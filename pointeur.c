#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getMinMax(int size, int iArray[], int *p_min, int *p_max) {
int n;
        (*p_min) = iArray[0];
	(*p_max) = iArray[0];
        for(n = 0; n < size; n++) {
                if(iArray[n] < (*p_min) ) {
                        *p_min = iArray[n];
			iArray[n] = (*p_min);
                }
		 else if(iArray[n] >= (*p_max) ) {
                        *p_max = iArray[n];
			iArray[n] = (*p_max);
                }
        }
}

void getMinMaxIndex(int size, int iArray[], int *p_minIndex, int *p_maxIndex) {
        int i;
	int imax = iArray[0];
	int imin = iArray[0];
	(*p_minIndex) = 0;
	(*p_maxIndex) = 0;
        	for (i=1; i<size; ++i) {
                	if (iArray[i] > imax) {
                        	(*p_maxIndex) = i;
				imax = iArray[i];
				}
			else if (iArray[i]< imin) {
                        	(*p_minIndex) = i;
				imin = iArray[i];
	        }
	}
}

int getFirstIndexOfValue(int size, int iArray[], int value, int* p_index) {

        int i;
        for (i=1; i<size; ++i) {
                if (value == iArray[i]) {
                        (*p_index)=i;
        return 1;}
	}
        return 0;

}


int main (void) {




return 0;
}
