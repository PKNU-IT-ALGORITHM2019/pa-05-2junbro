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

	//노드 추가 활용
	addFirst(node2, 30);
	addFirst(node2, 40);
	addFirst(node2, 50);
	addFirst(node2, 60);

	//누가 추가 하는거 문자 활용 하는법??
	char word_2[10];
	int num = 0, play = 0;
	while (1) {
		printf("정지:-1 계속:1");
		scanf("%d", &play);
		if (play == -1)
			break;
		else {
			printf("추가할 노드 위치 입력:");
			scanf("%s", &word_2);
			printf("추가할 숫자 입력:");
			scanf("%d", &num);
			printf("%s 다음위치에 %d 를 추가  ", word_2, num);
			node *word_2 = malloc(sizeof(node));
			addFirst(word_2, num);

			node *curr = head->next;
			while (curr != NULL) {
				printf("%d ", curr->data);
				curr = curr->next;
			}
		}
	}


	//노드 제거 활용
	removeFirst(node1);

	//순환하면서 출력
	node *curr = head->next;
	while (curr != NULL) {
		printf("%d ", curr->data);
		curr = curr->next;
	}

	printf("\n/////////\n");

	//검색 활용
	int find_num;
	printf("찾을 정수 입력");
	scanf("%d", &find_num);
	node *found = findNode(head, find_num);
	if (found == NULL)
		printf("없음\n");
	else
		printf("찾은값: %d\n", found->data);

	//찾아서 제거
	printf("값 입력하면 찾아서 제거: ");
	num = 0;
	scanf("%d", &num);	
	node_del(head, num);

	//전체 출력
	curr = head->next;
	while (curr != NULL) {
		printf("%d ", curr->data);
		curr = curr->next;
	}


	//순환하는 포인터를 이용해 메모리 해제하는법
	curr = head->next;
	while (curr != NULL) {
		node *next = curr->next;
		free(curr);
		curr = next;
	}
	free(head);

	////노드 만든것을 메모리 해제하는법
	//free(node2);
	//free(node1);
	//free(head);

	getchar();
	getchar();
	return 0;
}

//노드 추가하는 함수
void addFirst(node *target, int data) {
	printf("노드 추가됨\n");
	if (target == NULL)	//기준노드가 NULL 이면 함수 끝
		return;
	node* newNode = malloc(sizeof(node));
	if (newNode == NULL)
		return;
	newNode->next = target->next;
	newNode->data = data;
	target->next = newNode;
}

//노드 삭제 함수 target 노드의 다음 노드 제거
void removeFirst(node *target) {
	if (target == NULL)
		return;
	node *removeNode = target->next;
	if (removeNode == NULL)
		return;
	target->next = removeNode->next;
	free(removeNode);
}

//특정 노드 검색
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

//삭제 원하는 노드 제거
node *node_del(node *head, int data) {
	node *tmp, *ptr;
	tmp = ptr = head;
	if (head == NULL) {
		printf("빈리스트\n");
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
			printf("삭제하고자 하는값 없음 \n");
		else
			tmp->next = ptr->next;
	}
	return head;
}

