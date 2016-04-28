#include "hangman.h"

/******* STRUCTURES ****************/

struct node_s {
	char l;
	node_s * next;
}

typedef node_s * node;


/************ Global Variables *******/
node wrong;
node right;
char * phrase;
char numWrong;


/*********** Functions ************/
void setUp(char * phraseInput){
	wrong = NULL;
	right = NULL;
	numWrong = 0;
	phrase = toLowerCase(phraseInput);
}

char * toLowerCase(char * c){
	char i;
	for (i = 0; i < strlen(c); i++){
		if (c[i] >= 'A' && c[i] <= 'Z') c[i] = c[i] + 'A'-'a';
	}
	
}

void addToList(node list, char c){
	node p = list;
	node new = (node)malloc(sizeof(node_s));

	if (p == NULL){
		p = new;
		new->next = NULL;
		new->l = c;
	}
	else {
		while (p->next != NULL) p=p->next;
		p->next = new;
		new->next = NULL;
		new->l = c;

	}
}

void guess(char c){
	for (i = 0; i < strlen(phrase); i++){
		char correct = 0;
		if (phrase[i] == correct){
			addToList(c);
			return;
		}
	}
	addToList(c);
	numWrong++;
	return;
}




void print(){
	node p;
	char i;
	
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
		if (phrase[i] > 'a' && phrase[i] < 'z') printf("%c",guessed?phrase[i]:'_');
	}
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
		printf("_______/_\______________  \n");
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
		printf("_______/_\______________  \n");
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
		printf("_______/_\______________  \n");
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
		printf("_______/_\______________  \n");
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
		printf("_______/_\______________  \n");
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
		printf("_______/_\______________  \n");
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
		printf("_______/_\______________  \n");
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
		printf("_______/_\______________  \n");
	}






}
