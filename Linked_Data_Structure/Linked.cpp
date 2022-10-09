#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

// 노드
typedef struct Node {
	int value;
	struct Node* link;
}; Node;

// 시작점 링크를 가리키는 구조체
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

// 공백리스트를 생성하는 함수 (교재)
Start* createLinkedList() {
	Start* L;
	L = (Start*)malloc(sizeof(Start));
	L->head = NULL;
	return L;
}

// 노드를 삭제하는 함수 (교재)
void freeLinkedList(Start* L) {
	Node* temp;
	while (L->head != NULL) {
		temp = L->head;
		L->head = L->head->link;
		free(temp);
		temp = NULL;
	}
}

// 맨앞에 노드를 삽입하는 함수
void insertFirstNode(Start* L, int Xvalue) {
	Node* newNode;  // 노드를 하나 생성하고 할당 받는다.
	newNode = (Node*)malloc(sizeof(Node));
	newNode->value = Xvalue; // 값과 링크를 지정하고
	newNode->link = L->head;
	L->head = newNode; // 시작점은 지금 만든노드를 가리키게한다.
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
	// 이전의 값을 가지게 할 노드
	Node* pre;
	// 만약 공백리스트라면 
	if (L->head == NULL) {
		printf("삭제할 리스트가 없습니다.");
		return;
	}
	// 만약 리스트가 한개라면
	if (L->head->link == NULL) {
		freeLinkedList(L);
	}

	// 입력받은 노드가 없다면
	else if(p == NULL){
		printf("삭제할 리스트가 없습니다.");
		return;
	}

	// 위 3가지 경우가 아닌 경우
	else {
		pre = L->head;  // 우선 시작점을 주고
		while (pre->link != p) // 삭제할 노드를 가리킬때까지 돌자
			pre = pre->link;
		// 노드를 가리킨다면 다음 노드의 주소값을 받고, free 해주자.
		pre->link = p->link;
		free(p);
	}
}




void insertSituation(Start* L) {
	printList(L);
	printf("삽입할 위치는 1. 처음, 2. 중간, 3. 끝 ->");
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
		printf("중간에 삽입합니다. 찾을 값을 입력하세요 -> ");
		scanf("%d", &insert);
		p = SearchNode(L, insert);
		printf("노드 뒤에 삽입합니다. 값을 입력하세요. -> ");
		scanf("%d", &insert);
		insertMiddleNode(L, p, insert);
		break;

	case 3:
		printf("끝에 삽입합니다. 삽입할 자리의 값을 입력하세요. -> ");
		scanf("%d", &insert);
		insertLastNode(L, insert);
		break;
	}
}


void deleteCal(Start* L) {
	int insert;
	Node* p;
	printList(L);
	printf("삭제할 value를 입력하세요. ->");
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


	printf("----연결 리스트 구현하기----");

	while (true) {
		printList(L);
		printf("원하는 작업을 선택하세요. 1. 삽입, 2. 삭제, 3. 리스트를 비우기, 4. 역순으로 저장하기 ->");
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