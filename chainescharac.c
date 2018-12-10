#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loadWord(char word[]) {
	if(scanf("%50s", word) !=1) { //%50 car nos chaines de charac ne dépassent jamais 50 charac '\0' compris, donc on PROTEGE NOTRE TABLEAU en évitant les débordements
		printf("Input error\n");
		exit(-1);
	}
}

void loadSentence(char sentence[]) {
	if(scanf("\n%50[^\n]", sentence) !=1) { //\n%[^\n] car on veut récup TOUTE la ligne
		printf("Input error\n");
		exit(-1);
	}
}

void toUpperCase(char sentence[]) {
	int i;		//i parcourt la chaine jusqu'a '\0'
	for(i=0;sentence[i]!='\0';i++) { 
		if(sentence[i]>='a'&&sentence[i]<='z')
		sentence[i]=sentence[i]-32; //car en ASCII entre a-A=32
	}
}

void toLowerCase(char sentence[]) {
	int i;
	for(i=0;sentence[i]!='\0';i++) {  //Car on veut que le '/0' marque l'arret de la lecture
		if(sentence[i]>='A'&&sentence[i]<='Z')
			sentence[i]=sentence[i]+32; //Car en ASCII entre A est 65 et a est 97
	}
}
int main () {
	printf("Please enter a word (50 char max):\n");
	char sentence[50];
	loadSentence(sentence);
	printf("You have entered the sentence:%s\n", loadSentence(sentence));
	toUpperCase(sentence);
	printf("Uppecase:%c\n", toUpperCase(sentence));
	return 0;
}






