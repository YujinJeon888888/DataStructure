//#include <stdio.h>
//#include <string.h>
//#define MAX_STACK_SIZE 100
//
//typedef char element;
//typedef struct {
//	element data[MAX_STACK_SIZE];
//	int top;
//}StackType;
//
////���� �ʱ�ȭ �Լ�
//void init_stack(StackType* s) {//������ �߿�. �ֳĸ� �� �ּҿ� �ִ� ���� �ٷ�� �ϴϱ�/
//	//��� ������ ����ü�� �����͸� �޴´�.
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
////�������� ��� �Լ�
//int eval(char exp[]) {
//	int op1, op2, value, i = 0;
//	int len = strlen(exp);
//	char ch;
//	StackType s;
//	
//	init_stack(&s);///�����ʱ�ȭ
//	for (i = 0; i < len; i++) {
//		ch = exp[i];
//		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
//			value = ch - '0'; //�Է��� �ǿ������̸�. ���ڸ� ���ڷ� �ٲٴ� ó��
//			push(&s, value);//�ǿ������̸� ���ÿ� �ִ´�.
//		}
//		else {//�������̸� �ǿ����ڸ� ���ÿ��� ����
//			op2 = pop(&s);//pop�� ����� �ִ´�.
//			op1 = pop(&s);
//			switch (ch)//������ �����ϰ� ���ÿ� ����
//			{
//			case '+': push(&s, op1 + op2); break;
//			case '-': push(&s, op1 - op2); break;
//			case '*': push(&s, op1 * op2); break;
//			case '/': push(&s, op1 / op2); break;
//			}
//		}
//	}
//	return pop(&s);//���������� pop�ؼ� ������� �Ѱ��ش�. 
//}
//
//int main() {
//	int result;
//	printf("���� ǥ����� 82/3-32*+\n");
//	result = eval("82/3-32*+");
//	printf("������� %d\n", result);
//
//	return 0;
//}