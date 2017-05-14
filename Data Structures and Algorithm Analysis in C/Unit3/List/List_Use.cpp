#include <iostream>
using std::cin; using std::cout; using std::endl;

#include "List_H.h"

struct Node
{
	int Element;
	Position Next;
};

int IsEmpty(List L){
	return L->Next == NULL;
}

int IsLast(Position P,List L){
	return P->Next == NULL;
}

Position Find(int X, List L){
	Position P;

	P = L->Next;
	while(P->Element != X && P != NULL){
		P = P->Next;
	}

	return P;
}

Position FindPrevious(int X, List L){
	Position P;

	P = L;
	while(P->Next != NULL && P->Next->Element != X){
		P = P->Next;
	}

	return P;
}

//插入链表尾
void Inserts(int X, List L){
	Position P,TemCell;

	P = L;
	while(P->Next != NULL)
		P = P->Next;

	TemCell = malloc(sizeof(struct Node));
	TemCell->Element = X;
	TemCell->Next = NULL;
	P->Next = TemCell;
}

//如果不存在X，则什么都不做
//P为要删除结点的前置结点
void Delete(int X,List L){
	Position P, TemCell;

	P = FindPrevious(X, L);
	if(!IsLast(P, L)){
		TemCell = P->Next;
		P->Next = TemCell->Next;
		free(TemCell);
	}
}

void DeleteList(List L){
	Position P,TemCell;

	P = L->Next;
	L->Next = NULL;
	while(P != NULL){
		//TemCell = P;
		//p = P->Next;
		//free(TemCell);
		TemCell = P;
		free(P);
		p = TemCell->Next;
	}
}

//要测试函数，自己套路，函数原型在文件List_H.h中, 部分函数未实现
int main(void)
{

}