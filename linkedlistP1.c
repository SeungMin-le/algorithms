#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	struct node* next;
	int data;
	
}Node;
typedef struct linkedList {
	Node* first;
	Node* last;
	Node* index;
	int size;
}*Link;
Link createlinkedList() {
	Link S = (Link)malloc(sizeof(struct linkedList));
	S->first = NULL;
	S->index = NULL;
	S->size = 0;
}
Node* createNode(int item) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = item;
}
Link makeYose(Link S,int n) {
	int i = 1;
	Node* newNode;
	while (i <= n) {
		if (S->size == 0) {
			newNode = createNode(i);
			S->first = newNode;
			S->index = newNode;
			S->last = newNode;
		}
		else {
			newNode = createNode(i);
			S->last->next = newNode;
			S->last = newNode;
			
		}
		i++;
		S->size++;
	}
	return S;
}
int main() {
	Link s = createlinkedList();
	Link horse = makeYose(s,7);
	for (int i = 0; i < 7; i++) {
		printf("%d",horse->index->data);
		horse = horse->index->next;
	}
}