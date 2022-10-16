#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int pack(int n) {
	if (n == 1) {
		return n;
	}
	return n * pack(n - 1);
}

int main() {
	int n;
	printf("펙토리얼을 구합니다. 숫자를 입력해주세요.");
	scanf("%d", &n);
	printf("%d", pack(n));
}