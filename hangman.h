#ifndef HM_H
#define HM_H

#include "hangman.h"



#define MAX_WRONG 8

/******* STRUCTURES ****************/

struct node_s {
	char l;
	struct node_s* next;
};

typedef struct node_s* node;


/************ Global Variables *******/
node wrong;
node right;
char* phrase;
char numWrong;


/*********** Functions ************/
void play(char * phrase);

char getStatus();

void setUp(char * phraseInput);

void reset(char * phraseInput);

void toLowerCase(char * c);

void addToList(node list, char c);

void guess(char c);

void print();

void printGallows(char num);

#endif
