#ifndef _Polynomial_H
#define _Polynomial_H

typedef struct {  
    int Coefficient;	//系数  
    int Exponent;	//指数  
}ElementType;

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List CreateList();
List MakeEmpty(List L);
int isEmpty(List L);
int isLast(Position P, List L);
void Delete(ElementType X, List L);
void Insert(ElementType X, Position P);
void DeleteList(List L);
Position Find(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

#endif