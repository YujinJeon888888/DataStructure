//���Ŀ� ������ �ʿ��ϸ� ���⸸ �����Ͽ� ���δ�
//=========�����ڵ����=========
#define MAX_STACK_SIZE 100

typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;


//���� �ʱ�ȭ �Լ�
void init_stack(StackType* s) {
	s->top = -1;
}

//���� ���� ���� �Լ�
int is_empty(StackType* s) {
	return (s->top == -1);
}

//��ȭ ���� ���� �Լ�
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));//-1: 0���� �����ϴϱ�. 
}

//���� �Լ�
void push(StackType* s, element item) {
	if (is_full(&s)) {
		printf("���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;//1) ������ �ε���(==ž)�� �ø��� ����, 2) �������� �����Ѵ�.
}

//���� �Լ�
element pop(StackType* s) {
	if (is_empty(s)) {
		printf("���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];

}

//��ũ �Լ�
element peek(StackType* s) {
	if (is_empty(s)) {
		printf("���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}

//==============���� �ڵ��� ��==============

