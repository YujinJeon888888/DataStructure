//#include <stdio.h>
//#include <stdlib.h>
//int i = 0, j = 0;
//
////���Ḯ��Ʈ
//typedef int element;
//typedef struct DListNode {
//	element data;
//	struct DListNode* llink;
//	struct DListNode* rlink;
//
//}DListNode;
//
//DListNode* head;
//
////���߿��� ����Ʈ�� �ʱ�ȭ
//void init(DListNode* phead, element data) {
//	phead->data = data;
//	phead->llink = phead;
//	phead->rlink = phead;
//}
//
////���߿��� ����Ʈ�� ��带 ���
//void print_dlist(DListNode* phead) {
//	DListNode* p = phead;
//	while (1) {
//		printf("<-| |%d| |-> ", p->data);//���������
//		if (p->rlink == phead) {
//			break;
//		}
//		p = p->rlink;//�������̵�
//	}
//	printf("\n");
//}
//
////���ο� �����͸� ����� ���ʸ�ũ�� �����Ѵ�. 
//void dinsert(DListNode* head, element data) {
//	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
//	newnode->data = data;
//	newnode->llink = head->llink;
//	newnode->rlink = head;
//	head->llink->rlink = newnode;
//	head->llink = newnode;
//}
//
////��� removed�� �����Ѵ�. 
//void ddelete(DListNode* head, DListNode* removed) {
//	if (removed == head) return;
//	removed->llink->rlink = removed->rlink;
//	removed->rlink->llink = removed->llink;
//	free(removed);
//}
//////////////////////////////////////
////����Ʈ��
//typedef struct TreeNode {
//	int data;
//	struct TreeNode* left, * right;
//}TreeNode;
//
////		11
////	13		    16
////26  31	   37
//
//TreeNode n1 = { 26,NULL,NULL };
//TreeNode n2 = { 31, NULL,NULL };
//TreeNode n3 = { 13, &n1,&n2 };
//TreeNode n4 = { 37,NULL,NULL };
//TreeNode n5 = { 16, &n4, NULL };
//TreeNode n6 = { 11, &n3, &n5 };
//TreeNode* root = &n6;
//
////������ȸ
//void inorder(TreeNode* root) {
//	if (root != NULL) {
//		inorder(root->left);
//
//		if (i == 0) {//ù ��° �湮�̸�
//			head = (DListNode*)malloc(sizeof(DListNode));//����� ����
//			init(head, root->data);
//			i++;
//			j++;//��尹������
//		}
//		else {//�� ���� �湮���ʹ� 
//			dinsert(head, root->data);//����忡 ������ ����
//			j++;
//		}
//
//		inorder(root->right);
//	}
//}
//
////�׽�Ʈ ���α׷�
//int main() {
//
//	printf("��������Ʈ���� �������߸���Ʈ�� \n");
//	inorder(root);
//	print_dlist(head);
//
//	//�������ֱ�
//	for (int i = 0; i < j; i++) {
//		ddelete(head, head->rlink);
//	}
//	free(head);
//
//	return 0;
//}