#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *ALLOCATION_TAB_DYN(int N){
int *mat;
mat = malloc(N*sizeof(int));
return mat;
}

void CHARGEMENT_TAB (int N, int * TAB){
int i=0;
for(i=0; i<N; i++){
        scanf("%d", TAB+i);

	}
}

void AFFICHAGE_TAB(int N, int *TAB){
int i;
for(i=0; i<N; i++){

printf("%d ", *(TAB+i));
}
printf("\n");}

//========================+Partie B=================

int ** ALLOCATION_MAT_DYN (int NB_L, int NB_C) 
{
int i;
int ** mat;
mat = malloc(NB_L*sizeof(int*));
for (i=0; i<NB_L; i++)
{
	mat[i] = malloc(NB_C*sizeof(int));
}
return mat;
}

void CHARGEMENT_MAT (int NB_L, int NB_C, int **MAT)
{
int i,j;
for(i=0; i<NB_L; i++)
	{ for(j=0; j<NB_C; j++)
{
        scanf("%d %d", *(MAT+i), *(MAT+j));

	}
}
}


void LIB_MAT(int NB_L, int ** MAT)
{
int i;
for (i=0; i<NB_L; i++)
{
	free(MAT[i]);
	MAT[i] = NULL;
}
free(MAT);
MAT = NULL;
}

int main(){
int N;
scanf("%d", &N);
int *TAB=ALLOCATION_TAB_DYN(N);
CHARGEMENT_TAB(N, TAB);
AFFICHAGE_TAB(N, TAB);
return 0;
}
