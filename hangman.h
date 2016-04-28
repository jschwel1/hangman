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
void setUp(char * phraseInput);

char * toLowerCase(char * c);

void addToList(node list, char c);

void guess(char c);

void print();

void printGallows(char num);

