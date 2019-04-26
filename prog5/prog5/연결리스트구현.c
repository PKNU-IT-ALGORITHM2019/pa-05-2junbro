#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

typedef struct NODE {
	struct NODE *next;
	int data;
}node;

void addFirst(node *target, int data);
void removeFirst(node *target);
node *findNode(node *node_find, int data);
node *node_del(node *head, int data);


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
	addFirst(node2, 40);
	addFirst(node2, 50);
	addFirst(node2, 60);

	//���� �߰� �ϴ°� ���� Ȱ�� �ϴ¹�??
	char word_2[10];
	int num = 0, play = 0;
	while (1) {
		printf("����:-1 ���:1");
		scanf("%d", &play);
		if (play == -1)
			break;
		else {
			printf("�߰��� ��� ��ġ �Է�:");
			scanf("%s", &word_2);
			printf("�߰��� ���� �Է�:");
			scanf("%d", &num);
			printf("%s ������ġ�� %d �� �߰�  ", word_2, num);
			node *word_2 = malloc(sizeof(node));
			addFirst(word_2, num);

			node *curr = head->next;
			while (curr != NULL) {
				printf("%d ", curr->data);
				curr = curr->next;
			}
		}
	}


	//��� ���� Ȱ��
	removeFirst(node1);

	//��ȯ�ϸ鼭 ���
	node *curr = head->next;
	while (curr != NULL) {
		printf("%d ", curr->data);
		curr = curr->next;
	}

	printf("\n/////////\n");

	//�˻� Ȱ��
	int find_num;
	printf("ã�� ���� �Է�");
	scanf("%d", &find_num);
	node *found = findNode(head, find_num);
	if (found == NULL)
		printf("����\n");
	else
		printf("ã����: %d\n", found->data);

	//ã�Ƽ� ����
	printf("�� �Է��ϸ� ã�Ƽ� ����: ");
	num = 0;
	scanf("%d", &num);	
	node_del(head, num);

	//��ü ���
	curr = head->next;
	while (curr != NULL) {
		printf("%d ", curr->data);
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
	printf("��� �߰���\n");
	if (target == NULL)	//���س�尡 NULL �̸� �Լ� ��
		return;
	node* newNode = malloc(sizeof(node));
	if (newNode == NULL)
		return;
	newNode->next = target->next;
	newNode->data = data;
	target->next = newNode;
}

//��� ���� �Լ� target ����� ���� ��� ����
void removeFirst(node *target) {
	if (target == NULL)
		return;
	node *removeNode = target->next;
	if (removeNode == NULL)
		return;
	target->next = removeNode->next;
	free(removeNode);
}

//Ư�� ��� �˻�
node *findNode(node *node_find, int data) {
	if (node_find == NULL)
		return NULL;
	node *curr = node_find->next;
	while (curr != NULL) {
		if (curr->data == data)
			return curr;
		curr = curr->next;
	}
	return NULL;
}

//���� ���ϴ� ��� ����
node *node_del(node *head, int data) {
	node *tmp, *ptr;
	tmp = ptr = head;
	if (head == NULL) {
		printf("�󸮽�Ʈ\n");
		return 0;
	}
	if (ptr->data == data)
		head = ptr->next;
	else {
		while (ptr->data != data && ptr->next != NULL) {
			tmp = ptr;
			ptr = ptr->next;
		}
		if (ptr->data != data && ptr->next == NULL)
			printf("�����ϰ��� �ϴ°� ���� \n");
		else
			tmp->next = ptr->next;
	}
	return head;
}

