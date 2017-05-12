//这里ElementType暂时是Int类型,

#ifndef _List_H
#define _List_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List *L);
int IsEmpty(List *L);
int IsLast(Position *P, List *L);
Position Find(int X, List *L);
void Delete(int X, List *L);
Position FindPreviou(int X, List *L);
void Insert(int X, List *L, Position *P);
void DeleteList(List *L);
Position Header(List *L);
Position First(List *L);
Position Advance(Position *P);
int Retrieve(Position *P);

#endif