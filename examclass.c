#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
   const int MAX = 100, MIN = 1;
   int nombreMystere = 0, nombre = 0 ;
	srand(time(NULL));
	nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
	do{
	printf("Quel est le nombre ?\n");
		scanf("%d", &nombre);
		if (nombre > nombreMystere){
			printf("C'est moins\n");
			}
		else if (nombre < nombreMystere){
			printf("C'est plus\n");
			}
		else if (nombre == nombreMystere){
			printf("Bravo, vous avez trouvé le nombre mystere !!!\n");}
} while (nombre != nombreMystere);
return 0;
}
