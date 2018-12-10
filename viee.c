#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#define NBLIN 15
#define NBCOL 50
#define NBSTEPS 5

void clearScreen() {

	printf("%c[2J", 0x1B);

	printf("%c[%d;%dH", 0x1B, 1, 1);
}


void initArray(int nbLin, int nbCol ,int iArray[nbLin][nbCol], int value) {
	int l,c; //l=ligne; c=colone
	for(l=0; l<nbLin; l++)
	{
		for(c=0; c<nbCol; c++)
		{
			iArray[l][c]= value;
		}
	}
}


void showBoard (int nbLin, int nbCol, int board[nbLin][nbCol]) {
	int l,c;
	clearScreen();
	sleep(1);	
	for(l=0; l<nbLin; l++) {
		for(c=0; c<nbCol; c++) {
			if (board[l][c] == 1) {
				printf("o");
			}
			else {
				printf(" "); 
			}
		}
		printf("\n");
	}
}


void seedRandomCells(int nbLin, int nbCol, int board[nbLin][nbCol]) {
	int l,c;
	for(l = 0; l<nbLin; l++) {
		for(c =0;c<nbCol; c++) {
			if(rand()%5 == 0){
				board[l][c]=1;
			}
		}
	}
}


int getNumberOfNeighboursAlive(int nbLin, int nbCol, int board[nbLin][nbCol], int cellLin, int cellCol) {
	int var1, var2;
	int result = 0;
	for(var1 = cellLin - 1; var1 <= cellLin + 1; var1++) {
		for(var2 = cellCol - 1; var2 <= cellCol + 1; var2++) {
			if (var1 < 0 || var1 >= nbLin || var2 < 0 || var2 >=nbCol) {
				continue;
			}
			if (board[var1][var2] !=0) {
				result++;
			}
		}
	}
	if (board[cellLin][cellCol] != 0) {
		result--;
	}
	return result;
}


int isCellDeadOrAlive(int nbLin, int nbCol, int board[nbLin][nbCol], int cellLin, int cellCol) {
	int i;
	i = board[cellLin][cellCol];
	int neighbours = getNumberOfNeighboursAlive(nbLin, nbCol, board, cellLin, cellCol);
	if (i == 0) {
		if(neighbours == 3) {
			return 1;
		}
	}
	else if (neighbours == 2 || neighbours == 3) { 
			return 1;
			}
		
	return 0;	
}

void copyArray(int nbLin, int nbCol, int array1[nbLin][nbCol], int array2[nbLin][nbCol]) {
	int lin,col;
	for(lin = 0;lin < nbLin; lin++) {
		for(col = 0; col < nbCol; col++) {
			array2[lin][col] = array1[lin][col];
		}
	}
}


int getNumberOfLivingCells(int nbLin, int nbCol, int board[nbLin][nbCol]) {
	int sum = 0, x, y;
	for(x= 0 ; x <nbLin; x++){
		for(y = 0; y <nbCol; y++){
			if (board[x][y]!=0){
				sum++;
			}
		}	
	}
	return sum;
}


void  runAStep(int nbLin, int nbCol, int board[nbLin][nbCol]) {
	int boardTemp[nbLin][nbCol];
	int x=0;
	int y=0;
	for(x = 0; x < nbLin; x++){
		for(y = 0; y < nbCol; y++){
		boardTemp[x][y] = isCellDeadOrAlive(nbLin, nbCol, board, x, y);}
}
		copyArray(nbLin, nbCol, boardTemp, board);	
}


int runGame(int nbLin, int nbCol, int board[nbLin][nbCol]){ 
	int a;
	int cedric = 0;
	int ced;
	seedRandomCells(nbLin,nbCol,board);
	//showArray(nbLin,nbCol,board);
	showBoard(nbLin,nbCol,board);

	for(a = 0; a <NBSTEPS; a++){
		sleep(1);
		cedric++;
		runAStep(nbLin,nbCol,board);
		showBoard(nbLin,nbCol,board);
		ced = getNumberOfLivingCells(nbLin,nbCol,board);
		printf("\n\nIl y a %d cellules vivantes.\n", ced);
	}
	return 0;
}


int main() {
	//srand( time (NULL) );
	int board[NBLIN][NBCOL]={{0}};
	initArray(NBLIN, NBCOL, board, 0);
	runGame(NBLIN, NBCOL, board);
	return 0;
}

