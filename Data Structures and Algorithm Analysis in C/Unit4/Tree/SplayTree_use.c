#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SplayTree.h"

struct SplayNode
{
	ElementType element;
	SplayTree left;
	SplayTree right;
};

SplayTree CreateSplayTree()
{
	return NULL;
}

SplayTree MakeEmpty(SplayTree t)
{
	if(t != NULL){
		MakeEmpty(t->left);
		MakeEmpty(t->right);
		free(t);
	}

	return NULL;
}

static Position SingleRotateWithLeft(Position k2)
{
	Position k1;

	k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;

	return k1;
}

static Position SingleRotateWithRight(Position k2)
{
	Position k1;

	k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;

	return k1;
}

//之字形(Zig-zag)情形，可以直接使用双旋转，不需要重新另写解决方法
static Position DoubleRotateWithLeft(Position k3)
{
	k3->left = SingleRotateWithRight(k3->left);
	return SingleRotateWithLeft(k3);
}

static Position DoubleRotateWithRight(Position k3)
{
	k3->right = SingleRotateWithLeft(k3->right);
	return SingleRotateWithRight(k3);
}

//一字形(Zig-zig)情形
static Position ZigZigRotateWithLeft(Position G)
{
	Position P = G->left;
	Position X = P->left;
	Position B = X->right;
	Position C = P->right;

	X->right = P;
	P->left = B;
	p->right = G;
	G->left = C;

	return X;
}

static Position ZigZigRotateWithRight(Position G)
{
	Position P = G->right;
	Position X = P->right;
	Position B = P->left;
	Position C = X->left;

	X->left = P;
	P->right = C;
	P->left = G;
	G->right = B;

	return X;
}

Position Find(ElementType x, SplayTree t)
{
	if(t == NULL)
		return NULL;
	else if(x < t->element){

	}
}

Position FindMin(SplayTree t)
Position FindMax(SplayTree t)
SplayTree Insert(ElementType x, SplayTree t)
SplayTree Delete(ElementType x, SplayTree t)

ElementType Retrieve(Position p)
{
	return p->element;
}

void listDirectory(SplayTree t)
{

}

int main()
{

}