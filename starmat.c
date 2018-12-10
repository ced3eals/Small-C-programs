#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
	int lopez;
	int c;
	int i;
    do {
        printf("Please, enter a number of lines\n");
        if(scanf("%d", &choice) !=1){
            printf("Input error\n");
            return -1;}
    } while(choice<=0);
    
    for (lopez=1;lopez<=choice;lopez++){
        for (c=1;c<=60;c++){
        i=rand()%2;
        if(i==0){
            printf("*");
        } else {
        printf(" ");}}
    printf("\n");}

    return 0;
}
