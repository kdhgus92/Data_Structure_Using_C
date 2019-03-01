#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0;

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node * next;
	struct _node * prev;
} Node;

typedef struct _DLinkedList
{
	Node * head;
	Node * tail;   //05-2 추가된 부분
	Node * cur;
	int numOfData;
} DBLinkedList;

typedef DBLinkedList List;

void ListInit(List* plist);
void LInsert(List* plist, Data data); //꼬리에 추가

int LFirst(List* plist, Data* pdata);
int LNext(List* plist, Data* pdata);
int LPrevious(List* plist, Data* pdata);

Data LRemove(List* plist); 
int LCount(List* plist);


#endif
