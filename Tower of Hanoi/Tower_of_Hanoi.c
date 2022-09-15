#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int count = 1;

void hanoi(int n, char start, char end, char pass) {
	if (n == 1) {
		printf("%d. 원판 %d를 %c에서 %c로 움직였습니다. \n",count++, n, start, end);
	}
	else {
		hanoi(n - 1, start, pass, end);
		printf("%d. 원판 %d를 %c에서 %c로 움직였습니다. \n", count++, n, start, end);
		hanoi(n - 1, pass, end, start);
	}
}

int main() {
	int n;
	printf("하노이을 구합니다. 숫자를 입력해주세요.");
	scanf("%d", &n);
	hanoi(n, 'A', 'C', 'B');
	printf("%d 번 이동했습니다.", count-1);
}