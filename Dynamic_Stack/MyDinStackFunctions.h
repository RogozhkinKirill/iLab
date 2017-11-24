#ifndef _MyDinStackFunctions_
#define _MyDinStackFunctions_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



#define MyStkDump(x) printf("\n\n\%s \nLine:%d\n%s\n" , \
							__PRETTY_FUNCTION__ , \
							__LINE__ , __FILE__);\
							MyDump(x)

#define Stack(stk) Stack stk;\
					MyCreate(&stk);\
					pStack p##stk = &stk


typedef struct MyStack
{
	int *data;
	unsigned int number;
	unsigned int lenth;
} Stack , *pStack , **tpStack;

int preOK(pStack);
int postOK(pStack);

int* MyRealloc(int* , int , int);

void MyCreate(pStack);
void MyDestroy(tpStack);

void MyPush(pStack , int);
int MyPop(pStack);
void MyClear(pStack);
int MySize(pStack);
int MyTop(pStack);

int MyEmpty(pStack);
int IsFully(pStack);

void MyDump(pStack);



#endif // MyDinFunctions

