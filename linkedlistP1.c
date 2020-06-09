#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	struct node* next;
	struct node* prev;
	int data;
}Node;
typedef struct table {
	Node* head;
	Node* tail;
	Node* index;
	
	int size;

}*Table;
Table createTable() {
	Table T = (Table)malloc(sizeof(struct table));
	T->head = NULL;
	T->tail = NULL;
	T->index = NULL;
	T->size = 0;
	return T;
}
Node* createNode(int item) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->prev = NULL;
	newNode->next = NULL;
	newNode->data = item;
	return newNode;

}
void connectNode(Table T,int n) {
	Node* newNode;
	for (int i = 1; i <= n; i++) {

		newNode = createNode(i);

		if (T->size == 0) {
			T->head = newNode;
			T->tail = newNode;
		}
		else {
			newNode->prev = T->tail;
			T->tail->next = newNode;
			T->tail = newNode;
			
			newNode->next = T->head;
			T->head->prev = T->tail;
		}
		T->size++;
	}
}
int* yose(Table T,int n, int k) {
	int indexNum=0;
	int count = n;
	int resultNumindex=0;
	int* resultNum;
	
	resultNum = (int*)malloc(sizeof(int) * n);
	connectNode(T, n);
	T->index = T->head;
	while (count==(k-1)) {
		for (int i = 1; i <= k; i++) {
			
			indexNum = i;
			if (indexNum == k) {
				
				resultNum[resultNumindex++] = T->index->data;
				if (T->index == T->head)
					T->head = T->head->next;
				else if (T->index == T->tail)
					T->tail = T->tail->prev;
				
				count--;
				
			}
			T->index = T->index->next;
			/*index로 k번째에 있는
			정수 지우고 지워진 정수 배열에 저장하고 
			지운 노드 앞뒤 연결*/
		}
	}
	for (int i = 0; i < 7; i++) {
		printf("%d", resultNum[i]);
	}
	return resultNum;
}
int main() {

	Table T = createTable();
	int* result=yose(T, 7, 3);
	
	
	for (int i = 0; i < 7; i++) {
		printf("%d",result[i]);
	}
	
	return 0;
}