#include <stdio.h>

int main()
{    
    int i;
	int ligne;
	int espace;
int etoile;

    do {
        printf("Height in lines of the pyramid?\n");
        if (scanf("%d", &i) !=1){
            printf("Input error\n");
            return -1;}

    } while (i<1);

    //for (haut=0;haut<=choix;haut++){

    for (ligne =1;ligne <= i ;ligne ++){

        for (espace=0;espace<ligne-1;espace++){ printf(" ");
        }
        for (etoile=2*(i-ligne)+1;etoile>0;etoile--){ printf("*");
        }
        printf("\n");}

    return 0;

}
