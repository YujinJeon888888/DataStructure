#include <stdio.h>

int main()
{
	char* str;
	str = "Fryends";
	*(str + 2) = 'i';
	printf("%s ", str);
	return 0;
}
