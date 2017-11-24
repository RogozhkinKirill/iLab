/*Infix notation
 *f = (c / b - 3 * a * c + b^2) / (2 * a + b * c)
 *
 *Reverse Polish notation(prefix notation)
 *f = c , b / 3 , a , c * * - b , 2 ^ + 2 , a * b , c * + /
 */

#include "StackFunctions.h"

int main()
{
	Stack(stk);

	int a = 0,
		b = 0,
		c = 0;

	printf("a = ");
	scanf("%d" , &a);
	printf("\n");

	printf("b = ");
	scanf("%d" , &b);
	printf("\n");

	printf("c = ");
	scanf("%d" , &c);
	printf("\n");

	MyPush(pstk , c);
	MyPush(pstk , b);
	MyDiv(pstk);
	MyPush(pstk , 3);
	MyPush(pstk , a);
	MyPush(pstk , c);
	MyMul(pstk);
	MyMul(pstk);
	MySub(pstk);
	MyPush(pstk , b);
	MyPush(pstk , 2);
	MyPwr(pstk);
	MyAdd(pstk);
	MyPush(pstk , 2);
	MyPush(pstk , a);
	MyMul(pstk);
	MyPush(pstk , b);
	MyPush(pstk , c);
	MyMul(pstk);
	MyAdd(pstk);
	MyDiv(pstk);

	MyStkDump(pstk);


    MyDestroy(&pstk);

    return 0;
}

