// 미완성....

#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree3.h"
#include "BinarySearchTree3.h"
#include "AVLRebalance.h"

void BSTMakeAndInit(BTreeNode ** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
	return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
	BTreeNode * pNode = NULL;
	BTreeNode * cNode = *pRoot;
	BTreeNode * nNode = NULL;

	while (cNode != NULL)
	{
		if (data == GetData(cNode))
			return; //데이터 키의 중복 허용하지 않음

		pNode = cNode;

		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	nNode = MakeBTreeNode();
	SetData(nNode, data);

	if (pNode != NULL)
	{
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else
	{
		*pRoot = nNode;
	}
	*pRoot = Rebalance(pRoot);
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
	BTreeNode * cNode = bst;
	BSTData cd;

	while (cNode != NULL)
	{
		cd = GetData(cNode);

		if (target == cd)
			return cNode;
		else if (target < cd)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	return NULL; //탐색대상이 저장되어 있지 않음.
}

//확장부분
BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)
{
	BTreeNode * pVRoot = MakeBTreeNode();
	BTreeNode * pNode = pVRoot;
	BTreeNode * cNode = *pRoot;
	BTreeNode * dNode;				//delete node

	ChangeRightSubTree(pVRoot, *pRoot);

	while (cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;

		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	if (cNode == NULL)
		return NULL;

	dNode = cNode;

	//case1 : 단말노드
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}

	//case2 : 삭제대상이 하나의 자식노드 갖는경우
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode * dcNode;

		if (GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);

		if (GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}

	//case3 
	else
	{
		BTreeNode * mNode = GetRightSubTree(dNode);
		BTreeNode * mpNode = dNode;
		int delData;

		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		delData = GetData(dNode);
		SetData(dNode, GetData(mNode));

		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData);
	}

	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);

	free(pVRoot);
	*pRoot = Rebalance(pRoot);
	return dNode;
}


void ShowIntData(int data)
{
	printf("%d ", data);
}

void BSTShowAll(BTreeNode * bst)
{
	InorderTraverse(bst, ShowIntData);
}



BTreeNode * BSTInsert2(BTreeNode ** pRoot, BSTData data)
{
	if (*pRoot == NULL)
	{
		*pRoot = MakeBTreeNode();
		SetData(*pRoot, data);
	}

	else if (data < GetData(*pRoot))
	{
		BSTInsert2(&((*pRoot)->left), data);
		*pRoot = Rebalance(pRoot);
	}

	else if (data > GetData(*pRoot))
	{
		BSTInsert2(&((*pRoot)->right), data);
		*pRoot = Rebalance(pRoot);
	}

	else
		return NULL;

	return *pRoot;
}




BTreeNode * BSTRemove2(BTreeNode ** pRoot, BSTData target)
{
	/*
	BTreeNode * pVRoot = MakeBTreeNode();
	BTreeNode * pNode = pVRoot; */
	BTreeNode * pNode;
	BTreeNode * cNode = *pRoot;
	BTreeNode * dNode;				//delete node
	
	pNode = NULL;

	if (cNode == NULL)
		return NULL;


	if (target < GetData(cNode))
	{
		pNode = cNode;
		cNode = GetLeftSubTree(cNode);
		dNode = BSTRemove2(&(*pRoot)->left, target);
		*pRoot=Rebalance(pRoot);
	}

	else if (target > GetData(cNode))
	{
		pNode = cNode;
		cNode = GetRightSubTree(cNode);
		dNode = BSTRemove2(&((*pRoot)->right), target);
		*pRoot = Rebalance(pRoot);
	}


	else // (target == GetData(cNode))
	{
		dNode = cNode;

		//case1 : 단말노드
		if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
		{
			if (GetLeftSubTree(pNode) == dNode)
				RemoveLeftSubTree(pNode);
			else
				RemoveRightSubTree(pNode);
		}

		//case2 : 삭제대상이 하나의 자식노드 갖는경우
		else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
		{
			BTreeNode * dcNode;

			if (GetLeftSubTree(dNode) != NULL)
				dcNode = GetLeftSubTree(dNode);
			else
				dcNode = GetRightSubTree(dNode);

			if (GetLeftSubTree(pNode) == dNode)
				ChangeLeftSubTree(pNode, dcNode);
			else
				ChangeRightSubTree(pNode, dcNode);
		}

		//case3 
		else
		{
			BTreeNode * mNode = GetRightSubTree(dNode);
			BTreeNode * mpNode = dNode;
			int delData;

			while (GetLeftSubTree(mNode) != NULL)
			{
				mpNode = mNode;
				mNode = GetLeftSubTree(mNode);
			}

			delData = GetData(dNode);
			SetData(dNode, GetData(mNode));

			if (GetLeftSubTree(mpNode) == mNode)
				ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
			else
				ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

			dNode = mNode;
			SetData(dNode, delData);
		}

		return dNode;
	}



	/*
	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);

	free(pVRoot); */
	return dNode;
}
