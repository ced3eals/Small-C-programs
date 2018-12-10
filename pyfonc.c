#include <stdio.h>
#include <stdlib.h>

int getIntegerGreaterThan(int threshold) {
    int i;
    do{
        printf("Please enter a value greater than %d:\n", threshold);
        if(scanf("%d", &i) !=1){ 
            printf("Input error\n");
            exit(-1);}
    } while(i<=threshold);
    return i;
}
void printStar(int nbStar) {
    int s;
    for(s=0;s<nbStar;s++){
        printf("*");}
}

void printSpace(int nbSpace) {
    int spa;
    for(spa =1 ;spa <=nbSpace;spa++){
        printf(" ");
    }}

int main()
{
    printf("Height in lines of the pyramid?\n");

    int i = getIntegerGreaterThan(0), ko, spa = 1, s2=0, stars=2*(i - spa )+1;


    for (ko =0;ko<i;ko++){
        stars--;
        stars=2*(i - s2)-1;    
        printSpace(s2);
        printStar(stars);
        printf("\n");
        s2++;

    }
    return 0;
}
