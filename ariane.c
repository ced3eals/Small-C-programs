#include<stdio.h>
#include<stdlib.h>

    int rocketTest(short oldAltitude, short newAltitude){
        printf("old altitude: %d, ",oldAltitude); 
        printf("new altitude: %d\n",newAltitude);
        if ( newAltitude >= oldAltitude){
            return 1;
        }
        else {
            printf("Falling!\n");
            return 0;
        }

    }

    void runLoop(int speed){
        int altitude;
        int i=0;
        for (altitude = 0;altitude <=300000;altitude = altitude + speed){
            printf("Actual altitude: %d, ",altitude);
            if(rocketTest(i, altitude) == 0){
                printf("Boom!\n");
                break; 
            }
    i = altitude;
        }
    }
        int main() {
            runLoop(1000);
            return 0;
        }


