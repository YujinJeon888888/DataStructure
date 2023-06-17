#include <stdio.h> 
struct studentTag {
	char name[10];
	int age;
	double gpa;
}student;//typedef: 데이터타입을 내가 새로 define 하겠단 뜻



int main_s() {
	student a={"kim",18,3.2};
	student b={"hi",33,1.2};
	
	return 0;
}