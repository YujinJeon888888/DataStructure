#include <stdio.h>

int 學熱(int n) {
	if (n == 1) return 0;
	
	return (n-1)+學熱(n-1);//擅曖 n-1: 嫡擎 擁陛 學熱ж朝 餌塋 熱 , 學熱(n-1): 蕙 餌塋縑啪 學熱 饜蝶
}

int main_2() {
	
	printf("5貲郭葬 學熱 識 �蝦�: %d", 學熱(5));

	return 0;
}