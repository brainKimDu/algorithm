/*
문제


0 0 2 0 0 0 12
0 0 0 0 7 0 0
23 0 0 0 0 0 0
0 0 0 31 0 0 0
0 14 0 0 0 25 0
0 0 0 0 0 0 6
52 0 0 0 0 0 0
0 0 0 0 11 0 0

다음 희소행렬의 전치를 계산해라. 선형 리스트 표현을 함고하여 표현해라.

값의 대부분이 0을 가르키는 행렬을 희소행렬이라고 하며,

행렬을 전치 시킨 후 행렬로 표현하고 싶다




1단계 선형 리스트를 사용하지 않고, 전치작업을 구현하기

int main() {
	int a[8][7] = { { 0, 0, 2, 0, 0, 0, 12},
					{ 0, 0, 0, 0, 7, 0, 0},
					{ 23, 0, 0, 0, 0 ,0 , 0 },
					{0, 0, 0 , 31, 0, 0, 0},
					{0, 14, 0, 0, 0, 25, 0},
					{0, 0, 0, 0, 0, 0, 6},
					{52, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 11, 0, 0}
	};

	int b[7][8] = { 0 };

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 7; j++) {
			printf("%d \t", a[i][j]);
		}
		printf("\n");
	}

	printf("전치를 진행합니다. \n");

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 7; j++) {
			b[j][i] = a[i][j];
		}
		printf("\n");
	}

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%d \t", b[i][j]);
		}
		printf("\n");
	}

}

*/



/*
2단계 선형 리스트를 사용하여, 전치작업을 구현하기
*/

/*
#include<stdio.h>
#include<malloc.h>


typedef struct {
	int row;
	int col;
	int value;
} term;


void Transpose(term a[], term b[], int len) {
	for (int i = 0; i < len; i++) {
		b[i].row = a[i].col;
		b[i].col = a[i].row;
		b[i].value = a[i].value;
	}
}

void show(term b[], int len) {
	for (int i = 0; i < len; i++) {
		printf("(% d, % d, %d)", b[i].col, b[i].row, b[i].value);
		printf("\n");
	}
	printf("\n");
}


int main() {
	term hang[] = { {0, 2, 2}, {0, 6, 12}, {1, 4, 7}, {2, 0, 23}, {3,  3, 31},
					{4, 1, 14}, {4, 5, 25}, {5, 6, 6}, {6, 0, 52}, {7, 4, 11}
	};
	term after[10] = { 0 };


	show(hang, sizeof(hang) / sizeof(term));


	Transpose(hang, after, sizeof(hang) / sizeof(term));
	show(after, sizeof(after) / sizeof(term));
}

*/

/*
3단계 : 행, 열, 값으로 표현하는거 알겠습니다. 저는 이걸 행렬로 보고 싶습니다.
*/
/*
#include<stdio.h>
#include<malloc.h>

typedef struct {
	int row;
	int col;
	int value;
} term;


int main() {

	term hang[] = { {0, 2, 2}, {0, 6, 12}, {1, 4, 7}, {2, 0, 23}, {3,  3, 31},
	{4, 1, 14}, {4, 5, 25}, {5, 6, 6}, {6, 0, 52}, {7, 4, 11}
	};

	int len = sizeof(hang) / sizeof(term);
	int max_col = 0;
	int max_row = 0;

	for (int i = 0; i < len; i++) {
		if (max_col < hang[i].col)
			max_col = hang[i].col;
		if (max_row < hang[i].row)
			max_row = hang[i].row;
	}



	int** arr = NULL;
	arr = (int**)malloc(sizeof(int*) * max_row + 1);
	for (int i = 0; i < max_row + 1; i++) {
		arr[i] = (int*)malloc(sizeof(int) * max_col + 1);
	}


	for (int i = 0; i < max_col + 1; i++) {
		for (int j = 0; j < max_row + 1; j++) {
			arr[i][j] = 0;
		}
	}


	for (int i = 0; i < len; i++) {
		arr[hang[i].col][hang[i].row] = hang[i].value;
	}

	for (int i = 0; i < max_col + 1; i++) {
		for (int j = 0; j < max_row + 1; j++) {
			printf(" %d ", arr[i][j]);
		}
		printf("\n");
	}

}
*/

/*
4단계 : 그러면 이제 전치행렬을 행렬로 보여주세요. 함수로 분리
*/

#include<stdio.h>
#include<malloc.h>

typedef struct {
	int row;
	int col;
	int value;
} term;


int max_col_row(term hang[], int len, bool col_row) {
	int max = 0;
	if (col_row == true) {
		for (int i = 0; i < len; i++) {
			if (max < hang[i].col)
				max = hang[i].col;
		}
	}

	if (col_row == false) {
		for (int i = 0; i < len; i++) {
			if (max < hang[i].row)
				max = hang[i].row;
		}
	}
	return max;
}

void show_col_row(term a[], int len, int max_col, int max_row) {

	int** arr = NULL;
	arr = (int**)malloc(sizeof(int*) * max_row + 1);
	for (int i = 0; i < max_row + 1; i++) {
		arr[i] = (int*)malloc(sizeof(int) * max_col + 1);
	}


	for (int i = 0; i < max_col + 1; i++) {
		for (int j = 0; j < max_row + 1; j++) {
			arr[i][j] = 0;
		}
	}


	for (int i = 0; i < len; i++) {
		arr[a[i].col][a[i].row] = a[i].value;
	}


	for (int i = 0; i < max_col + 1; i++) {
		for (int j = 0; j < max_row + 1; j++) {
			printf(" %d\t", arr[i][j]);
		}
		printf("\n");
	}
}


void Transpose(term a[], term b[], int len) {
	for (int i = 0; i < len; i++) {
		b[i].row = a[i].col;
		b[i].col = a[i].row;
		b[i].value = a[i].value;
	}
}



int main() {

	term hang[] = { {0, 2, 2}, {0, 6, 12}, {1, 4, 7}, {2, 0, 23}, {3,  3, 31},
	{4, 1, 14}, {4, 5, 25}, {5, 6, 6}, {6, 0, 52}, {7, 4, 11}
	};

	term after[10] = { 0 };

	int len = sizeof(hang) / sizeof(term);
	int max_col = max_col_row(hang, len, true);
	int max_row = max_col_row(hang, len, false);

	show_col_row(hang, len, max_col, max_row);
	printf("\n전치를 진행 합니다. \n\n");
	Transpose(hang, after, len);
	show_col_row(after, len, max_col, max_row);
}