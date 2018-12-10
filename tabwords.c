#include <stdio.h>
int main()
{ char cha = 'A';
  char chas = 'Z';
  char oui;
 //char words[7] = {'b','o','n','j','o','u','r','\0'};/  <<VALGRIND à CHERCHER>>
printf("%c vaut en ASCII %d \n", cha, cha);
printf("tu veux savoir qqchz d'autres? y ou n\n");
scanf("%c", &oui);
if(oui=='y'){
printf("%c - 15 + %c vaut en ACSII %d\n", cha, chas, cha - 15 + chas);
} else { printf("Bah Je niques Ta Mère alors!! Sale Bouffon va!\n");}
return 0;
}
