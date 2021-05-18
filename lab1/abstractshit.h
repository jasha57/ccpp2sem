#ifndef ABSTRSHIT
#define ABSTRSHIT

#include <stdlib.h>
#include <string.h>

typedef struct absh {
	void * head;
	int len;
	int size;
} absh;

absh * makeshit(int);
int add(absh *, void *);
void deleteshit(absh *);


#endif