#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack * pstack)
{
	//int i;
	//for (i = 0; i < stack_len; i++)
	//	pstack->stackarr[i] = 0;
	pstack->topIndex = -1;
}

int SIsEmpty(Stack * pstack)
{
	if (pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data)
{
	(pstack->topIndex)++;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack * pstack)
{
	int rIdx;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	rIdx = pstack->topIndex;
	Data data = pstack->stackArr[pstack->topIndex];
	//pstack->stackarr[pstack->topindex] = 0;
	(pstack->topIndex)--;
	//return data;
	return pstack->stackArr[rIdx];
}

Data SPeek(Stack * pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	Data data = pstack->stackArr[pstack->topIndex];
	return data;
}
