//#include <stdio.h>
//#include <malloc.h>
//
//#define SIZE 10
//int main() {
//	int* p;
//
//	p = (int*)malloc(SIZE * sizeof(int));//반환형: void*=>int*로 형변환., 인자는 필요한 공간만큼
//	if (p == NULL) {
//		fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
//		exit(1);
//	}
//	for (int i = 0; i < SIZE; i++) {
//		p[i] = i;
//	}
//	for (int i = 0; i < SIZE; i++) {
//		printf("%d ", p[i]);
//	}
//	free(p);//다 쓰고나면 반납. 어디에 있는지를 알아야하기 때문에 p가 들어감. 주소를 잊어버려선 안된다.
//
//	return 0;
//}