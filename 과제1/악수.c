#include <stdio.h>

int �Ǽ�(int n) {
	if (n == 1) return 0;
	
	return (n-1)+�Ǽ�(n-1);//���� n-1: ���� �ְ� �Ǽ��ϴ� ��� �� , �Ǽ�(n-1): �� ������� �Ǽ� �佺
}

int main_2() {
	
	printf("5���� �Ǽ� �� Ƚ��: %d", �Ǽ�(5));

	return 0;
}