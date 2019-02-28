#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"
#include "Employee.h"

Employee * WhosNightDuty(List * plist, char* name, int day);
void ShowEmployeeInfo(Employee * emp);

int main(void)
{
	int i;
	Employee * pemp;

	List list;
	ListInit(&list);

	for (i = 0; i < 3; i++)
		printf("%d ", i);
	printf("\n%d \n", i);
	for (i = 0; i < 3; ++i)
		printf("%d ", i);
	printf("\n%d \n", i);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 111;
	strcpy(pemp->name, "가가가");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 222;
	strcpy(pemp->name, "나나나");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 333;
	strcpy(pemp->name, "다다다");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 444;
	strcpy(pemp->name, "라라라");
	LInsert(&list, pemp);


	ShowEmployeeInfo(WhosNightDuty(&list, "나나나", 2)); //라라라
	ShowEmployeeInfo(WhosNightDuty(&list, "나나나", 3)); //가가가
	ShowEmployeeInfo(WhosNightDuty(&list, "나나나", 4)); //나나나
	ShowEmployeeInfo(WhosNightDuty(&list, "다다다", 2)); //가가가
	ShowEmployeeInfo(WhosNightDuty(&list, "가가가", 2)); //다다다

	if (LFirst(&list, &pemp))
	{
		free(pemp);
		for (i = 0; i < LCount(&list)-1; i++) {
			LNext(&list, &pemp);
			free(pemp);
		}		
	}


	
	return 0;
}


Employee* WhosNightDuty(List * plist, char * name, int day)
{
	int i, num;
	Employee * ret;

	num = LCount(plist);

	LFirst(plist, &ret);

	if (strcmp(ret->name, name) != 0) //첫 순서가 찾는 이름이 아니라면
	{
		for (i = 0; i < num - 1; i++)
		{
			LNext(plist, &ret);    //찾을때까지 돌리자
			if (strcmp(ret->name, name) == 0)  
				break;
		}
		if (i >= num - 1)  //못찾고 for문이 끝나면 i = num-1
			return NULL;
	}

	for (i = 0; i < day; i++)
		LNext(plist, &ret);

	return ret;
}

void ShowEmployeeInfo(Employee * emp)
{
	printf("Employee name: %s \n", emp->name);
	printf("Employee number: %d \n", emp->empNum);
}
