#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Queue_H.h"

struct QueueRecord
{
	int capacity;
	int front;
	int rear;
	int size;
	ElementType *Array;
};

int IsEmpty(Queue q){
	return q->size == 0;
}

int IsFull(Queue q){
	return q->size == q->capacity;
}

void MakeEmpty(Queue q){
	q->size = 0;
	q->front = 1;
	q->rear = 0;
}

Queue CreateQueue(int MaxCapacity){
	Queue q;

	q = malloc(sizeof(struct QueueRecord));
	if(q == NULL){
		printf("Out of space!!!\n");
		exit(-1);
	}

	q->Array = malloc(sizeof(ElementType) * MaxCapacity);
	if(q->Array == NULL){
		printf("Out of space!!!\n");
		exit(-1);
	}

	q->capacity = MaxCapacity;
	MakeEmpty(q);

}

void DisposeQueue(Queue q){
	if(q != NULL){
		free(q->Array);
		free(q);
	}
}

//若q->rear到达队列尾，则将从队列头开始覆盖
static int Succ(int value, Queue q){
	if(++value == q->capacity)
		value = 0;
	return value;
}

void Enqueue(ElementType x, Queue q){
	if(IsFull(q))
		printf("Queue is full!!!\n");
	else{
		q->size++;
		q->rear = Succ(q->rear, q);
		q->Array[q->rear] = x;
	}
}

ElementType Front(Queue q){
	if(!IsEmpty(q))
		return q->Array[q->front];
	else
		printf("Queue is Empty!!!\n");
	return 0;
}

void Dequeue(Queue q){
	if(!IsEmpty(q)){
		q->front++;
		q->size--;
	}else
		printf("Queue is Empty!!!\n");
}

ElementType FrontAndDequeue(Queue q){
	ElementType temp;

	if(IsEmpty(q))
		printf("Queue is Empty!!!\n");
	else{
		temp = q->Array[q->front];
		q->front++;
		q->size--;
		return temp;
	}

	return 0;
}

int main(void)
{
	Queue q;
	int queueSize, i, temp;

	queueSize = 5;
	q = CreateQueue(queueSize);

	printf("随机生成5个数：\n");
	for(i = 0 ; i < queueSize ; i++){
		temp = rand()%100; //随机生成5个数
		printf("Num[%d]=%2d \n", i, temp);
		Enqueue(temp, q);
	}

	printf("The Queue Front is :%d\n", q->front);
	printf("The Queue Capacity is :%d\n", q->capacity);
	printf("The Queue current size is :%d\n", q->size);
	printf("The Queue Rear is :%d\n", q->rear);

	printf("\n");
	//调用Front函数
	printf("Use Front Foundation : %d\n", Front(q));

	//调用FrontAndDequeue函数
	printf("Use FrontAndDequeue Foundation : %d\n", FrontAndDequeue(q));

	DisposeQueue(q);
	return 0;
}



