#ifndef VECTOR_
#define VECTOR_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "abstractshit.h"

typedef absh vector;

vector * newVectorIn(int *, int);
vector * newVectorFn(float *, int);
vector * sumf (vector *, vector *);
float multf (vector *, vector *);
vector * sumi (vector *, vector *);
int multi (vector *, vector *);


#endif 