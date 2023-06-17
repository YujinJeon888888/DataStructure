//#include <stdio.h>
//#define MAX_STACK_SIZE 100
//typedef int element;
//typedef struct {
//	element data[MAX_STACK_SIZE];
//	int top;
//}StackType;
//
////스택 초기화 함수
//void init_stack(StackType* s) {//포인터 중요. 왜냐면 그 주소에 있는 값을 다뤄야 하니까/
//								//모든 연산은 구조체의 포인터를 받는다.
//	s->top = -1;
//}
//
////공백 상태 검출 함수
//int is_empty(StackType* s) {
//	return (s->top == -1);
//}
//
////포화 상태 검출 함수
//int is_full(StackType* s) {
//	return (s->top == (MAX_STACK_SIZE - 1));
//}
//
//void push(StackType* s, element item) {
//	if (is_full(&s)) {
//		printf("스택 포화");
//		return;
//	}
//	else
//		s->data[++(s->top)] = item;
//}
//
//element pop(StackType* s) {
//	if (is_empty(&s)) {
//		printf("비었음");
//		exit(1);
//	}
//	else return s->data[s->top--];
//	
//}
//
//int main() {
//
//	StackType s;
//	init_stack(&s);
//	push(&s, 1);
//	push(&s, 2);
//	push(&s, 3);
//	printf("%d\n", pop(&s));
//	printf("%d\n", pop(&s));
//	printf("%d\n", pop(&s));
//}