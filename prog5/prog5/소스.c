//#include <stdio.h>
//#pragma warning(disable:4996)
//
//#define MAX 100
//
//typedef struct node {
//	int data;
//	struct node *left;
//	struct node *right;
//	struct node *parent;
//}NODE;
//
//int N = 0, data[MAX] = { 0 }, end = 0, print = 0; // end는 스택 포인터, print는 프린트 포인터
//
//NODE *queue[MAX];
//NODE *head = NULL;
//
//void levelorder_walk(NODE *x) {
//
//	queue[end] = x;
//	end++;
//
//	while (queue[print] != NULL) {
//		printf("\n%d ", queue[print]->data);
//
//		if (queue[print]->left != NULL) {
//			queue[end] = queue[print]->left;
//			end++;
//		}
//		if (queue[print]->right != NULL) {
//			queue[end] = queue[print]->right;
//			end++;
//		}
//
//		if (queue[print]->parent != NULL) {
//			printf("( %d의 자식 : %d) / ", queue[print]->parent->data, queue[print]->data);
//		}
//
//		queue[print] = NULL;
//		print++;
//	}
//}
//
//void postorder_walk(NODE *x) {
//	if (x != NULL) {
//		postorder_walk(x->left);
//		postorder_walk(x->right);
//		printf("%d ", x->data);
//	}
//}
//
//void preorder_walk(NODE *x) {
//	if (x != NULL) {
//		printf("%d ", x->data);
//		preorder_walk(x->left);
//		preorder_walk(x->right);
//	}
//}
//
//void inorder_walk(NODE *x) {
//	if (x != NULL) {
//		inorder_walk(x->left);
//		printf("%d ", x->data);
//		inorder_walk(x->right);
//	}
//}
//
//NODE *make_node(NODE *x, int data) {
//	x->data = data;
//	x->left = NULL;
//	x->right = NULL;
//	x->parent = NULL;
//
//	return x;
//}
//
//void insert_binary(NODE *T, NODE *z) {
//	NODE *y = NULL;
//	NODE *x = T; // T = head
//
//	while (x != NULL) {
//		y = x;
//		if (z->data < x->data) {
//			x = x->left;
//		}
//		else {
//			x = x->right;
//		}
//	}
//	z->parent = y;
//
//	if (y == NULL) {
//		head = z;
//	}
//	else if (z->data < y->data) {
//		y->left = z;
//	}
//	else {
//		y->right = z;
//	}
//}
//
//NODE *search_binary(NODE *x, int k) {
//	if (x == NULL || k == x->data) {
//		return x;
//	}
//
//	if (k < x->data) {
//		return search_binary(x->left, k);
//	}
//	return search_binary(x->right, k);
//}
//
//NODE *find_max(NODE *x) {
//	while (x->right != NULL) {
//		x = x->right;
//	}
//	return x;
//}
//
//NODE *find_min(NODE *x) {
//	while (x->left != NULL) {
//		x = x->left;
//	}
//	return x;
//}
//
//NODE *find_successor(NODE *x) {
//	if (x->right != NULL) {
//		return find_min(x->right);
//	}
//	NODE *y = x->parent;
//
//	while (y != NULL && x == y->right) {
//		x = y;
//		y = y->parent;
//	}
//	return y;
//}
//
//NODE *find_prodecessor(NODE *x) {
//	if (x->left != NULL) {
//		return find_max(x->left);
//	}
//	NODE *y = x->parent;
//
//	while (y != NULL && x == y->left) {
//		x = y;
//		y = y->parent;
//	}
//	return y;
//}
//
//void *del_binary(NODE *T, NODE *z) {
//	NODE *x, *y;
//
//	if (z->left == NULL || z->right == NULL) {
//		y = z;
//	}
//	else {
//		y = find_successor(z);
//	}
//
//	if (y->left != NULL) {
//		x = y->left;
//	}
//	else {
//		x = y->right;
//	}
//
//	if (x != NULL) {
//		x->parent = y->parent;
//	}
//
//	if (y->parent == NULL) {
//		head = x;
//	}
//	else if (y == y->parent->left) {
//		y->parent->left = x;
//	}
//	else {
//		y->parent->right = x;
//	}
//
//	if (y != z) {
//		z->data = y->data;
//
//	}
//}
//
//void print_binary() {
//	printf("Inorder 순회 : ");
//	inorder_walk(head);
//	printf("\n\n");
//
//	printf("Preorder 순회 : ");
//	preorder_walk(head);
//	printf("\n\n");
//
//	printf("Postorder 순회 : ");
//	postorder_walk(head);
//	printf("\n\n");
//
//	printf("Levelorder 순회 : ");
//	levelorder_walk(head);
//
//	printf("최대값 : %d / 최소값 : %d\n", find_max(head)->data, find_min(head)->data);
//}
//
//void main() {
//
//	FILE *fp = fopen("input.txt", "r");
//	fscanf(fp, "%d", &N);
//
//	for (int i = 0; i < N; i++) {
//		fscanf(fp, "%d", &data[i]);
//	}
//
//	for (int i = 0; i < N; i++) {
//		NODE *temp = malloc(sizeof(NODE));
//		temp = make_node(temp, data[i]);
//
//		insert_binary(head, temp);
//	}
//
//	print_binary();
//
//	int input = 0;
//	scanf("%d", &input);
//
//	if (search_binary(head, input) != NULL) {
//		printf("결과 : %d\n", search_binary(head, input)->data);
//
//		NODE *target = search_binary(head, input);
//
//		if (find_successor(target) != NULL && find_prodecessor(target) != NULL) {
//			printf("Successor : %d\n", find_successor(target)->data);
//			printf("Prodecessor : %d\n\n", find_prodecessor(target)->data);
//		}
//
//		del_binary(head, target);
//	}
//
//	print_binary();
//
//	getchar();
//	getchar();
//}