#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Queue{
	int front,rear,size;
	unsigned int capacity;
	int* array;
};

struct Queue* createQueue(unsigned int capacity)
{
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->rear = capacity-1;
	queue->front = queue->size=0;
	queue->array = (int*)malloc(queue->capacity*sizeof(int));
	return queue;
}

int isFull(struct Queue* queue)
{
	return (queue->size==queue->capacity);
	
}
int isEmpty(struct Queue* queue)
{
	return (queue->size==0);
	
	
}
void enqueue(struct Queue* queue , int item)
{
	if(isFull(queue))
		return;
	queue->rear = (queue->rear + 1)%queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size +1;
	printf("\nenqueued value is %d\n",item);
	
}
int dequeue(struct Queue* queue)
{
	if(isEmpty(queue))
		return INT_MIN;
	int item = queue->array[queue->front];
	queue->front= (queue->front +1)%queue->capacity;
	queue->size= queue->size - 1;
	
	return item;	
}

int main()
{
	struct Queue* queue = createQueue(1000);
	
	enqueue(queue,10);
	enqueue(queue,20);
	enqueue(queue,30);
	enqueue(queue,40);
	
	printf("\n%d is dequeued\n",dequeue(queue));
	return 0;
}
