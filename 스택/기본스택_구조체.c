//차후에 스택이 필요하면 여기만 복사하여 붙인다
//=========스택코드시작=========
#define MAX_STACK_SIZE 100

typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;


//스택 초기화 함수
void init_stack(StackType* s) {
	s->top = -1;
}

//공백 상태 검출 함수
int is_empty(StackType* s) {
	return (s->top == -1);
}

//포화 상태 검출 함수
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));//-1: 0부터 시작하니까. 
}

//삽입 함수
void push(StackType* s, element item) {
	if (is_full(&s)) {
		printf("스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;//1) 데이터 인덱스(==탑)을 올리고 나서, 2) 아이템을 삽입한다.
}

//삭제 함수
element pop(StackType* s) {
	if (is_empty(s)) {
		printf("스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];

}

//피크 함수
element peek(StackType* s) {
	if (is_empty(s)) {
		printf("스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

//==============스택 코드의 끝==============

