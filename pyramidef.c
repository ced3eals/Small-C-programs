#include <stdio.h>
#include <stdlib.h>

int getIntegerGreaterThan(int threshold)
{
    int choix;
    do{
        printf("Please enter a value greater than %d:\n", threshold);
        if(scanf("%d", &choix) !=1){ 
            printf("Input error\n");
            exit(-1);}
    } while(choix<=threshold);
    return choix;
}
void printStar(int nbStar)
{
    int star;
    for(star=0;star<nbStar;star++){
        printf("*");}
}

void printSpace(int nbSpace)
{
    int space;
    for(space=1;space<=nbSpace;space++){
        printf(" ");
    }}

int main()
{
    printf("Height in lines of the pyramid?\n");

    int moi=getIntegerGreaterThan(0), toi, space=1, spaces2=0, stars=2*(moi-space)+1;


    for (toi=0;toi<moi;toi++){
        stars--;
        stars=2*(moi - spaces2)-1;    
        printSpace(spaces2);
        printStar(stars);
        printf("\n");
        spaces2++;

    }
    return 0;
}
