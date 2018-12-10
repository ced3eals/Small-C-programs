#include <stdio.h>
#include <stdlib.h>

void initArray(int nbLin, int nbCol, int iArray[nbLin][nbCol]){
    int x,y,z;
    z=1;
    for(x=0;x<nbLin;x++){

        for (y=0;y<nbCol;y++){

            iArray[x][y] = z;
            z++;
        }
    }
}

void showArray(int nbLin, int nbCol, int iArray[nbLin][nbCol]){
    int a,b;
    for(a=0;a<nbLin;a++){

    	for(b=0;b<nbCol;b++){

            printf("%3d ",iArray[a][b]);
        }
        printf("\n");
    }
}

void loadArray(int nbLin, int nbCol, int iArray[nbLin][nbCol]){
    int x;
    int y;
    for(x=0;x<nbLin;x++){

        for(y=0;y<nbCol;y++){

            if(scanf("%d",&iArray[x][y]) !=1 ){

                printf("Input error\n");

                exit(-1);
            }
        }
}}

int getSumOfFourNeighbors(int nbLin, int nbCol, int iArray[nbLin][nbCol], int eltLin, int eltCol){    
    int add;
    add = 0;
	//case en haut
	if((eltLin-1)>=0){ 
    	add += iArray[eltLin-1][eltCol];
    }
	//bas
    	if((eltLin+1)<=(nbLin-1)){
    	add += iArray[eltLin+1][eltCol];
    }
	//left
    	if((eltCol-1)>=0){ 
    	add += iArray[eltLin][eltCol-1]; 
    }
	//right
    	if((eltCol+1)<=(nbCol-1)){ 
    	add += iArray[eltLin][eltCol+1];
    }
     return add;
}

int getSumOfEightNeighbors(int nbLin, int nbCol, int iArray[nbLin][nbCol], int eltLin, int eltCol) {
int add1;
add1 = 0;

    if((eltLin-1)>=0){ //s'il existe une case au dessus
    add1 += iArray[eltLin-1][eltCol];

    }

    if((eltLin+1)<=(nbLin-1)){// dessous
    add1 += iArray[eltLin+1][eltCol];
    }

    if((eltCol-1)>=0){ // gauche
    add1 += iArray[eltLin][eltCol-1]; 
    }
    

    if((eltCol+1)<=(nbCol-1)){ // droite
    add1 += iArray[eltLin][eltCol+1];
    }

    //diagonales en heut à gauche
    if((eltLin-1)>=0){ 
    	if((eltCol-1)>=0){
    add1 += iArray[eltLin-1][eltCol-1];
    	}
    }
    //diagonale en haut à droite
    if((eltLin-1)>=0){ 
    	if((eltCol+1)<=(nbCol-1)){
    add1 += iArray[eltLin-1][eltCol+1];
    	}
    }
    //diagonale en bas a gauche 
    if((eltLin+1)<=(nbLin-1)){
    	if((eltCol-1)>=0){
    	add1 += iArray[eltLin+1][eltCol-1];
    	}
    }
    //diagonale bas droite 
    if((eltLin+1)<=(nbLin-1)){
    	if((eltCol+1)<=(nbCol-1)){
    	add1 += iArray[eltLin+1][eltCol+1];
    	}
    }

    return add1;
}

int main () {

    int board[3][4];
    int i;
    int i1;
    initArray(3,4,board);
    printf("Please enter values:\n");
    loadArray(3,4,board);    
    i = getSumOfFourNeighbors(3,4,board,0,0);
    i1 = getSumOfEightNeighbors(3,4,board,0,0);
    printf("%d ",i);
    printf("%d",i1);
    showArray(3,4,board);
    return 0;
}
