#pragma once
#include<stdio.h>
#include<stdlib.h>


typedef char elemtype;
typedef struct binarytreenode {
	elemtype data;	
	struct binarytreenode* lchild;	
	struct binarytreenode* rchild;	
}BTnode;
typedef BTnode* BTpoin;



void CreateBTree(BTpoin* T)                   //创建二叉树
{
	elemtype ch;
	printf("请输入数据：");
	ch = getchar();
	while (getchar() != '\n')//清除空格（多余字符）
		continue;
	if (ch == '#')
	{
		(*T) = NULL;
		return;
	}
	(*T) = (BTpoin)malloc(sizeof(BTnode));
	(*T)->data = ch;
	CreateBTree(&((*T)->lchild));
	CreateBTree(&((*T)->rchild));
	return;
}


void PreOrderTraverse(BTnode *T)                  //前序遍历
{
	if (T == NULL)
		return;
	printf("->%c", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

 
void InOrderTraverse(BTnode*T)                   //中序遍历
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild);
	printf("->%c", T->data);
	InOrderTraverse(T->rchild);
}


void PostOrderTraverse(BTnode* T)                //后序遍历
{ 
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("->%c", T->data);
}


void ClearBTree(BTnode* T)                    //销毁二叉树
{
	if (T == NULL)
		return;
	ClearBTree(T->lchild);
	ClearBTree(T->rchild);
	free(T);
}
