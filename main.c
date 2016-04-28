#include <stdio.h>
#include "hangman.h"


int main(){
	char again = 1;
	char phrase[100];
	int i=0;

	while (again){
		printf("Enter a word or phrase:\n");
		do {
			scanf("%c", &phrase[i]);
			i++;
		}while(phrase[i-1] != '\n');
		phrase[i] = 0x00;

		printf("You entered: %s\n", phrase);
		play(phrase);
		printf("Play again (y/n)");
		scanf("\n%c", &again);
		toLowerCase(&again);
		if (again == 'y' || again == 'Y') again = 1;
		else again = 0;

	}

	return 0;	
}
