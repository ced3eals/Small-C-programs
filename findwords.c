#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


/*
 * Constantes symboliques.
 *
 * La constante NB_WORD correspond au nombre de mots dans le dictionnaire
 * definit par la constante DICTIONARY. Si le nombre de mot change dans le
 * dictionnaire, il faut également changer la valeur de la constante NB_WORD,
 * elle sert pour le tirage au sort d'un mot dans le fichier !
 */
#define NB_TEST         10
#define NB_WORD         331612
#define MAX_LEN         50
#define INVISIBLE_CHAR  '-'
#define DICTIONARY      "dico.txt"


/*
 * Structure contenant le mot courant et les informations de la partie
 * en cours.
 */
typedef struct
{
   /* Nombre de lettre dans le mot à trouver. */
   size_t nb_char;
   
   /* Compteur. S'il arrive a zero, toutes les lettres sont trouvees. */
   size_t count;

   /* Lettres trouvees. Le restant des lettres non trouvees sont representees
      dans cette chaine par la constante INVISIBLE_CHAR. */
   char * word;
   
   /* Mot complet a trouver. */
   char * word_to_find;
}
word_t;


/*
 * Prototypes des fonctions.
 */
int      get_word_pos   (void);
char *   get_word       (int word_pos, const char * dictionary);
void     game           (word_t * self);
void     clean          (char * buf, FILE * stream);
void     get_char       (char * buf);
void     destroy_word   (word_t ** self);
word_t * make_word      (const char * word);
int      find_char      (word_t * self, const char c);


/*
 * Point d'entree du programme.
 */
int main (void)
{
   char * word = get_word (get_word_pos (), DICTIONARY);


   if (word != NULL)
   {
      word_t * my_word = make_word (word);
      
      if (my_word != NULL)
      {
         game (my_word);
         destroy_word (& my_word);
      }
      
      free (word);
   }


   return EXIT_SUCCESS;
}


/*
 * Tire un nombre au sort entre 0 et NB_WORD - 1.
 */
int get_word_pos (void)
{
   srand (time (NULL));
   return (int)(rand() / (double)RAND_MAX * (NB_WORD - 1));
}


/*
 * Recherche du mot d'apres le nombre tire au sort par get_word_pos.
 */
char * get_word (int word_pos, const char * dictionary)
{
   char * word = NULL;
   
   
   if (dictionary != NULL)
   {
      FILE * fp = fopen (dictionary, "r");
      
      if (fp != NULL)
      {
         int count = 0;
         char buf [MAX_LEN];
         
         
         while (fgets (buf, sizeof buf, fp) != NULL)
         {
            /*
             * Si on a atteint la bonne ligne, on copie le mot.
             */
            if (count == word_pos)
            {
               size_t size = 0;
               
               /*
                * On nettoie la chaine en enlevant le saut de ligne et
                * on copie la chaine sur un espace alloue dynamiquement
                * pour la renvoyer par la fonction.
                */
               clean (buf, NULL);
               size = strlen (buf) + 1;
               word = malloc (size);
               
               if (word != NULL)
               {
                  strcpy (word, buf);
               }
               else
               {
                  /* Erreur: Allocation impossible. */
                  free (word);
                  word = NULL;
                  
                  fprintf (
                     stderr,
                     "--> Erreur: Impossible d'allouer l'espace pour le mot !"
                  );
               }
               
               break;
            }
            
            count++;
         }
         
         
         fclose (fp);
      }
      else
      {
         fprintf (
            stderr,
            "--> Erreur: Impossible d'ouvrir le fichier %s !\n",
            dictionary
         );
      }
   }
   
   
   return word;
}


/*
 * Fonction gerant une partie.
 */
