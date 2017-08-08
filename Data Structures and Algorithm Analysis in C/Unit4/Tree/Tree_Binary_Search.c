#include <stdio.h>
#include "Tree_H.h"
#include <stdlib.h>
#include <math.h>

struct TreeNode{
	ElementType element;
	Tree left;
	Tree right;
};

//建立一棵空二叉树
Tree MakeEmpty(Tree tree)
{
	if(tree != NULL){
		MakeEmpty(tree->left);
		MakeEmpty(tree->right);
		free(tree);
	}

	return NULL;
}

Position Find(ElementType x, Tree tree)
{
	if(tree == NULL)
		return NULL;
	if(x < tree->element)
		return Find(x, tree->left);
	else if(x > tree->element)
		return Find(x, tree->right);
	else
		return tree;
}

Position FindMin(Tree tree)
{
	if(tree == NULL)
		return NULL;
	else if(tree->left == NULL)
		return tree;
	else
		return FindMin(tree->left);
}

Position FindMinNotRec(Tree tree)
{
	while(tree->left != NULL)
		tree = tree->left;

	return tree;
}

Position FindMax(Tree tree)
{
	if(tree == NULL)
		return NULL;
	else if(tree->right == NULL)
		return tree;
	else
		return FindMax(tree->right);
}

Position FindMaxNotRec(Tree tree)
{
	while(tree->right != NULL)
		tree = tree->right;

	return tree;
}

Tree Insert(ElementType x, Tree tree)
{
	if(tree == NULL){
		tree = malloc(sizeof(struct TreeNode));
		if(tree == NULL){
			printf("It is fatal error!!!\n");
		}else{
			tree->element = x;
			tree->left = NULL;
			tree->right = NULL;
		}
	}else if(x < tree->element)
		tree->left = Insert(x, tree->left);
	else if(x > tree->element)
		tree->right = Insert(x, tree->right);

	return tree;
}

Tree Delete(ElementType x, Tree tree)
{
	Position tmpCell;

	if(tree == NULL)
		printf("Node is not founded !!!\n");
	else if(x < tree->element)
		tree->left = Delete(x, tree->left);
	else if(x > tree->element)
		tree->right = Delete(x, tree->right);
	else if(tree->left && tree->right){
		tmpCell = FindMin(tree->right);
		tree->element = tmpCell->element;
		tree->right = Delete(tmpCell->element, tree->right);
	}else{
		tmpCell = tree;

		if(tree->left == NULL)
			tree = tree->right;
		else if(tree->right == NULL)
			tree = tree->left;
		free(tmpCell);
	}

	return tree;
}

//获取TreeNode的element元素
ElementType Retrieve(Position p)
{  
    return p->element;  
}  

int main()
{
	Tree tree = NULL;
	Position p;


	tree = MakeEmpty(tree);
	for(int i = 0; i < 10; i++){
		tree = Insert(rand()%100, tree);
	}

	printf("%d\n",tree->element);



	p = FindMin(tree);
	printf("%d\n", p->element);
	p = FindMinNotRec(tree);
	printf("%d\n", p->element);

	p = FindMax(tree);
	printf("%d\n", p->element);
	p = FindMaxNotRec(tree);
	printf("%d\n", p->element);

	Tree = MakeEmpty(tree);

	return 0;
}