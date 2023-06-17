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
////연산자의 우선순위를 반환한다.
//int prec(char op) {
//	switch (op)
//	{
//	case'(':case')':return 0;//0: 무조건 우선순위 제일 높음
//	case '+':case'-':return 1;
//	case '*':case'/':return 2;//숫자가 더 높음: 우선순위 높음
//	}
//	return -1;
//}
//
////중위표기수식->후위표기수식
//void infix_to_postfix(char exp[]) {
//	int i = 0;
//	char ch, top_op;
//	int len = strlen(exp);
//	StackType s;
//
//	init_stack(&s);//스택초기화
//	for (i = 0; i < len; i++) {
//		ch = exp[i];
//		switch (ch)
//		{
//		case '+': case'-':case'*':case'/'://연산자
//			//스택에 있는 연산자의 우선수위가 더 크거나 같으면 출력
//			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
//				printf("%c", pop(&s));
//			push(&s, ch);
//			break;
//		case '('://왼쪽괄호면 집어 넣는다.
//			push(&s, ch);
//			break;
//		case ')'://오른쪽 괄호면 왼쪽 괄호 만날때까지 다 pop한다.
//			top_op = pop(&s);//오른쪽괄호 이전은 스택에 피연산자가 쌓여있을 것임. 
//			//왼쪽괄호를 만날때까지 출력
//			while (top_op != '(') {
//				printf("%c", top_op);
//				top_op = pop(&s);
//			}
//			break;
//
//		default://피연산자
//			printf("%c", ch);
//			break;
//		}
//	}
//	while (!is_empty(&s))//스택에 저장된 연산자들 출력
//		printf("%c", pop(&s));
//}
//
//int main() {
//	char* s = "(2+3)*4+9";//배열
//	printf("중위표시수식 %s \n", s);
//	printf("후위표시수식 ");
//	infix_to_postfix(s);
//	printf("\n");
//
//	return 0;
//}