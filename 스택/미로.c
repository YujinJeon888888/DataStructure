#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAZE_SIZE 6

//차후에 스택이 필요하면 여기만 복사하여 붙인다
//=========스택코드시작=========
#define MAX_STACK_SIZE 100

typedef struct {
	short r;
	short c;
}element;

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


element here = { 1,0 };
element entry = { 1,0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'}
};

//위치를 스택에 삽입
void push_loc(StackType* s, int r, int c) {
	if (r < 0 || c < 0) return;//인덱스범위 아니면
	if (maze[r][c] != '1' && maze[r][c] != '.') {//갈 수 있는 곳이면
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

//미로를 화면에 출력한다
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]) {
	printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++) {
		for (int c = 0; c < MAZE_SIZE; c++) {
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}
}

int main() {
	int r, c;
	StackType s;

	init_stack(&s);//스택 초기화
	here = entry;
	while (maze[here.r][here.c] != 'x')//출구에 나가기 전까지
	{
		r = here.r;
		c = here.c;
		maze[r][c] = '.';//간 곳은 '.'으로 표시
		maze_print(maze);
		//상하좌우 다 넣어보기
		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);
		if (is_empty(&s)) {
			printf("실패");
			return;
		}
		else
			here = pop(&s);
	}

	printf(" 성공! \n");
	return 0;
}