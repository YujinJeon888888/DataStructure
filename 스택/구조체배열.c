//#include <stdio.h>
//#define MAX_STACK_SIZE 100
//typedef int element;
//typedef struct {
//	element data[MAX_STACK_SIZE];
//	int top;
//}StackType;
//
////���� �ʱ�ȭ �Լ�
//void init_stack(StackType* s) {//������ �߿�. �ֳĸ� �� �ּҿ� �ִ� ���� �ٷ�� �ϴϱ�/
//								//��� ������ ����ü�� �����͸� �޴´�.
//	s->top = -1;
//}
//
////���� ���� ���� �Լ�
//int is_empty(StackType* s) {
//	return (s->top == -1);
//}
//
////��ȭ ���� ���� �Լ�
//int is_full(StackType* s) {
//	return (s->top == (MAX_STACK_SIZE - 1));
//}
//
//void push(StackType* s, element item) {
//	if (is_full(&s)) {
//		printf("���� ��ȭ");
//		return;
//	}
//	else
//		s->data[++(s->top)] = item;
//}
//
//element pop(StackType* s) {
//	if (is_empty(&s)) {
//		printf("�����");
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