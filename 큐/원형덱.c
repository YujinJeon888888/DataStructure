#include <stdio.h>

//=======덱 코드 시작==========
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}DequeType;

//오류 함수
void error(char* message) {
	printf("%s\n", message);
	exit(1);
}

//초기화
void init_deque(DequeType* q) {
	q->front = q->rear= 0;
}

//공백 상태 검출 함수
int is_empty(DequeType* q) {
	return q->front == q->rear;
}

//포화 상태 검출 함수
int is_full(DequeType* q) {
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

//원형큐 출력 함수
void deque_print(DequeType* q) {
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(&q)) {
		int i = q->front;
		do {
			//일단 1 추가하고 시작. front는 맨 앞 수의 앞을 가리키니까
			i = (i + 1) % (MAX_QUEUE_SIZE);//최고인덱스일 경우 대비해서, 0,1,2,3,4,0,1,2,3,4 반복되게
			printf("%d | ", q->data[i]);
			if (i == q->rear)//끝을 만나면
				break;
		} while (i != q->front);//다시 되돌아오면 끝.
	}
	printf("\n");
}

//삽입 함수
void arr_rear(DequeType* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;//먼저 인덱스 증가 시키고
	q->data[q->rear] = item;
}

//삭제 함수
element delete_front(DequeType* q) {
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;//인덱스 먼저 증가시키고
	return q->data[q->front];//그 다음에 리턴
}

//맨 앞 값 가져오기
element get_front(DequeType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

//맨 앞에 추가하기
void add_front(DequeType* q, element val) {
	if (is_full(q))
		error(" 큐가 포화상태입니다.");
	q->data[q->front] = val;//일단 값 넣고
	//q->front - 1 + MAX_QUEUE_SIZE:  뒤로 빠지니까 -1, 음수될 수 있으니 +MAX
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;//뒤로 빠지기
}

element delete_rear(DequeType* q) {
	int prev = q->rear;//삭제할 값 저장해놓고(rear 바뀌기 전에)
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;//일단 뒤로 빠지고
	return q->data[prev];//삭제한 값 리턴하기
}

element get_rear(DequeType *q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[q->rear];
}

//=========덱 코드 끝=========
int main() {
	DequeType queue;

	init_deque(&queue);

	for (int i = 0; i < 3; i++) {
		add_front(&queue, i);
		deque_print(&queue);
	}
	for (int i = 0; i < 3; i++) {
		delete_rear(&queue);
		deque_print(&queue); 
	}

	return 0;
}