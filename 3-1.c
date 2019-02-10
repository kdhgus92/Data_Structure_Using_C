#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	List list;
	int data;
	int sum=0;
	ListInit(&list);

	LInsert(&list, 1); LInsert(&list, 2); LInsert(&list, 3);
	LInsert(&list, 4); LInsert(&list, 5); LInsert(&list, 6);
	LInsert(&list, 7); LInsert(&list, 8); LInsert(&list, 9);

	if (LFirst(&list, &data))
	{
		sum += data;
		printf("sum : %d \n", sum);
		while (LNext(&list, &data)) {
			sum += data;
			printf("sum : %d \n", sum);
		}
	}

	if (LFirst(&list, &data))
	{
		if (data % 2 == 0 || data % 3 == 0)
			LRemove(&list);
		while (LNext(&list, &data))
		{
			if (data % 2 == 0 || data % 3 == 0)
				LRemove(&list);
		}
	}

	printf("저장된 데이터 수: %d \n", LCount(&list));

	if (LFirst(&list, &data)) {
		printf("%d ", data);
		while (LNext(&list, &data))
			printf("%d ", data);
	}


	return 0;	
}
