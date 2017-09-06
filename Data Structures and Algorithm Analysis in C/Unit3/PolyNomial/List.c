/*
*链表操作(底层实现)
*/

#include "List_H.h"
#include <stdlib.h>
#include "fatal.h"

struct Node{
	ElementType Element;
	Position Next;
};

int compareElement(ElementType a, ElementType b){
	return a.Coefficient == b.Coefficient && a.Exponent == b.Exponent;
}

List CreateList()
{
	List l = malloc(sizeof(struct Node));
	if(l == NULL){
		Error("out of memory.");
	}

	l->Next = NULL;
	return l;
}

List MakeEmpty(List L)
{
	if(L == NULL){
		Error("List is not create.")
	}

	DeleteList(L);
	L->Next = NULL;

	return L;
}

int isEmpty(List L)
{
	return L->Next == NULL;
}

int isLast(Position P, List L)
{
	return P->Next == NULL;
}

void Delete(ElementType X, List L);
{
	Position p;
	p = FindPrevious(X, L);

	if(!isLast(p, L)){
		Position tmpCell = p->Next;
		p->Next = tmpCell->Next;
		free(tmpCell);
	}
}

//插入合适的位置,插入P后面
void Insert(ElementType X, Position P){
	Position tmpCell;
	tmpCell = malloc(sizeof(struct Node));
	if(tmpCell == NULL){
		Error("out of memory.");
	}
	tmpCell->Element = X;
	tmpCell->Next = P->Next;
	P->Next = tmpCell;
}

void DeleteList(List L)
{
	Position p;
	p = L->Next;

	while(p->Next != NULL){
		Position tmpCell = p->Next;
		free(p);
		p = tmpCell;
	}
}

Position Find(ElementType X, List L)
{
	Position p;
	p = L->Next;

	while(p != NULL && !compareElement(p->Element, X)){
		p = p->Next;
	}

	return p;
}

//找到匹配结点的前一个结点
Position FindPrevious(ElementType X, List L)
{
	Position p;
	p = L;

	while(p->Next != NULL && !compareElement(p->Next->Element, X)){
		p = p->Next;
	}

	return p;
}

Position Header(List L)
{
	return L;
}

//头结点不存放任何数据
Position First(List L);
{
	return L->Next;
}

Position Advance(Position P);
{
	return P->Next;
}

ElementType Retrieve(Position P)
{
	P->Element;
}
