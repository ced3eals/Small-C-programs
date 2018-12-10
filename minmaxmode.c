#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//======load Array===========
void loadArray(int size, int iArray[])
{
	int n, choix;

	for(n = 0;n < size; n++){
		if(scanf("%d", &choix) !=1)
		{
			printf("Input error\n");
			exit(-1);
		} iArray[n] = choix;
	}
}

//===show Array======
void showArray(int size, int iArray[]) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d " , iArray[i]);
	}
	printf("\n");
}

//==== Renvoyeur de Maximum====
int getMax(int size, int iArray[]) {
	int i;
	int max = iArray[0];
	for (i = 0; i < size; i++) {
		if (iArray[i] >= max) {
			max = iArray[i];
		}
	}
	return max;
}

//======= Renvoyeur de minimum==========
int getMin(int size, int iArray[]) {
	int n;
	int min = iArray[0];
	for(n = 0; n < size; n++) {
		if(iArray[n] < min) {
			min = iArray[n];
		}
	}
	return min;
}

//==============Index Max================
int getMaxIndex(int size, int iArray[]) {
	int i;
	int imax=0;
	for (i=1; i<size; ++i) {
		if (iArray[i]>iArray[imax])
			imax=i;
	}
	return imax;
}


//==============Index Min================
int getMinIndex(int size, int iArray[]) {
	int i;
	int imin=0;
	for (i=1; i < size; ++i) {
		if (iArray[i]<iArray[imin])
			imin=i;
	}
	return imin;
}

//==============MODD============

int getMode(int size, int iArray[]){
	int i; 
	int tab[21];
	for(i = 0; i < 21;i++) {
		tab[i] = 0;}
	for(i = 0;i < size; i++) {
		tab[iArray[i]]++;
	}
	return(getMaxIndex(21, tab));
}

//========Le MAIN(void)=========

int main(void) {
	int size = 10;
	int tab[size];
	printf("Please enter %d integers:\n", size);
	loadArray(10, tab);
	showArray(10, tab);
	getMax(10, tab);
	getMin(10, tab);
	getMaxIndex(10, tab);
	getMinIndex(10, tab);
	getMode(10, tab);
	printf("The max of the elements equals: %d\n", getMax(10, tab));
	printf("The min of the elements equals: %d\n", getMin(10,tab));
	printf("The (first) max of the elements is at index: %d\n", getMaxIndex(10, tab));
	printf("The (first) min of the elements is at index: %d\n", getMinIndex(10, tab));
	printf("The mode of the array equals: %d", getMode(10, tab));
	return 0;
}
