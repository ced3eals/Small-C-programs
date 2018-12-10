#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loadWord(char word[]) {
	if( scanf("%50s", word) !=1) {
		printf("Input error\n");
		exit(-1);}
}

void loadSentence( char sentence[]) {
	if(scanf("\n%50[^\n]", sentence) !=1) {
		printf("Input error\n");
		exit(-1);}
}

void toUpperCase(char sentence[]){
	//char c = sentence[0];
	int i= 0;
	for(i = 0; sentence[i] !='\0';i++) {
		if(sentence[i]>= 'a' && sentence[i]<= 'z') {
			sentence[i] -=32;
		}
	}}


void toLowerCase(char sentence[]) {
	int i = 0;
	for (i= 0;sentence[i] !='\0';i++) {
		if(sentence[i]>= 'A' && sentence[i]<= 'Z') {
			sentence[i] += 32;}
	}
}

void swap(char *x, char *y){
	char tmp;
	tmp = (*x);
	(*x) = (*y);
	(*y) = tmp;
}

void mirror(char sentence[]) {
	int len = strlen(sentence);
	int i;
	for(i = 0; i < (len /2); i++) {
		swap(&sentence[i], &sentence[len-1-i]);
	}
}
int main (void) {
	/*	char word[50];
	load
	printf("Please enter a word (50 char max):\n");
	  printf("You have entered the word: %s\n", loadSentence(word));
	toUpperCase(word);
	printf("Uppecase: %s\n", toUpperCase(word));
	
*/
	return 0;
}
