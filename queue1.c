#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node {
	int data;
	Node* next;
}Node;
typedef struct queue {
	Node* front;
	Node* rear;
	int size;
}*Queue;
Queue createQueue(void) {
	Queue q = (Queue)malloc(sizeof(struct queue));
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;

	return q;
}
int get_Size(Queue q) {
	return q->size;
}
void delete_queue(Queue q) {
	make_empty(q);
	free(q);
	
}
bool is_empty(Queue q) {
	return q->front == NULL;
}
void make_empty(Queue q) {
	while (!is_empty)
		dequeue(q);
	q->size = 0;
}
void enqueue(Queue q, int item) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = item;

	if (q->size == 0) {
		q->front = newNode;
		q->rear = newNode;
	}
	else {
		q->rear->next = newNode;
		q->rear = newNode;
	}
	q->size++;
}
int dequeue(Queue q) {
	Node* oldNode;
	int i;
	oldNode = q->front;
	i = oldNode->data;
	q->front = oldNode->next;
	if (q->front == NULL) {
		q->rear = NULL;
	}
	free(oldNode);
		
	q->size--;

	return i;
}
int main() {
	Queue q;
	int i = 0;
	q=createQueue();
	enqueue(q, 8);
	enqueue(q, 9);
	enqueue(q, 10);
	while (!is_empty(q)) {
		printf("%d" ,q[i]);
		i++;
	}
	return 0;
}
