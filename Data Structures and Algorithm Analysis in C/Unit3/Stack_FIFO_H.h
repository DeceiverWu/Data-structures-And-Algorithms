#ifndef _Stack_H
#define _Stack_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef int ElementType;

int IsEmpty(Stack);
Stack CreateStack(void);
void DisposeStack(Stack);
void MakeEmpty(Stack);
void Push(ElementType, Stack);
ElementType Top(Stack);
void Pop(Stack);

#endif