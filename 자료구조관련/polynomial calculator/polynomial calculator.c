#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

void show(int* A, int size) {
    for (int i = size; i >= 0; i--) {
        if (i != 0) {
            if (A[i] != 0)
                printf(" %dx^%d + ", A[i], i);
        }
        else {
            if (A[i] != 0)
                printf("%d ", A[i]);
        }
    }
}



void plus(int* A, int* B, int AMAX, int BMAX) {
    int MAX;
    int sel = 0;
    if (AMAX > BMAX) {
        MAX = AMAX;
        sel = 1;
    }
    else {
        MAX = BMAX;
        sel = 2;
    }


    int* c;
    c = (int*)malloc(sizeof(int) * (MAX + 1));
    for (int i = 0; i <= MAX; i++) {
        c[i] = 0;
    }


    for (int i = MAX; i >= 0; i--) {
        if (sel == 1) { //A가 큰 경우
            if (i > BMAX && A[i] != 0)
                c[i] = A[i];
            if (i <= BMAX && A[i] != 0 && B[i] != 0)
                c[i] = A[i] + B[i];
            if (i <= BMAX && A[i] != 0 && B[i] == 0)
                c[i] = A[i];
            if (i <= BMAX && A[i] == 0 && B[i] != 0)
                c[i] = B[i];
        }
        if (sel == 2) { //A가 큰 경우
            if (i > AMAX && B[i] != 0)
                c[i] = B[i];
            if (i <= AMAX && A[i] != 0 && B[i] != 0)
                c[i] = A[i] + B[i];
            if (i <= AMAX && A[i] != 0 && B[i] == 0)
                c[i] = A[i];
            if (i <= AMAX && A[i] == 0 && B[i] != 0)
                c[i] = B[i];
        }

    }

    show(c, MAX);
}


void mulhang(int* A, int AMAX, int co, int exp) {
    int MAX = AMAX + exp;
    int* c;
    c = (int*)malloc(sizeof(int) * (MAX + 1));
    for (int i = 0; i <= MAX; i++) {
        c[i] = 0;
    }

    for (int i = MAX; i >= 0; i--) {
        if (A[i] != 0) {
            c[i + exp] = A[i] * co;
            A[i] = 0;
        }
    }

    show(c, MAX);
}


void input(int* A, int AMAX) {
    int sel = 1;
    int co, exp;
    for (int i = 0; i <= AMAX; i++) {
        A[i] = 0;
    }

    while (sel == 1) {

        printf("지수와 계수를 입력하세요");
        scanf("%d %d", &exp, &co);
        A[exp] = co;

        printf("계속입력하시겠습니까?  1 : 계속 , 0 : 탈출");
        scanf("%d", &sel);

    }
}


int main() {
    int* A = 0;
    int AMAX = 0;

    int* B = 0;
    int BMAX = 0; 

    int co, exp;
    int sel1 = 1;
    int sel2 = 1;

    printf("A 다항식을 입력합니다. \n");
    printf("최고차항의 지수를 입력해주세요");
    scanf("%d", &AMAX);
    
    A = (int*)malloc(sizeof(int) * (AMAX + 1));
    input(A, AMAX);
   


    printf("B 다항식을 입력합니다. \n");
    printf("최고차항의 지수를 입력해주세요");
    scanf("%d", &BMAX);
    
    B = (int*)malloc(sizeof(int) * (BMAX + 1));
    input(B, BMAX);
  

    show(A, AMAX);
    printf("\n");
    show(B, BMAX);



    printf("\n 어떤 작업을 진행할까요? 1. 덧셈, 2. ax^z를 곱하기, 3. 곱셈>>");
    scanf("%d", &sel1);

    if (sel1 == 1) {
        plus(A, B, AMAX, BMAX);
    }

    if (sel1 == 2) {

        printf("A,B중에 선택하세요. A = 1, B = 2 >> ");
        scanf("%d", &sel2);

        printf("곱할 지수와 계수를 입력하세요.");
        scanf("%d %d", &exp, &co);

        if (sel2 == 1) {
            mulhang(A, AMAX, co, exp);
        }

        if (sel2 == 2) {
            mulhang(B, BMAX, co, exp);
        }
    }

    if (sel1 == 3) {

        int MAX = AMAX + BMAX;
        int* c;
        c = (int*)malloc(sizeof(int) * (MAX + 1));
        
        int* d;
        d = (int*)malloc(sizeof(int) * (MAX + 1));
        for (int p = 0; p <= MAX; p++) {
            d[p] = 0;
        }

        for (int i = AMAX; i >= 0; i--) {
            for (int p = 0; p <= MAX; p++) {
                c[p] = 0;
            }

            if (A[i] != 0) {
                for (int j = BMAX; j >= 0; j--) {
                    if (B[j] != 0) 
                        c[j + i] = B[j] * A[i];
                }

                show(c, MAX);
                printf("\n  \n");

                
                for (int i = MAX; i >= 0; i--) {
                        if (i > MAX && c[i] != 0)
                            d[i] = c[i];
                        if (i <= MAX && c[i] != 0 && d[i] != 0)
                            d[i] = c[i] + d[i];
                        if (i <= MAX && c[i] != 0 && d[i] == 0)
                            d[i] = c[i];
                        if (i <= MAX && c[i] == 0 && d[i] != 0)
                            d[i] = d[i];
                    }
              

                }

            }
        printf("--------------------- \n");
        show(d, MAX);
        }

}