//#include <stdio.h> 
//#include <malloc.h>
//typedef int element;
//typedef struct {
//	element data;
//	struct ListNode* link;//�ڱ���������ü
//}ListNode;
//
//
////���� ó�� �Լ�
//void error(char* message) {
//	printf("%s\n", message);
//	exit(1);
//}
//
//ListNode* insert_first(ListNode* head, element value) {
//	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
//	p->data = value;
//	p->link = head;//head ��带 ����Ű����
//	head = p;//���� head�� p��.
//	return head;// head�� ������: �������� ListNode*. �׻� ���� ���������� ����Ŵ. 
//}
//
////��� pre �ڿ� ���ο� ��� ����
//ListNode* insert(ListNode* head, ListNode* pre, element value)//�׻� ��� �ʿ�. ��� �����ؾ� �ϴϱ�
//{
//	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
//	p->data = value;
//	p->link = pre->link;
//	pre->link = p;
//	return head;
//}
//
//ListNode* delete_first(ListNode* head) {
//	ListNode* removed;
//	if (head == NULL) {
//		return NULL;
//	}
//	removed = head;
//	head = removed->link;//��带 ������-> �� �� ��尡 ��尡 ��-> ��帵ũ�� �޾Ƽ� �� �� ��尡 ��尡 �ǵ���.
//	free(removed);//�� free���ֱ�
//
//}
//
////pre�� ����Ű�� ����� ���� ��带 �����Ѵ�.
//ListNode* delete(ListNode* head, ListNode* pre) {
//	ListNode* removed;
//	removed = pre->link;//������ ��ũ�ʵ�� ������ ��带 ����Ŵ. 
//	pre->link = removed->link;//�� ���Ƴ���
//	free(removed);
//	return head;
//
//}
//
//void print_list(ListNode* head) {
//	for (ListNode* p = head; p != NULL; p = p->link) {//���� ���� �Ѿ
//		printf("%d->", p->data);
//	 }
//	printf("NULL \n");
//}
////=============���Ḯ��Ʈ ��=============
//ListNode* search_list(ListNode* head, element x) {
//	ListNode* p = head;//head�� �� ��ü ��带 ����.
//	//���� ��� ��� ������ �� ����� ����: ��� ��ü�� ������ �����ϴ� ���� ����.
//	while (p != NULL) {
//		//���� ���� �˻��ϴ� ����: ��尪���� �ٷ� ã�� �� �����ϱ�
//		if (p->data == x) {//�� ã����
//			return p;
//		}
//		p = p->link;//���� ���� �Űܰ���
//	}
//	return NULL;//Ž�� ����. �� ���Ϲ����� �� �ɸ��� Ž�� ������ ����
//}
//
////�׽�Ʈ ���α׷�
//int main() {
//	ListNode* head=NULL;//�׻� �η� �ʱ�ȭ. �����Ⱚ ���� �� ����
//	head = insert_first(head, 10);//��忡 10 �ִ´�. ��� ��� �����µ� ��� ����->�� ó���� insert_first��
//	print_list(head);
//	head = insert_first(head, 20);
//	print_list(head);
//	head = insert_first(head, 30);
//	print_list(head);
//	if (search_list(head, 30) != NULL) {
//		printf("����Ʈ���� 30�� ã�ҽ��ϴ�.\n");
//	}
//	else
//		printf("����Ʈ���� 30�� ã�� ���߽��ϴ�.\n");
//
//
//	return 0;
//}