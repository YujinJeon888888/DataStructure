#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100
//0을 제외하고, (공간절약위해)
typedef struct {
	int row;
	int col;
	int value;//어디 행 어디 열에 어느 값이 있다. 
}element;

typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows;//총 행의개수
	int cols;//총 열의개수
	int terms;//총 항의개수
}SparseMatrix;

SparseMatrix matrix_transpose2(SparseMatrix a) {
	SparseMatrix b;

	int bindex;//행렬 b에서 현재 저장 위치
	b.rows = a.cols;
	b.cols = a.rows;
	b.terms = a.terms;

	if (a.terms > 0) {
		bindex = 0;
		for (int c = 0; c < a.cols; c++) {//a의 총 열만큼
			for (int i = 0; i < a.terms; i++) {//a의 총 항만큼
				if (a.data[i].col == c) {//a의 열 옮겨가면서
					b.data[bindex].row = a.data[i].col;//b의 행에다가 a의 열 넣음
					b.data[bindex].col = a.data[i].row;//b의 열에다가 a의 행 넣음
					b.data[bindex].value = a.data[i].value;//b의 값에다가 a의 값 넣음
					bindex++;//b의 항 ++
				}
			}
		}
	}
	return b;
}

void matrix_print(SparseMatrix a) {
	printf("===========\n");
	for (int i = 0; i < a.terms; i++) {
		printf("(%d,%d,%d) \n", a.data[i].row, a.data[i].col, a.data[i].value);
	}
	printf("===========\n");
}

int main() {
	SparseMatrix m = {
		{{0,3,7},{1,0,9},{1,5,8},{3,0,6},{3,1,5},{4,5,1},{5,2,2}},6,6,7
	};
	SparseMatrix result;
	result = matrix_transpose2(m);
	matrix_print(result);


	return 0;
}