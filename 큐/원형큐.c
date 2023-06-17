//#include <stdio.h> 
////========원형큐 코드 시작========
//#define MAX_QUEUE_SIZE 5
//
//typedef int element;
//typedef struct {
//	element data[MAX_QUEUE_SIZE];
//	int front, rear;
//}QueueType;
//
////오류 함수
//void error(char* message) {
//	printf("%s\n", message);
//	exit(1);
//}
//
////초기화 함수
//void init_queue(QueueType* q) {
//	q->front = q->rear = 0;//원형이니까 -1 없음->0부터
//}
//
////공백 상태 검출 함수
//int is_empty(QueueType* q) {
//	return (q->front == q->rear);
//}
//
////포화 상태 검출 함수
//int is_full(QueueType* q) {
//	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
//}
//
////원형큐 출력 함수
//void queue_print(QueueType* q) {
//	printf("QUEUE(front=%d rear=%d)= ", q->front, q->rear);
//	if (!is_empty(&q)) {
//		int i = q->front;
//		do {
//			// front앞의 수부터 rear까지니까 일단 하나 증가시킴
//			i = (i + 1) % MAX_QUEUE_SIZE;//인덱스 증가시키고(원형큐니까 이렇게 증가시키기)
//			printf("%d | ", q->data[i]);//그 인덱스 값을 출력하고
//			if (i == q->rear)//만약 인덱스가 끝 값을 만나면
//				break;//멈춘다(값 출력을)
//		} while (i != q->front);//처음으로 돌아오면 멈춘다. (원형)
//	}
//	printf("\n");
//}
//
////삽입함수
//void enqueue(QueueType* q, element item) {
//	if (is_full(q))
//		error("큐가 포화상태입니다.");//다 찼으면 못 넣으니까
//	//1.인덱스 먼저 증가시킨다.
//	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;//원형큐 인덱스 증가 방법.( 인덱스범위 초과하면 다시 0으로 돌아오도록)
//	//2. 그 다음 삽입한다.
//	q->data[q->rear] = item;
//		
//}	
//
////삭제 함수
//element dequeue(QueueType* q) {
//	if (is_empty(&q))
//		error("큐가 공백상태입니다.");
//	q->front = (q->front + 1) % MAX_QUEUE_SIZE;//인덱스 증가시키고
//	return q->data[q->front];//그 인덱스의 값 반환한다.
//}
//
////피크 함수
//element peer(QueueType* q) {
//	if (is_empty(q)) {
//		error("큐가 공백상태입니다.");
//		return q->data[q->front + 1 % MAX_QUEUE_SIZE];
//	}
//}
//
////=========원형큐 코드 끝===========
//
//int main() {
//	QueueType queue;
//	int element;
//
//	init_queue(&queue);
//	printf("--데이터 추가 단계--\n");
//	while (!is_full(&queue)) {
//		printf("정수를 입력하시오: ");
//		scanf_s("%d", &element);
//		enqueue(&queue, element);
//		queue_print(&queue);
//	}
//	printf("큐는 포화상태입니다.\n\n");
//	
//	printf("--데이터 삭제 단계--\n");
//	while (!is_empty(&queue)) {
//		element = dequeue(&queue);
//		printf("꺼내진 정수: %d\n", element);
//		queue_print(&queue);
//	}
//	printf("큐는 공백상태입니다.\n\n");
//
//	return 0;
//}