#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef char elemtype;
typedef enum{link,thread}sign;
typedef struct binarytreenode {
	elemtype data;
	struct binarytreenode* lchild;
	struct binarytreenode* rchild;
	sign ltag;
	sign rtag;
}ThrBTnode;
typedef ThrBTnode* Thrpoin;


Thrpoin CreateThrBT()                   //创建二叉树
{
	Thrpoin T;
	elemtype ch;
	scanf_s("%c", &ch);
	if (ch == '#')
		T = NULL;
	else
	{
		T = (Thrpoin)malloc(sizeof(ThrBTnode));
		T->data = ch;
		T->ltag = link;
		T->rtag = link;
		T->lchild = CreateThrBT();
		T->rchild = CreateThrBT();
	}
	return T;
}

void InThreaded(Thrpoin T)                 //中序线索化
{
	static Thrpoin pre=NULL;
	if (T)
	{
		InThreaded(T->lchild);
		if (!T->lchild)
		{
			T->ltag = thread;
			T->lchild = pre;
		}
		if (pre&&!pre->rchild)
		{
			pre->rtag = thread;
			pre->rchild = T;
		}
		pre = T;
		InThreaded(T->rchild);
	}
}


Thrpoin Next(Thrpoin p)                //查找中序遍历下一元素
{
	if (p->rtag == thread)
		p = p->rchild;
	else 
	{
		p = p->rchild;
		while (p->ltag == link)
			p = p->lchild;
	}
	return p;
}


void InorderTraverse(Thrpoin T)             //中序遍历
{
	if (!T)
		return;

	while (T->ltag == link)
		T = T->lchild;
	printf("->%c", T->data);

	while (T->rchild)
	{
		T =Next(T);
		printf("->%c", T->data);
	}

}
