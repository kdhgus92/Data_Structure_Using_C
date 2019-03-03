#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack * pstack)
{
	pstack->head = NULL;
}

int SIsEmpty(Stack * pstack)
{
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (pstack->head == NULL)
	{
		newNode->next = NULL;
		pstack->head = newNode;
	}
	else
	{
		newNode->next = pstack->head;
		pstack->head = newNode;
	}

	(pstack->numOfData)++;
}

Data SPop(Stack * pstack)
{
	Node* rnod = pstack->head;
	Data data = pstack->head->data;
	
	pstack->head = pstack->head->next;
	
	free(rnod);
	return data;
}

Data SPeek(Stack * pstack)
{
	Data data = pstack->head->data;
	return data;
}
