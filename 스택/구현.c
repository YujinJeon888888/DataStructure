//#include <stdio.h> 
//
//#define MAX_STACK_SIZE 100
//
//typedef int element;
//element stack[MAX_STACK_SIZE];
//int top = -1;//-1�� ����Ű�� �� ����!!
//
////���� ���� ���� �Լ�
//int is_empty() {
//	return (top == -1);//top�� -1�� ����Ű��, ����(1��) �����϶�.
//}
//
////��ȭ ���� ���� �Լ�
//int is_full() {
//	return (top == (MAX_STACK_SIZE - 1));//-1�� ��������. �迭������ϱ� -1.
//}
//
////���� �Լ�
//void push(element item) {
//	if (is_full()) {
//		printf("��ȭ����\n");
//		return;
//	}
//	else stack[++top] = item;//���� 1)ž �ø���, 2)������ ����
//}
//
////���� �Լ�
//element pop() {
//	if (is_empty()) {
//		printf("������ϴ�.\n");
//		exit(1);
//	}
//	else return stack[top--];//���� 1)�����ϰ�, 2)������ �����
//	
//}
//
////��ũ �Լ�
//element peek() {
//	if (is_empty()) {
//		printf("������ϴ�.\n");
//		exit(1);
//	}
//	else return stack[top];
//}
//
//int main() {
//	push(1);
//	push(2);
//	push(3);
//	printf("%d\n", pop());
//	printf("%d\n", pop());
//	printf("%d\n", pop());
//
//	return 0;
//}