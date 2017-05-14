#ifndef _Stack_Arr_H
#define _Stack_Arr_H

struct StackRecord;
typedef struct StackRecord *Stack;
typedef int ElementType;

int IsEmpty(Stack);
int IsFull(Stack);
Stack CreateStack(int);
void MakeEmpty(Stack);
void Push(ElementType, Stack);
void Dispose(Stack);
ElementType Top(Stack);
void Pop(Stack);
ElementType TopAndPop(Stack);

#endif