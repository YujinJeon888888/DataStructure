#include <stdio.h>
power(int x, int n) {
	printf("гоюл\n");
	if (n == 0) return 1;
	else if (n % 2 == 0) {
		return power(x * x, n / 2);
	}
	else return x * power(x * x, (n - 1) / 2);
}
int main() {

	power(2, 5);
	return 0;
}