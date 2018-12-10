#include <stdio.h>
#include <stdlib.h>

void CHARGEMENT_MAT(int NB_L, int NB_C, int MAT[NB_L][NB_C])
{
int i,j,var;
for (i=0; i<NB_L; i++){
	for(j=0; j<NB_C; j++){
	scanf("%d", &var);
	MAT[i][j] = var;
	}}
}

void AFFICHAGE_MAT(int NB_L, int NB_C, int MAT[NB_L][NB_C])
{
int i,j;
for (i=0; i<NB_L; i++){
        for(j=0; j<NB_C; j++){
        printf("%d ",MAT[i][j] );
        }
	printf("\n");
	}
}

int MIN(int a, int b, int c)
{
int min;
min = a;
if(min >b){
	min = b;
	}
if(min >c){
	min = c;
	}
return min;
}

int PLUS_GRAND_SOUS_CARRE(int NB_L, int NB_C, int TAB[NB_L][NB_C])
{
int i,j,C;
int RES = 1;
int COUL[NB_L][NB_C];

for(j=0; j< NB_C;j++){
	COUL[0][j] = 1;
	}
for(i=0; i< NB_L; i++){
	COUL[i][0] = 1;
	}
for(i=0; i< NB_L; i++){
	for(j=0; j< NB_C; j++){
		if(TAB[i][j]==TAB[i-1][j] && TAB[i][j]==TAB[i-1][j-1] && TAB[i][j]==TAB[i][j-1]){
			C = (MIN(COUL[i-1][j], COUL[i-1][j-1], COUL[i][j-1]) + 1);
			COUL[i][j] = C;
			
			if(RES < C){
			RES = C;
			}
		} 
		else {
			COUL[i][j] = 1;
			}
			}
		}
return RES;
}

int PLUS_GRAND_SOUS_CARRE_2(int NB_L, int NB_C, int TAB[NB_L][NB_C])
{
int i,j,C,I,J;
int RES = 1;
int COUL[NB_L][NB_C];

for(j=0; j< NB_C;j++){
        COUL[0][j] = 1;
        }
for(i=0; i< NB_L; i++){
        COUL[i][0] = 1;
        }
for(i=0; i< NB_L; i++){
        for(j=0; j< NB_C; j++){
                if(TAB[i][j]==TAB[i-1][j] && TAB[i][j]==TAB[i-1][j-1] && TAB[i][j]==TAB[i][j-1]){
                        C = (MIN(COUL[i-1][j], COUL[i-1][j-1], COUL[i][j-1]) + 1);
                        COUL[i][j] = C;

                        if(RES < C){
                        RES = C;
                        I=i;
			J=j;
			}
                }
                else {
                        COUL[i][j] = 1;
                        }
                        }
                }
printf("Les coordonnées du coin inférieur droit d'un plus grand sous carré sont :(%d,%d)\n",I+1 ,J+1);
/*int nb=0;
for(i=0; i < NB_L; i++){
	for(j=0; j < NB_C; j++){
		if(COUL[i][j] == RES){
		nb = nb+1;
		}
	}
} */
return RES;
}

//void GENERATION_FIC();
//void NBRE_DE_CHAQ_SS_CAR(int NB_L, int NB_C, int COUL[NB_L][NB_C], int L_MAX);
int main()
{
int NB_L, NB_C;
scanf("%d %d", &NB_L, &NB_C);
int MAT[NB_L][NB_C];
CHARGEMENT_MAT(NB_L, NB_C, MAT);
AFFICHAGE_MAT(NB_L, NB_C, MAT);
PLUS_GRAND_SOUS_CARRE(NB_L, NB_C, MAT);
PLUS_GRAND_SOUS_CARRE_2(NB_L, NB_C, MAT);

return 0;
}
