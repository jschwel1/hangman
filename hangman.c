#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hangman.h"


void play(char * phrase){
	char input;
	reset(phrase);
	while (getStatus() == -1){
		print();
		printf("Enter a lettter:\n");
		scanf("\n%c", &input);
		toLowerCase(&input);
		guess(input);
	}
}


char getStatus(){
	int i;
	char allThere = 1;
	if (numWrong >= MAX_WRONG) return 0;
	if (right == NULL) return -1;

	for (i = 0; i < strlen(phrase); i++){
		node p = right;
		while (p != NULL){
			if (p->l == phrase[i]) break;
			p = p->next;
		}
		if (p == NULL) return -1;
	}
	if (allThere == 1) return 0;
	return -1;
}

/*********** Functions ************/
void setUp(char * phraseInput){
	wrong = NULL;
	right = NULL;
	numWrong = 0;

	toLowerCase(phraseInput);
	phrase = phraseInput;
}

void reset(char * phraseInput){
	node p = right;
	while (p != NULL) {
		right = p->next;
		free(p);
		p = right;
	}
	p = wrong;
	while (p != NULL){
		wrong = p->next;
		free(p);
		p = wrong;
	}

	setUp(phraseInput);

}
void toLowerCase(char * c){
	int i;
	for (i = 0; i < strlen(c); i++){
		if (c[i] >= 'A' && c[i] <= 'Z') c[i] +=32;
	}
	
}

void addToRightList(char c){
	node p = right;
	node new = (node)malloc(sizeof(struct node_s));

	if (p == NULL){
		right = new;
		right->next = NULL;
		right->l = c;
	}
	else {
		while (p->next != NULL) p=p->next;
		p->next = new;
		new->next = NULL;
		new->l = c;

	}
}
void addToWrongList(char c){
	node p = wrong;
	node new = (node)malloc(sizeof(struct node_s));

	if (p == NULL){
		wrong = new;
		wrong->next = NULL;
		wrong->l = c;
	}
	else {
		while (p->next != NULL) p=p->next;
		p->next = new;
		new->next = NULL;
		new->l = c;

	}
}
void guess(char c){
	int i;
	node p;

	if (c < 'a' || c > 'z') return;
	// check that it wasn't already guessed	
	p = right;
	while (p != NULL) {
		if (p->l == c) return;
		p=p->next;
	}
	p = wrong;
	while (p != NULL) {
		if (p->l == c) return;
		p=p->next;
	}

	for (i = 0; i < strlen(phrase); i++){
		if (phrase[i] == c){
			addToRightList(c);
			return;
		}
	}
	addToWrongList(c);
	numWrong++;
	return;
}




void print(){
	node p;
	int i;
	
	printGallows(numWrong);

	// print wrong letters
	printf("Wrong Guesses: ");
	for (p = wrong; p != NULL; p = p->next) printf("%c ", p->l);
	printf("\n");

	for (i = 0; i < strlen(phrase); i++){
		char guessed = 0;
		for (p = right; p != NULL; p = p->next){
			if (p->l == phrase[i]) guessed = 1;
		}
		if (phrase[i] > 'a' && phrase[i] < 'z') printf("%c ",guessed?phrase[i]:'_');
		else printf("%c ",phrase[i]);
	}
	printf("\n\n");
}

void printGallows(char num){
	if (num == 0){
		printf("	__________________\n");
		printf("	|		 |\n");
		printf("	|		 |\n");	
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("_______/_\\______________  \n");
	}

	else if(num == 1){
		printf("	__________________\n");
		printf("	|		 |\n");
		printf("	|	      ___|___\n");	
		printf("	|	     |      |\n");
		printf("	|	     |	    | \n");
		printf("	|	     |______|  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("_______/_\\______________  \n");
	}
	else if(num == 2){
		printf("	__________________\n");
		printf("	|		 |\n");
		printf("	|	      ___|___\n");	
		printf("	|	     |      |\n");
		printf("	|	     |	    | \n");
		printf("	|	     |______|  \n");
		printf("	|		 |\n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("_______/_\\______________  \n");
	}
	else if(num == 3){
		printf("	__________________\n");
		printf("	|		 |\n");
		printf("	|	      ___|___\n");	
		printf("	|	     |      |\n");
		printf("	|	     |	    | \n");
		printf("	|	     |______|  \n");
		printf("	|		 |\n");
		printf("	|		/ \n");
		printf("	|	       /  \n");
		printf("	|	      /	  \n");
		printf("	|	     /	  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("_______/_\\______________  \n");
	}
	else if(num == 4){
		printf("	__________________\n");
		printf("	|		 |\n");
		printf("	|	      ___|___\n");	
		printf("	|	     |      |\n");
		printf("	|	     |	    | \n");
		printf("	|	     |______|  \n");
		printf("	|		 |\n");
		printf("	|		/ \\\n");
		printf("	|	       /   \\\n");
		printf("	|	      /	    \\\n");
		printf("	|	     /	     \\\n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("_______/_\\______________  \n");
	}
	else if(num == 5){
		printf("	__________________\n");
		printf("	|		 |\n");
		printf("	|	      ___|___\n");	
		printf("	|	     |      |\n");
		printf("	|	     |	    | \n");
		printf("	|	     |______|  \n");
		printf("	|		 |\n");
		printf("	|		/|\\\n");
		printf("	|	       / | \\\n");
		printf("	|	      /	 |  \\\n");
		printf("	|	     /	 |   \\\n");
		printf("	|		 |\n");
		printf("	|		 |\n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("_______/_\\______________  \n");
	}
	else if(num == 6){
		printf("	__________________\n");
		printf("	|		 |\n");
		printf("	|	      ___|___\n");	
		printf("	|	     |      |\n");
		printf("	|	     |	    | \n");
		printf("	|	     |______|  \n");
		printf("	|		 |\n");
		printf("	|		/|\\\n");
		printf("	|	       / | \\\n");
		printf("	|	      /	 |  \\\n");
		printf("	|	     /	 |   \\\n");
		printf("	|		 |\n");
		printf("	|		 |\n");
		printf("	|		/ \n");
		printf("	|	       /  \n");
		printf("	|	      /	  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("_______/_\\______________  \n");
	}
	else if(num == 7){
		printf("	__________________\n");
		printf("	|		 |\n");
		printf("	|	      ___|___\n");	
		printf("	|	     |      |\n");
		printf("	|	     |	    | \n");
		printf("	|	     |______|  \n");
		printf("	|		 |\n");
		printf("	|		/|\\\n");
		printf("	|	       / | \\\n");
		printf("	|	      /	 |  \\\n");
		printf("	|	     /	 |   \\\n");
		printf("	|		 |\n");
		printf("	|		 |\n");
		printf("	|		/ \\\n");
		printf("	|	       /   \\\n");
		printf("	|	      /	    \\\n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("_______/_\\______________  \n");
	}
	else if(num == 8){
		printf("	__________________\n");
		printf("	|		 |\n");
		printf("	|	      ___|___\n");	
		printf("	|	     | X  X |\n");
		printf("	|	     | ____ | \n");
		printf("	|	     |______|  \n");
		printf("	|		 |\n");
		printf("	|		/|\\\n");
		printf("	|	       / | \\\n");
		printf("	|	      /	 |  \\\n");
		printf("	|	     /	 |   \\\n");
		printf("	|		 |\n");
		printf("	|		 |\n");
		printf("	|		/ \\\n");
		printf("	|	       /   \\\n");
		printf("	|	      /	    \\\n");
		printf("	|		  \n");
		printf("	|  GAME OVER	  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("	|		  \n");
		printf("_______/_\\______________  \n");
	}







}
