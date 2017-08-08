#include <stdio.h>
#include <stdlib.h>
#include "AVLTree.h"

struct AvlNode{
	ElementType element;
	AvlTree left;
	AvlTree right;
	int height;
};

static int Height(Position p)
{
	if(p == NULL)
		return -1;
	else
		return p->height;
}

static int Max(int x, int y)
{
	return x > y ? x : y; 
}

AvlTree MakeEmpty(AvlTree t)
{
	if(t != NULL){
		MakeEmpty(t->left);
		MakeEmpty(t->right);
		free(t);
	}

	return NULL;
}

Position Find(ElementType x, AvlTree t)
{
	if(t == null)
		return NULL;
	if(x < t->element)
		return Find(x, t->left);
	else if(x > t->element)
		return Find(x, t->right);
	else
		return t;
}

Position FindMin(AvlTree t)
{
	if(t == NULL)
		return NULL;
	else if(t->left == NULL)
		return t;
	else 
		return FindMin(t->left);
}

Position FindMinNotRec(AvlTree t)
{
	while(t->left != NULL)
		t = t->left;
	return t;
}

Position FindMax(AvlTree t)
{
	if(t == NULL)
		return NULL;
	else if(t->right == NULL)
		return t;
	else 
		return FindMax(t->right);
}

Position FindMaxNotRec(AvlTree t)
{
	while(t->right != NULL)
		t = t->right;
	return t;
}

static Position SingleRotateWithLeft(Position k2)
{
	Position k1;

	k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;

	k2->height = Max(Height(k2->left), Height(k2->right)) + 1;
	k1->height = Max(Height(k1->left), k2->height) + 1;

	return k1;
}

static Position SingleRotateWithRight(Position k2)
{
	Position k1;

	k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;

	k2->height = Max(Height(k2->left), Height(k2->right)) + 1;
	k1->height = Max(Height(k1->right), k2->height) + 1;

	return k1;
}

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

AvlTree Insert(ElementType x, AvlTree t)
{
	if(t == NULL){
		t = malloc(sizeof(struct AvlNode));
		if(t == NULL)
			printf("It is fatal error!!!\n");
			exit(-1);
		else{
			t->element = x;
			t->height
			t->left = NULL;
			t->right = NULL;
		}
	else if(x < t->element){
		t->left = Insert(x, t->left);
		if(Height(t->left) - Height(t->right) == 2)
			if(x < t->left->element)
				t = SingleRotateWithLeft(t);
			else
				t = DoubleRotateWithLeft(t);

	}else if(x > t->element){
		t->right = Insert(x, t->right);
		if(Height(t->right) - Height(t->left) == 2)
			if(x > t->right->element)
				t = SingleRotateWithRight(t);
			else
				t = DoubleRotateWithRight(t);
	}

	return t;
}

AvlTree Delete(ElementType x, AvlTree t)
{

}

ElementType Retrieve(Position p)
{
	return p->element;
}




