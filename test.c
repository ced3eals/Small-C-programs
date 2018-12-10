#include <stdio.h>
#include <stdlib.h>

//#define PI 3,14141415
/*
   int main() {
   int var = 7;
   int tmp;
   int *p_var = &var; // (*p_var) is now identical to var
   Show 
   printf("var = %d, (*p_var) = %d\n", var, (*p_var));
   2) Read access 
   tmp = (*p_var) + 5;
   printf("var = %d, (*p_var) = %d, tmp = %d\n", var, (*p_var), tmp);
   3) Write access 
   (*p_var) = tmp;
   printf("var = %d, (*p_var) = %d, tmp = %d\n", var, (*p_var), tmp);
   return 0;
   }

   double getMean(int size, int iArray[]) 
   int iArray [size1][size];
   int i,col;
   size1=0;
   size1 = size;
   for(i=0;i <size1;i++){
   for(col=0;col< size; col++){
 */

/*void count(int min, int max) { // Prototype
  int var;
  for( var = min ; var < max ; var++ ) {
  printf(" %d\n", var);
  }
  }
 */

int main()
{
	FILE *fichier;
	fichier = fopen("/home/cedric/Menu_Texte.txt", "r+");

	if (fichier != NULL)
	{
		fichier = fopen("/home/cedric/Menu_Texte.txt", "r+");
		printf("bien vu\n");	
	}
	else
	{
		printf("Impossible d'ouvrir le fichier test.txt");
	}
	//fclose(fichier);
	return 0;
}



/*
   int swapp(int x, int y) {
   int tmp;
   x=tmp;
   tmp=y;
   y=tmp;

   return 0;





   int main() {
   double board[3][4] = { {5, 8, 4, 6 }, {1, 8 ,6 ,2 } };
   printf("La case (3,2) correspond à %lf\n", board[2][2]);
   board[0][0] = 2;
   board[2][2] = PI;
   return 0;
   }
 */



