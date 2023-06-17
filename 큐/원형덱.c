#include <stdio.h>

//=======�� �ڵ� ����==========
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}DequeType;

//���� �Լ�
void error(char* message) {
	printf("%s\n", message);
	exit(1);
}

//�ʱ�ȭ
void init_deque(DequeType* q) {
	q->front = q->rear= 0;
}

//���� ���� ���� �Լ�
int is_empty(DequeType* q) {
	return q->front == q->rear;
}

//��ȭ ���� ���� �Լ�
int is_full(DequeType* q) {
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

//����ť ��� �Լ�
void deque_print(DequeType* q) {
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(&q)) {
		int i = q->front;
		do {
			//�ϴ� 1 �߰��ϰ� ����. front�� �� �� ���� ���� ����Ű�ϱ�
			i = (i + 1) % (MAX_QUEUE_SIZE);//�ְ��ε����� ��� ����ؼ�, 0,1,2,3,4,0,1,2,3,4 �ݺ��ǰ�
			printf("%d | ", q->data[i]);
			if (i == q->rear)//���� ������
				break;
		} while (i != q->front);//�ٽ� �ǵ��ƿ��� ��.
	}
	printf("\n");
}

//���� �Լ�
void arr_rear(DequeType* q, element item) {
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;//���� �ε��� ���� ��Ű��
	q->data[q->rear] = item;
}

//���� �Լ�
element delete_front(DequeType* q) {
	if (is_empty(q)) {
		error("ť�� ��������Դϴ�.");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;//�ε��� ���� ������Ű��
	return q->data[q->front];//�� ������ ����
}

//�� �� �� ��������
element get_front(DequeType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

//�� �տ� �߰��ϱ�
void add_front(DequeType* q, element val) {
	if (is_full(q))
		error(" ť�� ��ȭ�����Դϴ�.");
	q->data[q->front] = val;//�ϴ� �� �ְ�
	//q->front - 1 + MAX_QUEUE_SIZE:  �ڷ� �����ϱ� -1, ������ �� ������ +MAX
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;//�ڷ� ������
}

element delete_rear(DequeType* q) {
	int prev = q->rear;//������ �� �����س���(rear �ٲ�� ����)
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;//�ϴ� �ڷ� ������
	return q->data[prev];//������ �� �����ϱ�
}

element get_rear(DequeType *q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	return q->data[q->rear];
}

//=========�� �ڵ� ��=========
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