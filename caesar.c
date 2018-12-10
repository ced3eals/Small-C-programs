#include <stdio.h>
#include <stdlib.h>

int getIntegerGreaterThan(int threshold){
	int i;
	do{
		printf("Please enter a value greater than %d:\n", threshold);
		if(scanf("%d", &i) !=1){
			printf("Input error\n");
			exit (-1);}
	}	while (i<=threshold);
	return i;
}

char getACharacter()
{
	char lopez;
	printf("Please enter a character\n");	
	do{
		if(scanf("%c", &lopez) !=1)
		{	printf("Input error\n");
			exit (-1);}
	} while (lopez =='\n');
	return lopez;}

void loadCharArray(int size, char charArray[]) {
	int c;
	for (c=0; c < size;c++) {
		charArray[c] = getACharacter();

	}	
}
char caesarCypher (char character) {
	char chare = (character+3)%128;
	return chare;
}
void caesarCypherArray(int size,char charArray[])
{
	int cases;
	for(cases=0; cases<size; cases++){
		charArray[cases]=caesarCypher(charArray[cases]);
	}
}
char caesarDecypher(char character){
	char charde = (character+125)%128;
	return charde;
}
void caesarDecypherArray (int size, char charArray[]){
	int c;
	for (c=0; c<size; c++){
		charArray[c]=caesarDecypher(charArray[c]); 
	}
}
void showCharArray(int size, char charArray[]){
	int c;
	for (c=0; c<size; c++){
		printf("%c", charArray[c]);}
	printf("\n");
}

int main()
{
	printf("Size of the array?\n");
	int i = getIntegerGreaterThan(0);
	char tableau[i];
	loadCharArray(i, tableau);
	printf("Original: ");
	showCharArray(i, tableau);
	caesarCypherArray(i, tableau);
	printf("Caesar Cypher: ");
	showCharArray(i, tableau);
	caesarDecypherArray(i, tableau);
	printf("Caesar Decypher: ");
	showCharArray(i, tableau);		

	return 0;
}
