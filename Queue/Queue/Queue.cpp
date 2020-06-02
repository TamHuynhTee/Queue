#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;

#define MAX 10

typedef struct Node
{
	int data;
	Node* next;
}node;

typedef struct Queue_of_Nodes
{
	int capacity;
	int length;
	node* front;
	node* rear;
}Queue;

node* newNode()
{
	node* temp = new node();
	temp->data = 0;
	temp->next = NULL;
	return temp;
}

Queue* initiateQueue()
{
	Queue* q = new Queue();
	q->capacity = MAX;
	q->front = NULL;
	q->rear = NULL;
	q->length = -1;
	return q;

}

bool is_Empty(Queue* queue)
{
	return queue->length == -1;
}

bool is_Full(Queue* queue)
{
	return queue->length == queue->capacity - 1;
}

bool Enqueue(Queue* queue, int x)
{
	if (is_Full(queue))
	{
		printf("Overflow condition! Cannot add %d into queue", x);
		return false;
	}
	node* temp = newNode();
	if (is_Empty(queue))
	{
		temp->data = x;
		queue->front = queue->rear = temp;
		queue->length++;
	}
	else if(queue->length == 0)
	{
		temp->data = x;
		queue->rear = temp;
		queue->front->next = temp;
		queue->length++;
	}
	else
	{
		temp->data = x;
		queue->rear->next = temp;
		queue->rear = temp;
		queue->length++;
	}
	return true;
}

bool Dequeue(Queue* queue)
{
	if (is_Empty(queue))
	{
		printf("Underflow condition! Queue is empty.\n");
		return false;
	}
	node* temp = queue->front;
	if (queue->length == 0)
	{
		queue->length--;
		queue->front = queue->rear = NULL;
		delete temp;
	}
	else
	{
		queue->length--;
		queue->front = queue->front->next;
		delete temp;
	}
	return true;
}

int Front(Queue* queue)
{
	return queue->front->data;
}

int Size(Queue* queue)
{
	return queue->length + 1;
}

void Display(Queue* queue)
{
	if (queue->length == -1)
	{
		printf("Queue is empty.\n");
		return;
	}
	node* p = queue->front;
	printf("Elements in queue: ");
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\nFront value is: %d\nRear value is: %d\n",Front(queue),queue->rear->data);
	printf("Size of queue: %d\n", Size(queue));
}

void main()
{
	Queue* queue = initiateQueue();
	bool check;
	check = Enqueue(queue, 5);
	check = Enqueue(queue, 6);
	
	check = Dequeue(queue);
	check = Dequeue(queue);
	Display(queue);
	_getch();
}