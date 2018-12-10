#include <stdio.h>
#include <stdlib.h>
void loadArray(int size, int iArray[])
{	
	int choix;
	int n;
	for (n = 0; n < size ; n++){
		if(scanf("%d", &choix) !=1 )
		{
			printf("Input error\n");
			exit (-1);
		}	
		iArray[n] = choix;
	}	
}

void showArray(int size, int iArray[])
{
	int no; // espacement
	for (no = 0 ; no < size ; no++) 
	{
		printf("%d ",iArray[no]);
	}
	printf("\n");
}

double getMean(int size, int iArray[])
{
	int n;
	double moyenne= 0.0;
	for (n = 0; n < size; n++)
	{ 
		moyenne = moyenne + iArray[n];
	}
	return moyenne/size;
}

int main(void)
{
	int size = 10;
	int tab[size];
	printf("Please enter %d integers:\n", size);
	getMean(10, tab);
	loadArray(10, tab);
	showArray(10, tab);
	printf("The mean of the elements equals: %lf\n", getMean(10, tab));

	return 0;
}
