#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void)
{
	List list;
	NameCard * pcard;
	NameCard * rcard;
	int i;

	ListInit(&list);

	LInsert(&list, MakeNameCard("홍길동", "111-1111"));
	LInsert(&list, MakeNameCard("김개똥", "222-2222"));
	LInsert(&list, MakeNameCard("가가가", "333-3333"));

	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "홍길동"))
		{
			ShowNameCardInfo(pcard);
		}
		//else
		//{
			while (LNext(&list, &pcard))
			{
				if (!NameCompare(pcard, "홍길동"))
				{
					ShowNameCardInfo(pcard);
					break;
				}
			}
		//}
	}

	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "김개똥"))
		{
			ChangePhoneNum(pcard, "555-5555");
		}
		//else
		//{
		while (LNext(&list, &pcard))
		{
			if (!NameCompare(pcard, "김개똥"))
			{
				ChangePhoneNum(pcard, "555-5555");
				break;
			}
		}
		//}
	}


	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "가가가"))
		{
			rcard = LRemove(&list);
			free(rcard);
		}
		else
		{
			while (LNext(&list, &pcard)) {
				if (!NameCompare(pcard, "가가가"))
				{
					rcard = LRemove(&list);
					free(rcard);
					break;
				}
			}
		}
	}

	printf("%d \n", LCount(&list));

	if (LFirst(&list, &pcard))
	{
		ShowNameCardInfo(pcard);
		while (LNext(&list, &pcard))
		{
			ShowNameCardInfo(pcard);
		}
	}
	printf("\n");


	return 0;
	
}
