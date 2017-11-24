#include "MyDinStackFunctions.h"
#include "StackMath.h"
#include <math.h>

void MyAdd(pStack stk)
{
	int a = MyPop(stk);
	int b = MyPop(stk);
	MyPush (stk, a + b);

	return;
}

void MySub(pStack stk)
{
	int a = MyPop(stk);
	int b = MyPop(stk);
	MyPush (stk, b - a);

	return;
}
void MyMul(pStack stk)
{
	int a = MyPop(stk);
	int b = MyPop(stk);
	MyPush (stk, a * b);

	return;
}
void MyDiv(pStack stk)
{
	int a = MyPop(stk);
	int b = MyPop(stk);
	MyPush (stk, b / a);

	return;
}

void MyPwr(pStack stk)
{
	int pwr = MyPop(stk);
	int a = MyPop(stk);
	MyPush(stk , 1);

	for(int i=0; i<pwr; ++i)
	{
		MyPush (stk, a * MyPop(stk));
	}

	return;
}


void MySqrt(pStack stk)
{
	int a = MyPop(stk);
	MyPush (stk, (int)sqrt(a) );

	return;
}





void MyLinEq(pStack stk , int a , int b)
{
	MyPush(stk , -b / a);

	return;
}
