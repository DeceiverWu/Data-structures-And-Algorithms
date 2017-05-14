#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Stack_FIFO_H.h"

struct Node
{
	ElementType Element;
	PtrToNode Next;
};


//参数S为链表头
int IsEmpty(Stack S){
	return S->Next == NULL;
}

void MakeEmpty(Stack S){
	if(S == NULL)
		printf("Must use CreateStack first\n");
	else
		while(!IsEmpty(S))
			Pop(S);
}

//创建栈
Stack CreateStack(void){
	Stack S;

	S = (Stack)malloc(sizeof(struct Node));
	if(S == NULL)
		printf("Out of Space!!!\n");
	S->Next = NULL;
	MakeEmpty(S);
	return S;
}

void DisposeStack(Stack S){
	if(S == NULL)
		printf("Empty Stack!!!\n");
	else
		while(!IsEmpty(S))
			Pop(S);
}

//压栈
void Push(ElementType X, Stack S){
	PtrToNode TmpCell;

	TmpCell = (Stack)malloc(sizeof(struct Node));
	if(TmpCell == NULL)
		printf("Out of Space!!!\n");
	else{
		TmpCell->Element = X;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}

//返回栈顶元素
ElementType Top(Stack S){
	if(!IsEmpty(S))
		return S->Next->Element;
	printf("Empty Stack!!!\n");
	return 0;
}

//删除栈顶元素，这个我也是觉得有点鸡肋，用下面Pops代替
void Pop(Stack S){
	PtrToNode FirstCell;

	if(IsEmpty(S))
		printf("Empty Stack\n");
	else{
		FirstCell = S->Next;
		S->Next = FirstCell->Next;
		free(FirstCell);
	}
}

//返回栈顶元素并且删除
ElementType Pops(Stack S){
	PtrToNode FirstCell;
	ElementType tmp;

	if(IsEmpty(S))
		printf("Empty Stack\n");
	else{
		FirstCell = S->Next;
		S->Next = FirstCell->Next;
		tmp = FirstCell->Element;
		free(FirstCell);
		return tmp;
	}
}

int main(void)
{
	int temp, i;
	Stack SHead;
	SHead = CreateStack();

	printf("随机生成10个数：\n");
	for(i = 0 ; i < 10 ; i++){
		temp = rand()%100; //随机生成10个数
		printf("Num[%d]=%2d \t", i, temp);
		Push(temp,SHead);
	}
	printf("\n下面按照顺序弹出栈中所有元素并输出:\n");
	
    //for(i = 0 ; i < 10 ; i++){
    //	printf("第%2d个出栈的是%4d \n", i+1, SHead->Next->Element);
    //	Pop(SHead);        
    //}

    for(i = 0 ; i < 10 ; i++){
    	printf("第%2d个出栈的是%4d \n", i+1, Pops(SHead));
    }

	return 0;
}

