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

//============show Array======
void showArray(int size, int iArray[]) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d " , iArray[i]);
	}
	printf("\n");
}


//======== SWAP============

void swap(int iArray[], int index1, int index2) {
	int a;
	a = iArray[index1];
	iArray[index1] = iArray[index2];
	iArray[index2] = a;
}

//=====Echange de valeur et tri============
void bubbleSort(int size, int iArray[]) {
	int i;
	int isSorted;
	//	int tmp;
	do {
		isSorted = 1;
		for (i = 0; i < (size - 1); i++) {
			if (iArray[i] > iArray[i+1]) {
				swap(iArray, i, i+1);
				isSorted = 0;
			}
		}
	} while (isSorted != 1);
}

int getMedian(int size, int iArray[]){
	//int i;
	int median;
	//for(i = 0;i < size;i++) {
bubbleSort(size, iArray);
	if(size%2 == 0){
		median = iArray[size/2];
	} 
	else { 
		median = iArray[size/2];	 
	}
	//}
	return median;
}

//==========INt main (void)=========
int main(void) {
	int a = 10;
	int tab[a];
	printf("Please enter %d integer:\n", a);
	loadArray(10, tab);
	showArray(10, tab);
	swap(tab, 10, 10);
	bubbleSort(10, tab);
	printf("The median of the array equals: %d", getMedian(10, tab));
	getMedian(10, tab);

	return 0;
}


