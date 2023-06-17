//
//
//#include <stdio.h>
//#include <stdlib.h>
////==================선형큐 시작==================
//#define MAX_QUEUE_SIZE 5
//
//typedef int element;
//
//typedef struct {//큐 타입
//	int front;//앞 화살표
//	int rear;//꼬랑지 화살표
//	element data[MAX_QUEUE_SIZE];//배열
//}QueueType;
//
////오류 함수
//void error(char* message) {
//	printf("%s\n", message);
//	exit(1);
//}
//
//void init_queue(QueueType* q) {
//	q->rear = -1;
//	q->front = -1;
//}
//
//void queue_print(QueueType* q) {
//	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
//		if (i <= q->front || i > q->rear)
//		{
//			printf(" | ");//요소없으면
//		}
//		else
//			printf("%d |", q->data[i]);//요소있으면
//	}
//	printf("\n");
//}
//
//int is_full(QueueType* q) {
//	if (q->rear == MAX_QUEUE_SIZE - 1) {
//		return 1;//인덱스 최고범위를 꼬랑지가 가리키면: 다 찬 거임
//	}
//	else
//		return 0;
//}
//
//int is_empty(QueueType* q) {
//	if (q->front == q->rear) {
//		return 1;//둘이 같다는 것은, 비어있다는 뜻.
//	}
//	else
//		return 0;
//}
//
//void enqueue(QueueType* q, int item) {
//	if (is_full(q)) {//넣으려는데 다 차있으면 못 넣으니까
//		error("큐가 포화상태입니다.\n");
//		return;
//	}
//	q->data[++q->rear] = item;
//}
//
//int dequeue(QueueType* q) {
//	if (is_empty(q)) {
//		error("큐가 공백상태입니다.\n");
//		return -1;//int 리턴해야함: 공백상태면 -1
//	}
//	int item = q->data[++q->front];//front 에 있는 것 반환해야함. 근데 front -1이니까 일단 ++하고 
//	return item;
//}
//
////================선형큐 끝================
//
//int main() {
//	int item=0;
//	QueueType q;
//
//	init_queue(&q);//큐 초기화
//	queue_print(&q);
//
//	enqueue(&q, 10); queue_print(&q);
//	enqueue(&q, 20); queue_print(&q);
//	enqueue(&q, 30); queue_print(&q);
//
//	item = dequeue(&q); queue_print(&q);
//	item = dequeue(&q); queue_print(&q);
//	item = dequeue(&q); queue_print(&q);
//
//
//	return 0;
//}