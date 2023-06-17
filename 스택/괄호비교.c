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
//
//int check_matching(const char* in) {
//	StackType s;
//	char ch, open_ch;
//	int i, n = strlen(in);//n:���ڿ��� ����
//	init_stack(&s);//���� �ʱ�ȭ
//
//	for (int i = 0; i < n; i++) {
//		ch = in[i];//ch: ��������
//		switch (ch)
//		{
//		case '(': case '{': case '[':
//			push(&s, ch);
//			break;
//		case ')': case '}': case ']':
//			if (is_empty(&s)) return 0;//������ ��������� ����
//			else {
//				open_ch = pop(&s);//open_ch: ������
//				if ((open_ch == '(' && ch != ')') ||//¦�� �� ������ ���� ����
//					(open_ch == '[' && ch != ']') ||
//					(open_ch == '{' && ch != '}')) {
//					return 0;
//				}
//				break;
//			}
//				
//			
//		}
//	}
//	if (!is_empty(&s)) return 0;//���ÿ� ���������� ����
//	return 1;//���� �� �ɸ��� ���������� ����.
//}
//
//int main() {
//	char* p = "{A[(i+1)]=0}";//�迭�̶� ���� �ǹ�. 
//	if (check_matching(p) == 1)
//		printf("��ȣ�˻缺��!");
//	else
//		printf("��ȣ�˻����");
//
//	return 0;
//}