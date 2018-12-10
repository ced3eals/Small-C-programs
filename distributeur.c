#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define L 10


void AFFICHAGE_BOISSONS(){
printf("		╔═════════════════════╦═════╦═════╗\n");
printf("		║       BOISSON       ║PRIX ║CHOIX║\n");
printf("		╠═════════════════════╬═════╬═════╣\n");
printf("		║Café court           ║0.70€║  0  ║\n");
printf("		║Café long            ║0.90€║  1  ║\n");
printf("		║Café au lait         ║0.90€║  2  ║\n");
printf("		║Chocolat             ║0.50€║  3  ║\n");
printf("		║Lait                 ║0.50€║  4  ║\n");
printf("		║Thé au citon         ║0.60€║  5  ║\n");
printf("		║Café au M&N's        ║1.10€║  6  ║\n");
printf("		║Thé à la menthe      ║0.60€║  7  ║\n");
printf("		║Thé chinois (WUSHU)  ║1.00€║  8  ║\n");
printf("		║TheReal  tea	      ║9.90€║  9  ║\n");
printf("		╚═════════════════════╩═════╩═════╝\n");
}


void ACHAT_BOISSON(double MONNAIE_DISPO[L], double PRIX_BOISSONS[L], int choix, double Somme){
double arendre;
double eps = 0.001;
int i=0;
int TAB[L]={0};
arendre = Somme-PRIX_BOISSONS[choix];
printf("La monnaie à rendre est de : %.2f\n", arendre);

i=L-1;
while (arendre != 0 && i>=0)
{
while (arendre>=MONNAIE_DISPO[i] /*|| fabs((arendre) - MONNAIE_DISPO[i] < eps*/)
{
arendre-= MONNAIE_DISPO[i];
TAB[i]++;
}
i--;
}
for (i=L-1; i>=0; i--)
{
if (TAB[i]!=0)
{
printf("%d x %.2lf\n", TAB[i], MONNAIE_DISPO[i]);
}
}
}




int main(){
AFFICHAGE_BOISSONS();

double MONNAIE_DISPO[L]= {0.01,0.02,0.05,0.10,0.20,0.50,1.00,2.00,5.00,10.00};
double PRIX_BOISSONS[L] = {0.70,0.90,0.90,0.50,0.50,0.60,1.10,0.60,1.00,9.90};

int choix;
double montant;//, pièce;
	printf("Quel est votre choix (tapez '10' pour quitter) ?\n");
	scanf("%d", &choix);
	while(choix !=10){
		if(choix>=0 && choix<10)
		{
	printf("Donner votre montant : ");
		scanf("%lf", &montant);
		ACHAT_BOISSON(MONNAIE_DISPO, PRIX_BOISSONS, choix, montant);		
	printf("Votre boisson est prête !!!\n");}
printf("Quel est votre nouveau choix (tapez '10' pour quitter) ?\n");

scanf("%d", &choix);}	return 0;
}
