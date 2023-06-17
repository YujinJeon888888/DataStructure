//#include <stdio.h> 
//
//#define MAX_STACK_SIZE 100
//
//typedef int element;
//element stack[MAX_STACK_SIZE];
//int top = -1;//-1을 가리키는 것 주의!!
//
////공백 상태 검출 함수
//int is_empty() {
//	return (top == -1);//top이 -1을 가리키면, 참을(1을) 리턴하라.
//}
//
////포화 상태 검출 함수
//int is_full() {
//	return (top == (MAX_STACK_SIZE - 1));//-1을 주의하자. 배열사이즈니까 -1.
//}
//
////삽입 함수
//void push(element item) {
//	if (is_full()) {
//		printf("포화에러\n");
//		return;
//	}
//	else stack[++top] = item;//먼저 1)탑 올리고, 2)아이템 삽입
//}
//
////삭제 함수
//element pop() {
//	if (is_empty()) {
//		printf("비었습니다.\n");
//		exit(1);
//	}
//	else return stack[top--];//먼저 1)리턴하고, 2)아이템 지우기
//	
//}
//
////피크 함수
//element peek() {
//	if (is_empty()) {
//		printf("비었습니다.\n");
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