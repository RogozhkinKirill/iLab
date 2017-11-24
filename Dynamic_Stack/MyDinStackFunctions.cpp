#include <stdio.h>
#include <stdlib.h>
#include "StackFunctions.h"



int* MyRealloc(int *pArr , int OldLen , int NewLen)
{
	if(NewLen != 0)
	{
		if(pArr)
		{
			int *pNewArr = (int*)calloc(NewLen , sizeof(int));

			for(int i=0; i<OldLen; ++i)
			{
				pNewArr[i] = pArr[i];
			}

			return pNewArr;
		}
		else
		{
			return (int*)calloc(NewLen , sizeof(int));
		}
	}
	else
	{
		return (int*)calloc(NewLen , sizeof(int));
	}
}





int preOK(pStack stk)
{
	if(!stk)
	{
		return 1;
	}

	if(stk->number <= stk->lenth)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int postOK(pStack stk)
{
	if(stk->number <= stk->lenth)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}




void MyCreate(pStack stk)
{
	stk->data = NULL;
	stk->lenth = 0;
	stk->number = 0;

	return;
}

void MyDestroy(tpStack stk)
{
	free((**stk).data);
	printf("\n%p\n" , *stk);
}






void MyPush(pStack stk , int value)
{
	assert(stk);

	if(stk->number == 0)
	{
		stk->data = (int*)calloc(2 , sizeof(int));
		stk->lenth = 2;
	}

	if(stk->number >= stk->lenth)
	{
		int NewLength = 2 * stk->lenth + 1;
		stk->data = MyRealloc(stk->data , stk->lenth , NewLength);
		stk->lenth = NewLength;
	}

	stk->data[stk->number++] = value;

	return;
}

int MyPop(pStack stk)
{
	assert(stk);
	assert(stk->number >= 1);

	int ret = stk->data[stk->number - 1];

	--stk->number;

    return ret;
}

void MyClear(pStack stk)
{
	assert(stk);

	for(int i=0; i<(int)stk->lenth - 1; ++i)
	{
		stk->data[i] = 0;
	}

	stk->lenth = 0;
	stk->data = NULL;
	stk->number = 0;

	return;
}

int MySize(pStack stk)
{
	assert(stk);

	return stk->number;
}

int MyTop(pStack stk)
{
	assert(preOK(stk));

	return stk->data[stk->number - 1];
}

int MyEmpty(pStack stk)
{
	assert(preOK(stk));

	if(stk->number == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int IsFully(pStack stk)
{
	assert(preOK(stk));

	if(stk->number == stk->lenth - 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void MyDump(pStack stk)
{
	assert(stk);

	printf("\nAddress of stack: %p\n" , stk);
	printf("Stack contains\n");
	printf("Number members: %d\n" , stk->number);
	printf("Max number members: %d\n" , stk->lenth);
	printf("Pointer on data: %p\n" , stk->data);

	if(!stk->data)
	{
		printf("Stack at the zero condition\n\n");
		return;
	}

	int i = 0;
	for(i=0; i<(int)stk->number; ++i)
	{
		printf("Used    data[%d] = %d\n" , i , stk->data[i]);
	}
	printf("\n");
	for(i; i<(int)stk->lenth; ++i)
	{
		printf("Unused  data[%d] = %d\n" , i , stk->data[i]);
	}

	printf("\n\n");


	return;
}







