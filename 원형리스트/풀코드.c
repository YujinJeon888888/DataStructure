#include <stdio.h> 
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

//����Ʈ�� �׸� ���
void print_list(ListNode* last) {
	ListNode* p;
	if (last == NULL) return;//�ƹ��͵� ������ ����
	p = last->link;// last->link: head
	do {
		printf("%d->", p->data);//������ ���
		p = p->link;//������ �̵�
	} while (p != last);//last ������ ������. 
	printf("%d->", p->data);//last�� �����ͱ��� ����ϰ� ����. 
}

ListNode* insert_first(ListNode* last, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));//�����Ҵ�
	node->data = data;//���ο� ��忡 ���ڷ� ���� ������ �� �ִ´�. 
	if (last == NULL) {//�ƹ� ��嵵 ������
		last = node;//���ο� ��尡 ������ ��尡 ��
		node->link = last;//���Ϲ����� ���->��尡 �ڱ� �ڽ��� ����Ŵ->������� ��Ʈ�� ���Ϲ��� ���
	}
	else {//�ٸ� ��� �ִ� ���¸�
		node->link = last->link;//���ο� ���� ��带 ����Ų��. 
		last->link = node;//���� ���ο� ��尡 �ȴ�. 
	}
	return last;//last��带 �����Ѵ�. 
}

ListNode* insert_last(ListNode* last, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));//�����Ҵ�
	node->data = data;//���ο� ��� �����Ϳ� ���� �� �ִ´�. 
	if (last == NULL) {//�ƹ��͵�������
		last = node;//���ο���==last;
		node->link = last;//���ο���� �ڱ��ڽ��� ����Ų��. (���Ϲ��̳��)
	}
	else {//�� ������
		node->link = last->link;//���ο� ���� ��带 ����Ų��. 
		last->link = node;//��Ʈ��ũ�� ��带 ����Ų��.(���� ��Ʈ�� ��)
		last = node;//���� ��Ʈ�� ��
	}
	return last;//��Ʈ ����
}

//�������� ����Ʈ �׽�Ʈ ���α׷�
int main() {
	ListNode* last = NULL;//��Ʈ�� �η� �ʱ�ȭ�ϰ� ����.

	//list=10->20->30->40
	last = insert_last(last, 20);//��Ʈ�� ��� �־���
	last = insert_last(last, 30);
	last = insert_last(last, 40);
	last = insert_first(last, 10);//��忡 10 ����
	print_list(last);
	
	return 0;
}