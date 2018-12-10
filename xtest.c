#include <stdio.h>
#include <stdlib.h>

void MENU()
{
        FILE*fichier;
        char c;
	fichier = fopen("menu.txt", "r+");
        if (fichier == NULL)
        {
	printf("Impossible d'ouvrir le fichier test.txt");
	//fichier = fopen("Menu_Texte.txt", "r+");
         //       printf("bien vu\n");    
        }
        else while(=!feof(fichier))
        {
         c = fichier;               }
}


int main()
{
MENU;
return 0;
}

