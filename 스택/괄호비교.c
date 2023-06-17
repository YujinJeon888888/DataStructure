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
////스택 초기화 함수
//void init_stack(StackType* s) {//포인터 중요. 왜냐면 그 주소에 있는 값을 다뤄야 하니까/
//	//모든 연산은 구조체의 포인터를 받는다.
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
//int check_matching(const char* in) {
//	StackType s;
//	char ch, open_ch;
//	int i, n = strlen(in);//n:문자열의 길이
//	init_stack(&s);//스택 초기화
//
//	for (int i = 0; i < n; i++) {
//		ch = in[i];//ch: 다음문자
//		switch (ch)
//		{
//		case '(': case '{': case '[':
//			push(&s, ch);
//			break;
//		case ')': case '}': case ']':
//			if (is_empty(&s)) return 0;//스택이 비어있으면 오류
//			else {
//				open_ch = pop(&s);//open_ch: 꺼낸거
//				if ((open_ch == '(' && ch != ')') ||//짝이 안 맞으면 오류 리턴
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
//	if (!is_empty(&s)) return 0;//스택에 남아있으면 오류
//	return 1;//오류 안 걸리면 정상적으로 리턴.
//}
//
//int main() {
//	char* p = "{A[(i+1)]=0}";//배열이랑 같은 의미. 
//	if (check_matching(p) == 1)
//		printf("괄호검사성공!");
//	else
//		printf("괄호검사실패");
//
//	return 0;
//}