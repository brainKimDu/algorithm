#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


void pibo(int n) {
	int output1 = 1;
	int output2 = 1;

	printf("%d ", output1);
	for (int i = 0; i < n; i++) {
		if (i == 1)
			printf("%d ", output2);
		if (i > 1) {
			int temp;
			temp = output2;
			output2 = output1 + output2;
			output1 = temp;
			printf("%d ", output2);
		}
	}
	
}

int main() {
	int n;
	printf("피보나치 수열을 구합니다. 숫자를 입력해주세요.");
	scanf("%d", &n);
	pibo(n);
	return 0;
}


/* 재귀함수
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int f1(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	return f1(n - 1) + f1(n - 2);
}

int main() {
	int n;
	printf("피보나치 수열을 구합니다. 숫자를 입력해주세요.");
	scanf("%d", &n);
	printf("%d", f1(n));
}


*/