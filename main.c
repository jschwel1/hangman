#include <stdio.h>
#include "hangman.h"


int main(){
	char again = 1;
	char phrase[100];
	while (again){
		scanf("%s", phrase);
		play(phrase);
		scanf("%c", again);
		if (again == 'y' || again == 'Y') again = 1;
		else again = 0;

	}
		
}
