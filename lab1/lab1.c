#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "test.h"
#include "vector.h"



const char *MSGS[] = {"0. Quit", "1. input vectors", "2. summarize vectors", "3. scalar multiplication of vectors", "4. testing", "5. output vectors"};
const int MSGS_SIZE = sizeof(MSGS) / sizeof(MSGS[0]);

int dialog(const char *msgs[], int n) {
	char *error = "";
		int choice;
		do {
			puts(error);
			error = "You're wrong. Try again!";
			for (int i = 0; i < n; ++i) {
				puts(msgs[i]);
			}
			puts("Make your choice: ");
			scanf("%d", &choice);
			scanf("%*c");
	    } while (choice < 0 || choice >= n);
	return choice;
}
int main() {
	vector ** intveclist = NULL;
	int lenintlist = 0;
	vector ** floatveclist = NULL;
	int lenfloatlist = 0;
	int c;
    do {
		c  = dialog(MSGS, MSGS_SIZE);
		switch(c) {
			case 0:
		    break;

			case 1:
			printf("Write 1 for int vector or 2 for float vector:\n");
			int flag = 0;
			scanf("%d", &flag);
			if(flag == 1) {
				printf("Enter dimention:");
				int dim;
				scanf("%d", &dim);
				printf("Enter vector:");
				int * data = readi(stdin, dim);
				vector * vector1 = newVectorIn(data, dim);
				intveclist = (vector**) realloc(intveclist, (lenintlist + 1)*sizeof(vector *));
				intveclist[lenintlist] = vector1;
				lenintlist++;
				printf("Number new (int)vector : %d", lenintlist);
			} else if( flag == 2) {
				printf("Enter dimention:");
				int dim;
				scanf("%d", &dim);
				printf("Enter vector:");
				float * data = readf(stdin, dim);
				vector * vector1 = newVectorFn(data, dim);
				floatveclist = (vector**) realloc(floatveclist, (lenfloatlist + 1)*sizeof(vector *));
				floatveclist[lenfloatlist] = vector1;
				lenfloatlist++;
				printf("Number new (float)vector : %d", lenfloatlist);
			}	else {
				printf("error ...\n");
			}
		    scanf("%*c");
		    break;

			case 2:
		    	{
		    		printf("Write 1 for int vector or 2 for float vector:\n");
					int flag = 0;
					scanf("%d", &flag);
					if(flag == 1) {
						int num1;
						int num2;
			    		printf("Enter num1 and num2 summ vector:");
			    		scanf("%d %d", &num1, &num2);
			    		if(num1 > lenintlist || num2 > lenintlist || num1 < 0 || num2 < 0) {
			    			printf("Error IndexOutOfRange...\n");
			    			scanf("%*c");
			    			break;
			    		}
						vector * vec = sumi(intveclist[num1 - 1], intveclist[num2 - 1]);
						if(!vec) {
							printf("Error dimention vector.\n");
							scanf("%*c");
							break;
						}
						intveclist = (vector**) realloc(intveclist, (lenintlist + 1)*sizeof(vector *));
						intveclist[lenintlist] = vec;
						lenintlist++;
						printf("Number new (int)vector : %d", lenintlist);

		    		} else if(flag == 2){
		    			int num1;
						int num2;
			    		printf("Enter num1 and num2 summ vector:");
			    		scanf("%d %d", &num1, &num2);
			    		if(num1 > lenfloatlist || num2 > lenfloatlist || num1 < 0 || num2 < 0) {
			    			printf("Error IndexOutOfRange...\n");
			    			scanf("%*c");
			    			break;
			    		}
						vector * vec = sumf(floatveclist[num1 - 1], floatveclist[num2 - 1]);
						if(!vec) {
							printf("Error dimention vector.\n");
							scanf("%*c");
							break;
						}
						floatveclist = (vector**) realloc(floatveclist, (lenfloatlist + 1)*sizeof(vector *));
						floatveclist[lenfloatlist] = vec;
						lenfloatlist++;
						printf("Number new (float)vector : %d", lenfloatlist);
		    		}
		    	}
		    scanf("%*c");
		    break;

		    case 3:
		    {
			    printf("Write 1 for int vector or 2 for float vector:\n");
				int flag = 0;
				scanf("%d", &flag);
				if(flag == 1) {
					int num1;
					int num2;
			    	printf("Enter num1 and num2 summ vector:");
			    	scanf("%d %d", &num1, &num2);
			    	if(num1 > lenintlist || num2 > lenintlist || num1 < 0 || num2 < 0) {
			    		printf("Error IndexOutOfRange...\n");
			    		scanf("%*c");
			    		break;
			    	}
					int res = multi(intveclist[num1 - 1], intveclist[num2 - 1]);
					printf("Scalar multiplication : %d", res);
				} else if( flag == 2) {
					int num1;
					int num2;
			    	printf("Enter num1 and num2 summ vector:");
			    	scanf("%d %d", &num1, &num2);
			    	if(num1 > lenfloatlist || num2 > lenfloatlist || num1 < 0 || num2 < 0) {
			    		printf("Error IndexOutOfRange...\n");
			    		scanf("%*c");
			    		break;
			    	}
					float res = multf(floatveclist[num1 - 1], floatveclist[num2 - 1]);
					printf("Scalar multiplication : %f", res);
				}	else {
					printf("error ...\n");
				}
		    }
		    scanf("%*c");
		    break;

		    case 4:{
		    	int res = test();
		    	if (res == 0) {
		    		printf("Congrat\n");
		    	}else {
		    		printf("Error %d", res);
		    	}
		    }
		    break;

		    case 5:
		    	{
		    		printf("(int)vector :\n");
		    		for(int i = 0; i < lenintlist; i++) {
		    			printf("{");
		    			for (int j = 0; j < intveclist[i]->len - 1; j++) {
		    				printf(" %d,", ((int *)intveclist[i]->head)[j]);
		    			}
		    			printf(" %d", ((int *)intveclist[i]->head)[intveclist[i]->len - 1]);
		    			printf(" }\n");
		    		}
		    		printf("(float)vector :\n");
		    		for(int i = 0; i < lenfloatlist; i++) {
		    			printf("{");
		    			for (int j = 0; j < floatveclist[i]->len - 1; j++) {
		    				printf(" %f,", ((float *)floatveclist[i]->head)[j]);
		    			}
		    			printf(" %f", ((float *)floatveclist[i]->head)[floatveclist[i]->len - 1]);
		    			printf(" }\n");
		    		}
		    	}
		    break;
		}
	} while (c != 0);
	for(int i = 0; i < lenintlist; i++){
		deleteshit(intveclist[i]);
	}
	free(intveclist);
	for(int i = 0; i < lenfloatlist; i++){
		deleteshit(floatveclist[i]);
	}
	free(floatveclist);
	return 0;
}
