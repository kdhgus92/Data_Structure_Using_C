#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"
#include "ListBaseStack.h"

void StackInit(Stack * pstack)
{
	pstack->plist = (List*)malloc(sizeof(List));
	ListInit(pstack->plist);
}

int SIsEmpty(Stack * pstack)
{
	if (LCount(pstack->plist) == 0)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data)
{
	LInsertFront(pstack->plist, data);
}

Data SPop(Stack * pstack)
{
	Data rdata;
	
	//if (SIsEmpty(pstack))
	//{
	//	printf("Stack Memory Error!");
	//	exit(-1);
	//}

	LFirst(pstack->plist, &rdata);
	LRemove(pstack->plist);

	return rdata;
}

Data SPeek(Stack * pstack)
{
	Data data;

	//if (SIsEmpty(pstack))
	//{
	//	printf("Stack Memory Error!");
	//	exit(-1);
	//}
	LFirst(pstack->plist, &data);

	return data;
}
