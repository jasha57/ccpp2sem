#include "abstractshit.h"

absh * makeshit(int sizem) {
	if(sizem == 0) {
		return NULL;
	}
	absh * res = (absh *)calloc(1, sizeof (absh));
	res->size = sizem;
	return res;
}

int add(absh * s, void * data) {
	int len = s->len;
	int size = s->size;
	s->head = realloc(s->head, (len + 1) * size);
	memcpy(s->head + len * size, data, size);
	(s->len)++;
	return 0;
}

void deleteshit(absh * s) {
	if (s->head) {
		free(s->head);
	}
	free(s);
}