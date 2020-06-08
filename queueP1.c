#include<stdio.h>
#include<stdlib.h>

#include<string.h>

typedef struct node {
	struct node* next;
	int data;
}Node;

typedef struct queue {
	Node* front;
	Node* rear;
	int size;

}*Queue;
Queue createQueue() {
	Queue q;
	q = (Queue)malloc(sizeof(struct queue));
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}
Node* createNode(Queue q) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data =0;
	return newNode;
}
//empty : 큐가 비어있으면 1, 아니면 0을 출력한다.

int empty(Queue q) {
	if (q->size == 0)
		return 1;
	else
		return 0;
}
//pop : 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다.만약 큐에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
int pop(Queue q) {
	if (empty(q) == 1)
		return -1;
	else {
		Node* oldNode = createNode(q);
		int outNum;
		oldNode = q->front;
		if (q->front == oldNode->next) {
			q->front = NULL;
			q->rear = NULL;
		}

		q->front = oldNode->next;


		outNum = oldNode->data;
		free(oldNode);
		q->size--;
		return outNum;

	}

}
void deleteNode(Queue q) {
	while (empty(q) == 0)
		pop(q);
}
//push X : 정수 X를 큐에 넣는 연산이다.
void deleteQ(Queue q) {
	deleteNode(q);
	free(q);
}

void push(Queue q,int item) {
	Node* newNode = createNode(q);
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

//size : 큐에 들어있는 정수의 개수를 출력한다.
int size(Queue q) {
	return q->size;
}
//front : 큐의 가장 앞에 있는 정수를 출력한다.만약 큐에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
int front(Queue q) {
	if (empty(q) == 1) {
		return -1;
	}
	else
		return q->front->data;
}
//back : 큐의 가장 뒤에 있는 정수를 출력한다.만약 큐에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
int back(Queue q) {
	if (empty(q) == 1) {
		return -1;
	}
	else
		return q->rear->data;
}
int main() {
	Queue q=createQueue();
	char inputData[10];
	char pusharr[6];
	int num=0;
	int outNum = 0;
	int orderNum;
	int* oNarr;
	int i = 0;
	scanf_s("%d", &orderNum);
	
	oNarr = (int*)malloc(sizeof(int) * orderNum);
	
	
	while (i<orderNum) {
		scanf_s("%s", inputData, sizeof(inputData));
		pusharr[0] = inputData[0];
		pusharr[1] = inputData[1];
		pusharr[2] = inputData[2];
		pusharr[3] = inputData[3];
		if (!strcmp(pusharr, "push")) {
			num = atoi(&inputData[5]);
			push(q, num);
			outNum = num;
		}
		else if (!strcmp(inputData, "pop")) {
			outNum = pop(q);
		}
		else if (!strcmp(inputData, "size")) {
			outNum = size(q);
		}
		else if (!strcmp(inputData, "empty")) {
			outNum = empty(q);
			
		}
		else if (strcmp(inputData, "front")) {
			outNum = front(q);
		}
		else if (strcmp(inputData, "back")) {
			outNum = back(q);
		}
		oNarr[i++] = outNum;
	}
	for (int i = 0; i < orderNum; i++) {
		printf("%d\n",oNarr[i]);
	}
	deleteQ(q);
	return 0;
}