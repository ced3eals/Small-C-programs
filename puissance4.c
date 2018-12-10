#include <stdio.h>
#include <stdlib.h>

#define NBLIN 6
#define NBCOL 7



void initArray(int nbLin, int nbCol, int iArray[nbLin][nbCol], int value) {
    int col;
    int lin;
    for (lin =0; lin < nbLin ; lin++)
        for (col =0; col < nbCol ; col++)
            iArray[lin][col] =value;
}

void showArray(int nbLin, int nbCol, int iArray[nbLin][nbCol]) {
    int lin;
    int col;
    for (lin=0; lin < nbLin ; lin++) {
        for (col =0; col < nbCol ; col++) {
            printf("%3d ", iArray[lin][col]);
        }
        printf("\n");
    }

}

int getColumnForPawn(int nbLin, int nbCol, int board[nbLin][nbCol]) {
    int x = 0;
    int p = 0;
    do
    {
        printf("Enter the coordinate of the column you want to put your pawn on: ");

        if (scanf("%d", &p) != 1)
            exit(-1);

        if (board[x][p] != 0)
            printf("\nThis column is full so you can't add any more pawn, please re-try.\n");

        if (p < 0 || p >= nbCol)
            printf("Wrong number of column (outside of the board), please re-try.\n");

    } while (p < 0 || p >= nbCol || board[x][p] != 0);

    return p;

}

int placePawn(int nbLin, int nbCol, int board[nbLin][nbCol], int pawnCol, int pawn) {
    int l = (nbLin-1);
    for (l =(nbLin-1); l >= 0 ;l--) {
        if (board[l][pawnCol] == 0) {
            board[l][pawnCol] = pawn;
            break;
        }
    }
    return l;
}


int checkFourInLine(int nbLin, int nbCol, int board[nbLin][nbCol], int pawnLin, int pawnCol) {

    // On initialise les sommes à 1 pour considérer la [pawnLin][pawnCol] == seeked
    int Hor =1; // Somme horizontale
    int Ver =1; // Somme verticale
    int Diag1 =1; // Diagonale HG --> BD
    int Diag2 =1; // Diagonale BG --> HD
    int m =1;
    int search =board[pawnLin][pawnCol];

    // Verticale
    for (m =1; m < 4 ;m++) {

        if (pawnLin-m >= 0 && board[pawnLin-m][pawnCol] == search && board[pawnLin-m][pawnCol] == board[pawnLin-(m-1)][pawnCol]) // En haut
            Ver++;

        if (pawnLin+m < nbLin && board[pawnLin+m][pawnCol] == search && board[pawnLin+m][pawnCol] == board[pawnLin+(m-1)][pawnCol]) // En Bas
            Ver++;

    }

    // Horizontale
    for (m =1; m < 4 ;m++) {

        if (pawnCol-m >= 0 && board[pawnLin][pawnCol-m] == search && board[pawnLin][pawnCol-m] == board[pawnLin][pawnCol-(m-1)]) // A gauche
            Hor++;

        if (pawnCol+m < nbCol && board[pawnLin][pawnCol+m] == search && board[pawnLin][pawnCol+m] == board[pawnLin][pawnCol+(m-1)]) // A droite
            Hor++;

    }

    // Diagonale HG --> BD
    for (m =1; m < 4 ;m++) {

        if (pawnLin-m >= 0 && pawnCol-m >= 0 && board[pawnLin-m][pawnCol-m] == search && board[pawnLin-m][pawnCol-m] == board[pawnLin-(m-1)][pawnCol-(m-1)]) // Vers haut-gauche
            Diag1++;

        if (pawnLin+m < nbLin && pawnCol+m < nbCol && board[pawnLin+m][pawnCol+m] == search && board[pawnLin+m][pawnCol+m] == board[pawnLin+(m-1)][pawnCol+(m-1)]) // Vers bas-droit
            Diag1++;

    }

    // Diagonale BG --> HD
    for (m =1; m < 4 ;m++) {

        if (pawnLin+m < nbLin && pawnCol-m >= 0 && board[pawnLin+m][pawnCol-m] == search && board[pawnLin+m][pawnCol-m] == board[pawnLin+(m-1)][pawnCol-(m-1)]) // Vers bas-gauche
            Diag2++;

        if (pawnLin-m >= 0 && pawnCol+m < nbCol && board[pawnLin-m][pawnCol+m] == search && board[pawnLin-m][pawnCol+m] == board[pawnLin-(m-1)][pawnCol+(m-1)]) // Vers haut-droit
            Diag2++;

    }

    if (Hor >= 4 || Ver >= 4 || Diag1 >= 4 || Diag2 >= 4) // Si une des sommes est a 4 return 1
        return 1;

    return 0;

}



void clearScreen() {
    printf("%c[%d;%dH", 0x1B, 1, 1);

    printf("%c[2J", 0x1B);

}


void showBoard(int nbLin, int nbCol, int board[nbLin][nbCol]) {

    int col =0;
    int lin =0;

    clearScreen();

    for (lin =0;   lin < nbLin ; lin++) {

        for (col =0; col < nbCol ; col++) {

            printf(" |");

            if (board[lin][col] == 0)
                printf("  ");
            if (board[lin][col] == 1) 
                printf("\033[31;01m o\033[00m");


            if (board[lin][col] == 2) 
                printf("\033[36;01m o\033[00m");            
        }

        printf(" |\n");

    }

    printf(" ");

    for (lin =0; lin < nbCol ;lin++)
        printf(" ---");
    printf("\n");
    for (lin =0; lin < nbCol ;lin++)
        printf(" %3d", lin);
    printf("\n");
}

int runAStep(int nbLin, int nbCol, int board[nbLin][nbCol], int numPlayer) {
    int c;
    int flag =0;
    int l;
    printf("\n#### Player %d, your turn ####\n", numPlayer);
    c = getColumnForPawn(nbLin, nbCol, board);
    l = placePawn(nbLin, nbCol, board, c, numPlayer);
    flag = checkFourInLine(nbLin, nbCol, board, l, c);

    if (flag == 1)
        return 1;

    return 0;

}

int runGame(int nbLin, int nbCol, int board[nbLin][nbCol]) {
    int vainqueur = 0;
    int victoire = 0;
    int nbcp = (nbLin * nbCol);
    int numPlayer = 1;
    int flag = 1;

    do {
        showBoard(nbLin, nbCol, board);
        victoire = runAStep(nbLin, nbCol, board, numPlayer);
        if (victoire == 1){
            vainqueur = numPlayer;
            flag=0;
        showBoard(nbLin, nbCol, board);

        }
        nbcp--;
    
        if (nbcp == 0)  {
        flag = 0;    
    vainqueur = 0;
showBoard(nbLin, nbCol, board);

        }

        numPlayer =((numPlayer+1)%2);

        if (numPlayer == 0) {
            numPlayer = 2;

        
    }
}
    while(flag == 1);
    return vainqueur;
}

void endOfGame(int numWinner){

    printf("\n\n#### THE GAME IS OVER ####\n");

    if (numWinner == 0)
        printf("\nIt's a draw!\n");
    else
        printf("\nAnd the winner is Player %d!\n", numWinner);

}


int main (){

    int nbLin =NBLIN;

    int nbCol =NBCOL;

    int board[nbLin][nbCol];

    int vainqueur;

    initArray(nbLin, nbCol, board, 0);
    vainqueur =runGame(nbLin, nbCol, board);
    endOfGame(vainqueur);

    return 0;

}
