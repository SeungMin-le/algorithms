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
//empty : ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.

int empty(Queue q) {
	if (q->size == 0)
		return 1;
	else
		return 0;
}
//pop : ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�.���� ť�� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
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
//push X : ���� X�� ť�� �ִ� �����̴�.
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

//size : ť�� ����ִ� ������ ������ ����Ѵ�.
int size(Queue q) {
	return q->size;
}
//front : ť�� ���� �տ� �ִ� ������ ����Ѵ�.���� ť�� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
int front(Queue q) {
	if (empty(q) == 1) {
		return -1;
	}
	else
		return q->front->data;
}
//back : ť�� ���� �ڿ� �ִ� ������ ����Ѵ�.���� ť�� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
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