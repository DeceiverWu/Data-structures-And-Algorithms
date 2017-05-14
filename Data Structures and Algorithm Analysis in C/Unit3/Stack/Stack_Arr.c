#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Stack_Arr_H.h"

#define EmptyTOS (-1)
#define MinStackSize (5)

struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};

int IsEmpty(Stack s){
	return s->TopOfStack == EmptyTOS;
}

int IsFull(Stack s){
	return s->TopOfStack == (s->Capacity - 1);
}

void MakeEmpty(Stack s){
	s->TopOfStack = EmptyTOS;
}

Stack CreateStack(int MaxElements){
	Stack s;

	if(MaxElements < MinStackSize)
		printf("Stack size is too small!\n");

	s = malloc(sizeof(struct StackRecord));
	if(s == NULL){
		printf("Out of space!!!\n");
		exit(-1);
	}

	s->Array = malloc(sizeof(struct StackRecord) * MaxElements);
	if(s->Array == NULL){
		printf("Out of space!!!\n");
		exit(-1);
	}

	s->Capacity = MaxElements;
	MakeEmpty(s);

	return s;
}

void DisposeStack(Stack s){
	if(s != NULL){
		free(s->Array);
		free(s);
	}
}

void Push(ElementType x, Stack s){
	if(!IsFull(s))
		s->Array[++s->TopOfStack] = x;
	else
		printf("Full Stack!!!\n");
}

ElementType Top(Stack s){
	if(!IsEmpty(s))
		return s->Array[s->TopOfStack];
	else{
		printf("Stack is Empty!!!\n");
		return 0;
	}
}

//这个函数有什么意义吗？通常是由下面TopAndPop代码代替
void Pop(Stack s){
	if(!IsEmpty(s))
		s->TopOfStack--;
}

ElementType TopAndPop(Stack s){
	if(!IsEmpty(s))
		return s->Array[s->TopOfStack--];
	else{
		printf("Stack is Empty!!!\n");
		return 0;
	}
}

int main(void)
{
	Stack s;
	int stackSize, topDate, temp, i;

	stackSize = 10;
	s = CreateStack(stackSize);

	printf("随机生成10个数：\n");
	for(i = 0 ; i < stackSize ; i++){
		temp = rand()%100; //随机生成10个数
		printf("Num[%d]=%2d \t", i, temp);
		Push(temp, s);
	}

	//print top element of stack
	topDate = Top(s);
	printf("栈顶元素是 %d\n", topDate);

	//Pop only do TopOfStack-- like index--
	printf("Before Pop index: %d\n", s->TopOfStack);
	Pop(s);
	printf("After Pop index: %d\n", s->TopOfStack);

	topDate = TopAndPop(s);
	printf("弹出的栈顶元素: %d\n", topDate);

	DisposeStack(s);

	return 0;
}

