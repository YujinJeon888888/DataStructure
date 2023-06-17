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
////후위수식 계산 함수
//int eval(char exp[]) {
//	int op1, op2, value, i = 0;
//	int len = strlen(exp);
//	char ch;
//	StackType s;
//	
//	init_stack(&s);///스택초기화
//	for (i = 0; i < len; i++) {
//		ch = exp[i];
//		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
//			value = ch - '0'; //입력이 피연산자이면. 문자를 숫자로 바꾸는 처리
//			push(&s, value);//피연산자이면 스택에 넣는다.
//		}
//		else {//연산자이면 피연산자를 스택에서 제거
//			op2 = pop(&s);//pop한 결과를 넣는다.
//			op1 = pop(&s);
//			switch (ch)//연산을 수행하고 스택에 저장
//			{
//			case '+': push(&s, op1 + op2); break;
//			case '-': push(&s, op1 - op2); break;
//			case '*': push(&s, op1 * op2); break;
//			case '/': push(&s, op1 / op2); break;
//			}
//		}
//	}
//	return pop(&s);//연산결과값을 pop해서 결과값을 넘겨준다. 
//}
//
//int main() {
//	int result;
//	printf("후위 표기식은 82/3-32*+\n");
//	result = eval("82/3-32*+");
//	printf("결과값은 %d\n", result);
//
//	return 0;
//}