#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

typedef struct node {
	int value;
	struct node* next;
}Node;

Node* g_pHead = NULL;

void generate_num(int n) {
	for (int i = 0; i < n; i++) {//n���� ������ �����ϱ� ���� ���� �޸� �Ҵ��� ���� ���Ḯ��Ʈ ����.
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->value = rand() % 10000;
		newNode->next = NULL;
		if (g_pHead == NULL) {
			g_pHead = newNode;
		}
		else {
			newNode->next = g_pHead;
			g_pHead = newNode;
		}
	}
}

void print_num() {
	Node* pHead = g_pHead;
	while (pHead != NULL) {
		printf("%d ", pHead->value);
		pHead = pHead->next;
	}
	printf("\n");
}

Node* head[10] = {NULL};	//�� ���Ḯ��Ʈ�� ��带 �����ϴ� ������ �迭.
Node* tail[10] = { NULL };  //�� ���Ḯ��Ʈ�� ������ �����ϴ� ������ �迭.

void push(Node **head, int data) {
	Node* temp = (Node*)malloc(sizeof(Node));//0���� 9 ������ �ڸ����� �ش��ϴ� ���Ḯ��Ʈ�� ���� ���� �޸� �Ҵ�.
	temp->value = data;
	temp->next = NULL;
	if (!*head) {
		*head = temp;
	}
	else {
		temp->next = *head;
		*head = temp;
	}
}

void pop(Node** head) {
	Node* temp = *head;
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->value = temp->value;
	newNode->next = NULL;
	if (g_pHead == NULL) {
		g_pHead = newNode;
	}
	else {
		newNode->next = g_pHead;
		g_pHead = newNode;
	}
	*head = (*head)->next;
	free(temp);
	temp = NULL;
}

int main() {
	int n, m;
	srand(time(NULL));

	printf("n�� ���� m�� ���� �Է��ϼ���.(����� ����):");
	scanf_s("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		printf("[%d��°] �����ϱ� ���� ����\n",i+1);
		generate_num(n);
		print_num();
		int exp = 1;
		for (int i = 0; i < 4; i++) {

			while (g_pHead != NULL) {
				push(&head[g_pHead->value / exp % 10], g_pHead->value);
				g_pHead = g_pHead->next;
			}
			for (int i = 0; i < 10; i++) {
				while (head[9 - i] != NULL) {
					pop(&head[9 - i]);
				}
			}
			exp = exp * 10;
		}
		printf("[%d��°] ������� ���� ���\n",i+1);
		print_num();
		while (g_pHead != NULL) {
			Node* ptr = g_pHead;
			g_pHead = g_pHead->next;
			free(ptr);
		}
	}
	return 0;
}
