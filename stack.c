#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node {
	struct node* next;
	struct node* prev;
	int data;
}Node;
typedef struct stack {
	Node* bottom;
	Node* top;
	int size;
}*Stack;
Stack createStack(void) {
	Stack s = (Stack)malloc(sizeof(struct stack));
	s->bottom = NULL;
	s->top = NULL;
	s->size = 0;
	return s;
}
void push(Stack s, int newData) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->data = newData;
	if (s->size == 0) {
		s->bottom = newNode;
		s->top = newNode;
	}
	else {
		
		newNode->prev = s->top;
		s->top->next = newNode;
		s->top = newNode;

		
	}
	s->size++;
}
int pop(Stack s) {
	Node* oldNode;
	int i;
	oldNode = s->top;
	i = oldNode->data;
	
	s->top = oldNode->prev;

	free(oldNode);
	s->size--;
	return i;
}
bool is_empty(Stack s) {
	return s->bottom == NULL;

}
/*void delete_stack(Stack s) {
	make_Empty(s);
	free(s);
}*/
/*void make_Empty(Stack s) {
	while (!is_empty) {
		pop(s);
	}
	s->size = 0;
}*/
int main() {
	Stack s;
	int i = 0;
	Node* horse;
	s=createStack();
	push(s, 8);
	push(s, 9);
	push(s, 10);
	horse = s->bottom;
	for (int i = 0; i < s->size; i++) {
		printf("%d ", horse->data);
		horse = horse->next;
		
	}
	pop(s);
	horse = s->bottom;
	for (int i = 0; i < s->size; i++) {
		printf("%d ", horse->data);
		horse = horse->next;

	}
	return 0;
}
