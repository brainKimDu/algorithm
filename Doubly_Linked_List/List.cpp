#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

// 노드 구조체
typedef struct Node {
	struct Node* leftLink;
	int value;
	struct Node* rightLink;
}; Node;

// 시작점을 가리키는 구조체
typedef struct Start {
	Node* head;
}; Start;


// 연결 리스트를 출력하는 연산
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
		Node* newNode;  // 노드를 하나 생성하고 할당 받는다.
		newNode = (Node*)malloc(sizeof(Node));
		newNode->value = Xvalue; // 값과 링크를 지정하고
		
		if (L->head == NULL) {
			newNode->rightLink = NULL;
			newNode->leftLink = NULL;
		}
		else {
			newNode->rightLink = L->head;
			newNode->leftLink = NULL;
			L->head->leftLink = newNode;
		}
		L->head = newNode; // 시작점은 지금 만든노드를 가리키게한다.
}


// 값을 가지는 노드를 탐색하여 리턴한다.
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

	// 공백리스트일 경우
	if (L == NULL) {
		newNode->rightLink = NULL;
		newNode->leftLink = NULL;
		L->head = newNode;
	}

	// pre의 R링크가 NULL이여도 상관없다. (끝에 넣는 것이여도 문제 없다)
	else {
		newNode->rightLink = pre->rightLink;
		pre->rightLink = newNode;
		newNode->leftLink = pre;
		// 중간에 삽입되는 경우라면 다음 노드의 왼쪽은 삽입되는 노드를 가리켜야한다.
		if (newNode->rightLink != NULL)
			newNode->rightLink->leftLink = newNode;
	}
}

// 이중 연결 리스트에서 old 노드를 삭제하는 연산
void deleteNode(Start* L, Node* p) {
	//공백리스트라면 리턴
	if (L->head == NULL) {
		printf("삭제할 리스트가 없습니다.");
		return;
	}

	// 만약 리스트가 한개라면
	if (L->head->rightLink == NULL) {
		freeLinkedList(L);
	}

	//리스트가 없다면 리턴
	else if (p == NULL) {
		printf("삭제할 리스트가 없습니다.");
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
	printf("삽입할 위치는 1. 처음, 2. 중간 혹은 끝 ->");
	int sel1, insert;
	Node* p;
	scanf("%d", &sel1);
	switch (sel1) {
	case 1:
		printf("처음에 삽입합니다. 값을 입력하세요 -> ");
		scanf("%d", &insert);
		insertFirstNode(L, insert);
		break;

	case 2:
		printf("중간 혹은 끝에 삽입합니다. 원하는 지점의 값을 입력하세요 -> ");
		scanf("%d", &insert);
		p = SearchNode(L, insert);
		printf("노드 뒤에 삽입합니다. 값을 입력하세요. -> ");
		scanf("%d", &insert);
		insertMiddleNode(L, p, insert);
		break;
	}
}

void deleteSituation(Start* L) {
	int insert;
	Node* p;
	printList(L);
	printf("삭제할 value를 입력하세요. ->");
	scanf("%d", &insert);
	p = SearchNode(L, insert);
	deleteNode(L, p);
}

void wantSee(Start* L) {
	Node* p;
	int count = 1;
	bool sel;
	p = L->head;

	printf("조회를 시작합니다. \n");
	while (true) {
		printf("\n%d번째 값 = %d \n", count, p->value);
		printf("0.이전 , 1. 다음");

		scanf("%d", &sel);
		if (sel == 0) {
			if (p->leftLink == NULL)
				printf("왼쪽 끝입니다.\n");
			else {
				p = p->leftLink;
				count++;
			}
		}

		if (sel == 1) {
			if (p->rightLink == NULL)
				printf("오른쪽 끝입니다.\n");
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


	printf("----연결 리스트 구현하기----\n");

	while (true) {
		printList(L);
		printf("원하는 작업을 선택하세요. 1. 삽입, 2. 삭제, 3. 리스트를 비우기, 4. 역순으로 출력하기, 5 조회 ->");
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
			printf("역순으로 출력합니다.");
			reversePrintList(L);
			printf("\n");
			break;

		case 5:
			wantSee(L);
			break;
		}
	}



}