#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
//typedef struct studentTag {
//	char name[10];
//	int age;
//	double gpa;
//}student;
//
//int main() {
//	student* s;
//	s = (student*)malloc(sizeof(student));
//
//	if (s == NULL) {
//		fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
//		exit(1);
//	}
//
//	strcpy(s->name, "Park");
//	s->age = 20;
//
//	free(s);
//
//	struct
//	{
//		char name[10];
//		int age;
//		float 월급;
//	}person;
//
//	return 0;
//}

typedef struct {
    float real;
    float imaginary;
} complex;

int main(void) {
    complex c1 ={2.3,3.2};
    complex c2 ;

    return 0;
}
