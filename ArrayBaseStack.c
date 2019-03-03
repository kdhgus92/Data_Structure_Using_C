#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack * pstack)
{
	int i;
	for (i = 0; i < STACK_LEN; i++)
		pstack->stackArr[i] = 0;
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
	Data data = pstack->stackArr[pstack->topIndex];
	pstack->stackArr[pstack->topIndex] = 0;
	(pstack->topIndex)--;
	return data;
}

Data SPeek(Stack * pstack)
{
	Data data = pstack->stackArr[pstack->topIndex];
	return data;
}
