//#define SIZE 8
//#define MAX_ELEMENT 200
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct {
//	int key;
//}element;
//
//typedef struct {
//	element heap[MAX_ELEMENT];
//	int heap_size;
//}HeapType;
//
////�����Լ�
//HeapType* create() {
//	return (HeapType*)malloc(sizeof(HeapType));
//}
//
////�ʱ�ȭ�Լ�
//void init(HeapType* h) {
//	h->heap_size = 0;
//}
//
////���� ����� ������ heap_size�� ���� h�� item�� �����Ѵ�.
////���� �Լ�
//void insert_max_heap(HeapType* h, element item) {
//	int i;
//	i = ++(h->heap_size);
//
//	//Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
//	while ((i != 1) && (item.key > h->heap[i / 2].key))
//	{
//		h->heap[i] = h->heap[i / 2];//�θ��带 �������.
//		i /= 2;
//	}
//	h->heap[i] = item;//���ο� ��带 �� �ڸ��� ����
//}
//
////�����Լ�
////�ִ��������� ��������: �ִ밪�� ���� ��Ҹ� �����ϴ� ��
////�ִ밪: ��Ʈ���
//element delete_max_heap(HeapType* h) {
//	int parent, child;
//	element item, temp;
//
//	item = h->heap[1];//��Ʈ������
//
//	//��Ʈ��� ���� �� �籸�� �ʿ�
//	//�� ��Ʈ��� �ڸ����� ������ ������ ��带 �����´�
//	//���ο� ��Ʈ�� �ڽ� ��带 ���� ��ȯ�Ѵ�. (�ڽ� �� �� ū ���� ��ȯ)
//	temp = h->heap[(h->heap_size)--];
//	parent = 1;
//	child = 2;//���� �ڽĺ��� ��
//
//	while (child <= h->heap_size) {//��ȿ ���������
//		//���� ����� �ڽĳ�� �� �� ū �ڽ� ��带 ã�´�.
//		if ((child < h->heap_size) &&
//			(h->heap[child].key) < h->heap[child + 1].key)
//			child++;
//		if (temp.key >= h->heap[child].key) break;
//		//�� �ܰ� �Ʒ��� �̵�
//		h->heap[parent] = h->heap[child];//�ڽ� ���� �θ�� ����ø���.
//		parent = child;
//		child *= 2;
//	}
//	h->heap[parent] = temp;//��ȯ
//	return item;
//}
//
//////////////////////////////////////////
//
////�켱���� ť�� ������ �̿��� ����
//void heap_sort(element a[], int n) {
//	int i;
//	HeapType* h;
//
//	h = create();
//
//	init(h);
//	for (i = 0; i < n; i++) {//�迭������ŭ
//		insert_max_heap(h, a[i]);//�� h�� �迭��� �߰�
//	}
//	for (i = (n - 1); i >= 0; i--) {//�ε��� �Ųٷ� ������.==��������
//		a[i] = delete_max_heap(h);
//	}
//	free(h);
//}
//
//int main() {
//	element Arr[] = { 3, 5, 9, 6, 8, 20, 10, 12, 18, 9 };
//	element e;
//	HeapType* heap;
//	heap = create();//������
//	init(heap);//�ʱ�ȭ
//
//	//�迭 ������ ���ؾ��Ѵ�.
//	int size = sizeof(Arr) / sizeof(int);
//
//	//�� ������� ���� ����
//	for (int i = 0; i < size; i++) {
//		insert_max_heap(heap, (Arr[i]));//�ƽ� ������ �ٲ��.
//		//printf("%d ", Arr[i].key);//�������� ������ ��
//	}
//
//	printf("\n\n");
//	for (int i = 0; i < size; i++) {
//		e = delete_max_heap(heap);//�ƽ����̾ ���������� ������ ������� ��µ�
//		printf("< %d > ", e.key);
//	}
//
//	return 0;
//}
//
