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
//
//ListNode* concat_list(ListNode* head1, ListNode* head2) {
//	if (head1 == NULL) return head2;//������ �� ������ head2�� ����
//	else if (head2 == NULL) return head1;//������ �� ������ head1�� ����
//	else {
//		ListNode* p;
//		p = head1;
//		while (p->link != NULL)
//			p = p->link;//���� ���� ��
//		p->link = head2;//�� ������ �� ����, �� �� ����� ��ũ�ʵ忡 head2����(����Ϸ�)
//		return head1;
//	}
//		
//}
//
////�׽�Ʈ ���α׷�
//int main() {
//	ListNode* head1=NULL;
//	ListNode* head2 = NULL;
//
//	head1 = insert_first(head1, 10);
//	head1 = insert_first(head1, 20);
//	head1 = insert_first(head1, 30);
//	print_list(head1);
//
//	head2 = insert_first(head2, 40);
//	head2 = insert_first(head2, 50);
//	print_list(head2);
//
//	ListNode* total = concat_list(head1, head2);
//	print_list(total);
//
//	return 0;
//}