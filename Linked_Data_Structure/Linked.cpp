#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

// ���
typedef struct Node {
	int value;
	struct Node* link;
}; Node;

// ������ ��ũ�� ����Ű�� ����ü
typedef struct Start {
	Node* head;
}; Start;

void printList(Start* L) {
	Node* p;
	printf("L = (");
	p = L->head;
	while (p != NULL) {
		printf("%d", p->value);
		p = p->link;
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}

// ���鸮��Ʈ�� �����ϴ� �Լ� (����)
Start* createLinkedList() {
	Start* L;
	L = (Start*)malloc(sizeof(Start));
	L->head = NULL;
	return L;
}

// ��带 �����ϴ� �Լ� (����)
void freeLinkedList(Start* L) {
	Node* temp;
	while (L->head != NULL) {
		temp = L->head;
		L->head = L->head->link;
		free(temp);
		temp = NULL;
	}
}

// �Ǿտ� ��带 �����ϴ� �Լ�
void insertFirstNode(Start* L, int Xvalue) {
	Node* newNode;  // ��带 �ϳ� �����ϰ� �Ҵ� �޴´�.
	newNode = (Node*)malloc(sizeof(Node));
	newNode->value = Xvalue; // ���� ��ũ�� �����ϰ�
	newNode->link = L->head;
	L->head = newNode; // �������� ���� �����带 ����Ű���Ѵ�.
}

void insertLastNode(Start* L, int Xvalue) {
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->value = Xvalue;

	Node* temp;
	newNode->link = NULL;

	if (L->head == NULL) {
		L->head = newNode;
		return;
	}

	temp = L->head;
	while (temp->link != NULL)
		temp = temp->link;
	temp->link = newNode;
}

void insertMiddleNode(Start* L, Node* pre, int Xvalue) {
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->value = Xvalue;

	if (L == NULL) {
		newNode->link = NULL;
		L->head = newNode;
	}

	else if (pre == NULL)
		L->head = newNode;

	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}


Node* SearchNode(Start* L, int Xvalue) {
	Node* temp;
	temp = L->head;
	while (temp != NULL) {
		if (temp->value == Xvalue)
			return temp;
		else
			temp = temp->link;
	}

	return temp;
}

void deleteNode(Start* L, Node* p) {
	// ������ ���� ������ �� ���
	Node* pre;
	// ���� ���鸮��Ʈ��� 
	if (L->head == NULL) {
		printf("������ ����Ʈ�� �����ϴ�.");
		return;
	}
	// ���� ����Ʈ�� �Ѱ����
	if (L->head->link == NULL) {
		freeLinkedList(L);
	}

	// �Է¹��� ��尡 ���ٸ�
	else if(p == NULL){
		printf("������ ����Ʈ�� �����ϴ�.");
		return;
	}

	// �� 3���� ��찡 �ƴ� ���
	else {
		pre = L->head;  // �켱 �������� �ְ�
		while (pre->link != p) // ������ ��带 ����ų������ ����
			pre = pre->link;
		// ��带 ����Ų�ٸ� ���� ����� �ּҰ��� �ް�, free ������.
		pre->link = p->link;
		free(p);
	}
}




void insertSituation(Start* L) {
	printList(L);
	printf("������ ��ġ�� 1. ó��, 2. �߰�, 3. �� ->");
	int sel1, insert;
	Node* p;
	scanf("%d", &sel1);
	switch (sel1) {
	case 1:
		printf("ó���� �����մϴ�. ���� �Է��ϼ��� -> ");
		scanf("%d", &insert);
		insertFirstNode(L, insert);
		break;

	case 2:
		printf("�߰��� �����մϴ�. ã�� ���� �Է��ϼ��� -> ");
		scanf("%d", &insert);
		p = SearchNode(L, insert);
		printf("��� �ڿ� �����մϴ�. ���� �Է��ϼ���. -> ");
		scanf("%d", &insert);
		insertMiddleNode(L, p, insert);
		break;

	case 3:
		printf("���� �����մϴ�. ������ �ڸ��� ���� �Է��ϼ���. -> ");
		scanf("%d", &insert);
		insertLastNode(L, insert);
		break;
	}
}


void deleteCal(Start* L) {
	int insert;
	Node* p;
	printList(L);
	printf("������ value�� �Է��ϼ���. ->");
	scanf("%d", &insert);
	p = SearchNode(L, insert);
	deleteNode(L, p);
}

void reverseNode(Start* L) {
	Node* p;
	p = L->head;

	Node* q;
	q = NULL;

	Node* r;
	r = NULL;

	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}

	L->head = q;
}



int main() {
	Start* L;

	int sel;

	L = createLinkedList();


	printf("----���� ����Ʈ �����ϱ�----");

	while (true) {
		printList(L);
		printf("���ϴ� �۾��� �����ϼ���. 1. ����, 2. ����, 3. ����Ʈ�� ����, 4. �������� �����ϱ� ->");
		scanf("%d", &sel);

		switch (sel) {
		case 1:
			insertSituation(L);
			break;

		case 2:
			deleteCal(L);
			break;

		case 3:
			freeLinkedList(L);
			break;

		case 4:
			reverseNode(L);
			break;
		}
	}

	

}