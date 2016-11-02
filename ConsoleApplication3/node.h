#pragma once
typedef int ElementType;
typedef struct node {
	int item;
	struct node* link;
	struct node* past;
}Node;
typedef struct queue {
	struct node* head;
	struct node* tail;
	int length;
}Queue;

Node* makeNode(int data);
Queue* makeQueue();
int isEmpty(Queue* dest);
void enqueue(Queue* dest, ElementType data);
ElementType peek(Queue* dest);
void destroy(Queue* dest);
ElementType dequeue(Queue* dest);
ElementType at(Queue* dest, int index);
void makeKbonacci(Queue* dest, int k, int n);