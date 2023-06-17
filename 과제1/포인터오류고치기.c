#include <stdio.h>

int main_3()
{
	char* str;
	char str2[] = "Fryends";
	str = &str2;
	*(str + 2) = 'i';
	printf("%s ", str);
	return 0;
}
