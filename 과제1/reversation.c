#include <stdio.h>
#define	SIZE 6

void reversestring(char str[]);
void swap(char* a, char* b);

int main() {
	char str[] ="TOMATO";

	printf("%s\n", str);
	reversestring(str);
	printf("%s\n", str);

	return 0;
}

void reversestring(char str[])
{
	
	for (int i = 0, j = SIZE-1; i < SIZE / 2; i++, j--) {
		swap(&str[i], &str[j]);
	}
	
}

void swap(char *a, char *b)
{
	char temp='\0';
	temp=*a;
	*a = *b ;
	*b = temp;
}
