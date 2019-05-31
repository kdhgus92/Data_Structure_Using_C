#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree3.h"
#include "BinarySearchTree3.h"

int main(void)
{
	BTreeNode * avlRoot;
	BTreeNode * clNode;
	BTreeNode * crNode;
	BSTMakeAndInit(&avlRoot);

	BSTInsert2(&avlRoot, 1);	
	BSTInsert2(&avlRoot, 2);
	BSTInsert2(&avlRoot, 3);
	BSTInsert2(&avlRoot, 4);
	BSTInsert2(&avlRoot, 5);
	BSTInsert2(&avlRoot, 6);
	BSTInsert2(&avlRoot, 7);
	BSTInsert2(&avlRoot, 8);
	BSTInsert2(&avlRoot, 9);
	
	printf("루트 노드: %d \n", GetData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("왼쪽1: %d, 오른쪽1: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("왼쪽2: %d, 오른쪽2: %d \n", GetData(clNode), GetData(crNode));

	/*
	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("왼쪽3: %d, 오른쪽3: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("왼쪽4: %d, 오른쪽4: %d \n", GetData(clNode), GetData(crNode));
	*/

	printf("중간 \n");

	BSTRemove2(&avlRoot, 2);
	BSTRemove2(&avlRoot, 3);

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("왼쪽1: %d, 오른쪽1: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("왼쪽2: %d, 오른쪽2: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("왼쪽3: %d, 오른쪽3: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("왼쪽4: %d, 오른쪽4: %d \n", GetData(clNode), GetData(crNode));


	return 0;
}
