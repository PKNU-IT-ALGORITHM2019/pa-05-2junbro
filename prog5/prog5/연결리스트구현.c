#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

typedef struct NODE {
	struct NODE *next;
	int data;
}node;

void addFirst(node *target, int data);

int main()
{
	node *head = malloc(sizeof(node));
	node *node1 = malloc(sizeof(node));
	head->next = node1;
	node1->data = 10;
	node *node2 = malloc(sizeof(node));
	node1->next = node2;
	node2->data = 20;
	node2->next = NULL;

	//��� �߰� Ȱ��
	addFirst(node2, 30);

	node *curr = head->next;

	//��ȯ�ϸ鼭 ���
	while (curr != NULL) {
		printf("%d\n", curr->data);
		curr = curr->next;
	}

	//��ȯ�ϴ� �����͸� �̿��� �޸� �����ϴ¹�
	curr = head->next;
	while (curr != NULL) {
		node *next = curr->next;
		free(curr);
		curr = next;
	}
	free(head);

	////��� ������� �޸� �����ϴ¹�
	//free(node2);
	//free(node1);
	//free(head);

	getchar();
	getchar();
	return 0;
}

//��� �߰��ϴ� �Լ�
void addFirst(node *target, int data) {
	node* newNode = malloc(sizeof(node));
	newNode->next = target->next;
	newNode->data = data;
	target->next = newNode;
}

//��� ���� �Լ�
