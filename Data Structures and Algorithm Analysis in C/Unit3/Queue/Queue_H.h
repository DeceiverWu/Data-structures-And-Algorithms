#ifndef _Queue_H
#define _Queue_H

struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef int ElementType;

int IsEmpty(Queue);
int IsFull(Queue);
Queue CreateQueue(int);
void DisposeQueue(Queue);
void MakeEmpty(Queue);
void Enqueue(ElementType, Queue);
ElementType Front(Queue);
void Dequeue(Queue);
ElementType FrontAndDequeue(Queue);

#endif