void game (word_t * self)
{
   char buf [5];
   int nb_test = 0;
   
   
   if (self != NULL)
   {
      printf ("=== DEBUT DE LA PARTIE ===\n\n");
      printf ("Le mot a trouver possede %d lettres et vous avez %d essais !\n%s\n\n", self->nb_char, NB_TEST, self->word);
      fflush (stdout);
   
      
      /*
       * Boucle principale du jeu.
       */
      do
      {
         /* Recupere la lettre tapee par le joueur. */
         get_char (buf);
         
         /* Recherche de la lettre dans le mot. */
         if (find_char (self, buf[0]))
         {
            /* Si toutes les lettres ont ete trouvees, on sort de la boucle. */
            if (self->count == 0)
            {
               break;
            }
         }
         else
         {
            /* La lettre courante n'est pas dans le mot. On deduit un essai. */
            nb_test++;
            printf ("Plus que %d essais !\n", NB_TEST - nb_test);
            fflush (stdout);
         }
         
         printf ("%s\n\n", self->word);
         fflush (stdout);
      }
      while (nb_test < NB_TEST);
      
      
      /* Si le nombre d'essais a ete atteint, la partie est perdu. */
      if (nb_test == NB_TEST)
      {
         printf (
            ">> Vous avez perdu :(\nLe mot a trouver etait: %s\n\n",
            self->word_to_find
         );
         fflush (stdout);
      }
      else
      {
         printf (">> Vous avez gagne !!\n");
         printf ("%s\n\n", self->word);
         fflush (stdout);
      }
      
      
      printf ("=== FIN DE LA PARTIE ===\n\n");
      fflush (stdout);
   }
}


/*
 * Fonction de nettoyage des saisie utilisateur et du buffer clavier.
 */
void clean (char * buf, FILE * stream)
{
   if (buf != NULL)
   {
      char * p = strchr (buf, '\n');

      if (p == NULL && stream != NULL)
      {
         int c;
         
         while ((c = fgetc (stream)) != '\n' && c != EOF)
         {
         }
      }
      else
      {
         *p = 0;
      }
   }
}


/*
 * Demande au joueur de taper une lettre. Si la lettre est tapee en minuscule,
 * elle est changee automatiquement en majuscule. Les caracteres accentues
 * ne sont pas pris en compte.
 */
void get_char (char * buf)
{
   printf ("Quelle lettre proposez-vous ? ");
   fflush (stdout);
   
   if (fgets (buf, sizeof buf, stdin) != NULL)
   {
      /* Change la casse de la lettre. */
      buf[0] = toupper (buf[0]);
      
      /* Nettoye le buffer temporaire et le buffer clavier. */
      clean (buf, stdin);
   }
}


/*
 * Fonction de liberation d'un obiet de type word_t.
 */
void destroy_word (word_t ** self)
{
   if (self != NULL && *self != NULL)
   {
      if ((* self)->word_to_find != NULL)
         free ((* self)->word_to_find);

      if ((* self)->word != NULL)
         free ((* self)->word);

      free (* self);
      *self = NULL;
   }
}


/*
 * Fonction de creation et d'initialisation d'un objet de type word_t.
 * Ce type permet de stocker le mot a retrouver et les diverses informations
 * de la partie en cours.
 */
word_t * make_word (const char * word)
{
   word_t * self = NULL;


   if (word != NULL)
   {
      self = malloc (sizeof (* self));

      if (self != NULL)
      {
         self->nb_char        = strlen (word);
         self->count          = self->nb_char;
         self->word           = malloc (self->nb_char + 1);
         self->word_to_find   = malloc (self->nb_char + 1);

         if (self->word != NULL && self->word_to_find != NULL)
         {
            strcpy      (self->word_to_find, word);
            memset      (self->word, INVISIBLE_CHAR, self->nb_char);
            self->word  [self->nb_char] = 0;
         }
         else
         {
            /* Erreur: on libere toutes les ressources. */
            destroy_word (& self);
         }
      }
   }


   return self;
}


/*
 * Fonction de recherche de la lettre courante dans le mot.
 */
int find_char (word_t * self, const char c)
{
   int ret = 0;


   if (self != NULL)
   {
      size_t i = 0;

      for (i = 0; i < self->nb_char; i++)
      {
         /* Si la lettre courante que l'utilisateur a tapee correspond au
            caractere courant du mot a retrouver et qu'il n'a pas encore ete
            donne avant, on remplace le caractere de masquage de la chaine
            affichee a l'ecran par celui propose par le joueur. */
         if (self->word_to_find[i] == c && self->word[i] == INVISIBLE_CHAR)
         {
            self->word[i] = self->word_to_find[i];
            self->count--;

            ret = 1;
         }
      }
   }


   return ret;
}

