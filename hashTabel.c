#include<stdio.h>
#include<stdlib.h>

struct bucket* hashTable = NULL;
int Size = 10;
int flag = 0;
typedef struct node {
	struct node* next;
	int key;
	int value;
}Node;
struct bucket {
	struct node* head;
	int count;
};
Node* createNode(int key, int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = key;
	newNode->value = value;
	newNode->next = NULL;
	return newNode;
}
int hashfunction(int key) {
	return key % Size;
}
void insert(int key, int value) {
	if (flag == 0) {
		hashTable = (struct bucket*)malloc(sizeof(struct bucket) * Size);
		for (int i = 0; i < Size; i++) {
			hashTable[i].count = 0;
			hashTable[i].head = NULL;
		}
		flag = 1;
	}
	Node* node = createNode(key, value);
	
	int tableIndex = hashfunction(key);
	

	if (hashTable[tableIndex].count == 0) {
		
		hashTable[tableIndex].head = node;

	}
	else {
		node->next = hashTable[tableIndex].head;
		hashTable[tableIndex].head = node;

	}
	hashTable[tableIndex].count++;
}
void search(int key) {
	int tableIndex = hashfunction(key);
	Node* node = hashTable[tableIndex].head;
	if (node == NULL)
		printf("key not found");
	else {
		while (hashTable[tableIndex].count != 0) {
			if (key == node->key) {
				printf("\nkey->%d value->%d \n", node->key, node->value);
				return;
			}
			node = node->next;
		}
	}
	printf("key not found");
	return;
}
void delete(int key) {
	int tableIndex = hashfunction(key);
	Node* node = hashTable[tableIndex].head;
	Node* trace = node;
	
	
	if (node == NULL) {
		printf("key not found");

	}
	while (node != NULL) {
		if (node->key == key) {
			if (node == hashTable[tableIndex].head)
				node->next = hashTable[tableIndex].head;
			trace->next = node->next;

			free(node);
			hashTable[tableIndex].count--;
			return;
		}
		node = node->next;
	}
	printf("key not found");
	return;
}
void display() {
	Node* horse;
	int i = 0;
	printf("\n---------------------------------------------\n");
	for (i = 0; i < Size; i++) {
		horse = hashTable[i].head;
		printf("hashTable[%d]=", i);
		for (int j = 0; j < hashTable[i].count; j++) {
			printf("{%d, %d}", horse->key, horse->value);
			horse = horse->next;
		}
		printf("\n");
	}
	printf("\n----------------the end----------------------\n");
}
int main() {

	insert(0, 3);
	insert(1, 4);
	insert(2, 5);
	insert(33, 56);
	delete(33);
	search(1);
	display();

	

	return 0;
}