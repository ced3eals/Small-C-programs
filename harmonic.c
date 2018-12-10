#include <stdio.h>

int main() 
{
    int choix;
    int prog;
    double result;
    do {
        printf("Rank of the Harmonic serie?\n");
        if (scanf("%d", &choix) !=1){
        printf("Input error\n");
            return -1;}
    } while(choix<1);
    
    result=1.;

    for(p=2;p<=choix;p++){
        printf(" + 1/%d", p);
        result = result + 1./p;
    }
    printf(" = %lf\n", result);

    return 0;
}
