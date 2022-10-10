#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

// ��� ����ü
typedef struct Node {
	struct Node* leftLink;
	int value;
	struct Node* rightLink;
}; Node;

// �������� ����Ű�� ����ü
typedef struct Start {
	Node* head;
}; Start;


// ���� ����Ʈ�� ����ϴ� ����
void printList(Start* L) {
	Node* p;
	printf("L = (");
	p = L->head;
	while (p != NULL) {
		printf("%d", p->value);
		p = p->rightLink;
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}


void reversePrintList(Start* L) {
	Node* p;
	printf("L = (");
	p = L->head;
	while (p->rightLink != NULL) {
		p = p->rightLink;
	}

	while (p->leftLink != NULL) {
		printf("%d", p->value);
		p = p->leftLink;
		if (p != NULL) printf(", ");
	}
	printf("%d", p->value);
	printf(") \n");
}






Start* createLinkedList() {
	Start* L;
	L = (Start*)malloc(sizeof(Start));
	L->head = NULL;
	return L;
}

void freeLinkedList(Start* L) {
	Node* temp;
	while (L->head != NULL) {
		temp = L->head;
		L->head = L->head->rightLink;
		free(temp);
		temp = NULL;
	}
}


void insertFirstNode(Start* L, int Xvalue) {
		Node* newNode;  // ��带 �ϳ� �����ϰ� �Ҵ� �޴´�.
		newNode = (Node*)malloc(sizeof(Node));
		newNode->value = Xvalue; // ���� ��ũ�� �����ϰ�
		
		if (L->head == NULL) {
			newNode->rightLink = NULL;
			newNode->leftLink = NULL;
		}
		else {
			newNode->rightLink = L->head;
			newNode->leftLink = NULL;
			L->head->leftLink = newNode;
		}
		L->head = newNode; // �������� ���� �����带 ����Ű���Ѵ�.
}


// ���� ������ ��带 Ž���Ͽ� �����Ѵ�.
Node* SearchNode(Start* L, int Xvalue) {
	Node* temp;
	temp = L->head;
	while (temp != NULL) {
		if (temp->value == Xvalue)
			return temp;
		else
			temp = temp->rightLink;
	}

	return temp;
}



void insertMiddleNode(Start* L, Node* pre, int Xvalue) {
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->value = Xvalue;

	// ���鸮��Ʈ�� ���
	if (L == NULL) {
		newNode->rightLink = NULL;
		newNode->leftLink = NULL;
		L->head = newNode;
	}

	// pre�� R��ũ�� NULL�̿��� �������. (���� �ִ� ���̿��� ���� ����)
	else {
		newNode->rightLink = pre->rightLink;
		pre->rightLink = newNode;
		newNode->leftLink = pre;
		// �߰��� ���ԵǴ� ����� ���� ����� ������ ���ԵǴ� ��带 �����Ѿ��Ѵ�.
		if (newNode->rightLink != NULL)
			newNode->rightLink->leftLink = newNode;
	}
}

// ���� ���� ����Ʈ���� old ��带 �����ϴ� ����
void deleteNode(Start* L, Node* p) {
	//���鸮��Ʈ��� ����
	if (L->head == NULL) {
		printf("������ ����Ʈ�� �����ϴ�.");
		return;
	}

	// ���� ����Ʈ�� �Ѱ����
	if (L->head->rightLink == NULL) {
		freeLinkedList(L);
	}

	//����Ʈ�� ���ٸ� ����
	else if (p == NULL) {
		printf("������ ����Ʈ�� �����ϴ�.");
		return;
	}

	else {
		p->leftLink->rightLink = p->rightLink;
		if (p->rightLink != NULL) {
			p->rightLink->leftLink = p->leftLink;
		}
		free(p);
	}
}



void insertSituation(Start* L) {
	printList(L);
	printf("������ ��ġ�� 1. ó��, 2. �߰� Ȥ�� �� ->");
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
		printf("�߰� Ȥ�� ���� �����մϴ�. ���ϴ� ������ ���� �Է��ϼ��� -> ");
		scanf("%d", &insert);
		p = SearchNode(L, insert);
		printf("��� �ڿ� �����մϴ�. ���� �Է��ϼ���. -> ");
		scanf("%d", &insert);
		insertMiddleNode(L, p, insert);
		break;
	}
}

void deleteSituation(Start* L) {
	int insert;
	Node* p;
	printList(L);
	printf("������ value�� �Է��ϼ���. ->");
	scanf("%d", &insert);
	p = SearchNode(L, insert);
	deleteNode(L, p);
}

void wantSee(Start* L) {
	Node* p;
	int count = 1;
	bool sel;
	p = L->head;

	printf("��ȸ�� �����մϴ�. \n");
	while (true) {
		printf("\n%d��° �� = %d \n", count, p->value);
		printf("0.���� , 1. ����");

		scanf("%d", &sel);
		if (sel == 0) {
			if (p->leftLink == NULL)
				printf("���� ���Դϴ�.\n");
			else {
				p = p->leftLink;
				count++;
			}
		}

		if (sel == 1) {
			if (p->rightLink == NULL)
				printf("������ ���Դϴ�.\n");
			else {
				p = p->rightLink;
				count++;
			}
			
		}
	
	}
}


int main() {
	Start* L;

	int sel;
	L = createLinkedList();


	printf("----���� ����Ʈ �����ϱ�----\n");

	while (true) {
		printList(L);
		printf("���ϴ� �۾��� �����ϼ���. 1. ����, 2. ����, 3. ����Ʈ�� ����, 4. �������� ����ϱ�, 5 ��ȸ ->");
		scanf("%d", &sel);

		switch (sel) {
		case 1:
			insertSituation(L);
			break;

		case 2:
			deleteSituation(L);
			break;

		case 3:
			freeLinkedList(L);
			break;

		case 4:
			printf("�������� ����մϴ�.");
			reversePrintList(L);
			printf("\n");
			break;

		case 5:
			wantSee(L);
			break;
		}
	}



}