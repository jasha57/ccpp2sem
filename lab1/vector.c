#include "vector.h"

vector * newVectorIn(int * data, int n) {
	vector * vector1 = makeshit(sizeof(int));
	for (int i = 0; i < n; i++) {
		add(vector1, data + i);
	}
	return vector1;
}

vector * newVectorFn(float * data, int n) {
	vector * vector1 = makeshit(sizeof(float));
	for (int i = 0; i < n; i++) {
		add(vector1, data + i);
	}
	return vector1;
}

vector * sumf(vector * a, vector * b) {
	if (a->len != b->len){
		fprintf(stderr ,"meh different length fok u\n");
		return NULL;
	}
	vector * res = makeshit(sizeof(float));
	for (int i = 0; i < a->len; i++) {
		float sum = ((float*)a->head)[i] + ((float*)b->head)[i];
		add(res, &(sum));
	}
	return res;
}

float multf(vector * a, vector * b) {
	if (a->len != b->len){
		fprintf(stderr ,"meh different length fok u\n");
		return 0.0f;
	}
	float res = 0;
	for (int i = 0; i < a->len; i++) {
		float mult = ((float*)a->head)[i] * ((float*)b->head)[i];
		res += mult;
	}
	return res;
}

vector * sumi(vector * a, vector * b) {
	if (a->len != b->len){
		fprintf(stderr ,"meh different length fok u\n");
		return NULL;
	}
	vector * res = makeshit(sizeof(int));
	for (int i = 0; i < a->len; i++) {
		int sum = ((int*)a->head)[i] + ((int*)b->head)[i];
		add(res, &(sum));
	}
	return res;
}

int multi(vector * a, vector * b) {
	if (a->len != b->len){
		fprintf(stderr ,"meh different length fok u\n");
		return 0;
	}
	int res = 0;
	for (int i = 0; i < a->len; i++) {
		int mult = ((int*)a->head)[i] * ((int*)b->head)[i];
		res += mult;
	}
	return res;
}