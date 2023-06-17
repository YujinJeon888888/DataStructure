#include <stdio.h>

int sub(int n) {
	if (n < 0) return 0;
	return n + sub(n - 3);
}

int main_1() {
	printf("순환: %d\n", sub(10));
	
	
	int i = 10;
	int sum = 0;
	while (i > 0) {
		sum += i;
		i -= 3;
	}
	printf("반복: %d", sum);

	return 0;
}

