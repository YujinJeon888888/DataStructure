//#include <stdio.h> 
////========����ť �ڵ� ����========
//#define MAX_QUEUE_SIZE 5
//
//typedef int element;
//typedef struct {
//	element data[MAX_QUEUE_SIZE];
//	int front, rear;
//}QueueType;
//
////���� �Լ�
//void error(char* message) {
//	printf("%s\n", message);
//	exit(1);
//}
//
////�ʱ�ȭ �Լ�
//void init_queue(QueueType* q) {
//	q->front = q->rear = 0;//�����̴ϱ� -1 ����->0����
//}
//
////���� ���� ���� �Լ�
//int is_empty(QueueType* q) {
//	return (q->front == q->rear);
//}
//
////��ȭ ���� ���� �Լ�
//int is_full(QueueType* q) {
//	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
//}
//
////����ť ��� �Լ�
//void queue_print(QueueType* q) {
//	printf("QUEUE(front=%d rear=%d)= ", q->front, q->rear);
//	if (!is_empty(&q)) {
//		int i = q->front;
//		do {
//			// front���� ������ rear�����ϱ� �ϴ� �ϳ� ������Ŵ
//			i = (i + 1) % MAX_QUEUE_SIZE;//�ε��� ������Ű��(����ť�ϱ� �̷��� ������Ű��)
//			printf("%d | ", q->data[i]);//�� �ε��� ���� ����ϰ�
//			if (i == q->rear)//���� �ε����� �� ���� ������
//				break;//�����(�� �����)
//		} while (i != q->front);//ó������ ���ƿ��� �����. (����)
//	}
//	printf("\n");
//}
//
////�����Լ�
//void enqueue(QueueType* q, element item) {
//	if (is_full(q))
//		error("ť�� ��ȭ�����Դϴ�.");//�� á���� �� �����ϱ�
//	//1.�ε��� ���� ������Ų��.
//	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;//����ť �ε��� ���� ���.( �ε������� �ʰ��ϸ� �ٽ� 0���� ���ƿ�����)
//	//2. �� ���� �����Ѵ�.
//	q->data[q->rear] = item;
//		
//}	
//
////���� �Լ�
//element dequeue(QueueType* q) {
//	if (is_empty(&q))
//		error("ť�� ��������Դϴ�.");
//	q->front = (q->front + 1) % MAX_QUEUE_SIZE;//�ε��� ������Ű��
//	return q->data[q->front];//�� �ε����� �� ��ȯ�Ѵ�.
//}
//
////��ũ �Լ�
//element peer(QueueType* q) {
//	if (is_empty(q)) {
//		error("ť�� ��������Դϴ�.");
//		return q->data[q->front + 1 % MAX_QUEUE_SIZE];
//	}
//}
//
////=========����ť �ڵ� ��===========
//
//int main() {
//	QueueType queue;
//	int element;
//
//	init_queue(&queue);
//	printf("--������ �߰� �ܰ�--\n");
//	while (!is_full(&queue)) {
//		printf("������ �Է��Ͻÿ�: ");
//		scanf_s("%d", &element);
//		enqueue(&queue, element);
//		queue_print(&queue);
//	}
//	printf("ť�� ��ȭ�����Դϴ�.\n\n");
//	
//	printf("--������ ���� �ܰ�--\n");
//	while (!is_empty(&queue)) {
//		element = dequeue(&queue);
//		printf("������ ����: %d\n", element);
//		queue_print(&queue);
//	}
//	printf("ť�� ��������Դϴ�.\n\n");
//
//	return 0;
//}