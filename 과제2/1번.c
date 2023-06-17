//#include <stdio.h>
//#include <stdlib.h>
//int i = 0, j = 0;
//
////연결리스트
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
////이중연결 리스트를 초기화
//void init(DListNode* phead, element data) {
//	phead->data = data;
//	phead->llink = phead;
//	phead->rlink = phead;
//}
//
////이중연결 리스트의 노드를 출력
//void print_dlist(DListNode* phead) {
//	DListNode* p = phead;
//	while (1) {
//		printf("<-| |%d| |-> ", p->data);//데이터출력
//		if (p->rlink == phead) {
//			break;
//		}
//		p = p->rlink;//옆으로이동
//	}
//	printf("\n");
//}
//
////새로운 데이터를 헤드의 왼쪽링크에 삽입한다. 
//void dinsert(DListNode* head, element data) {
//	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
//	newnode->data = data;
//	newnode->llink = head->llink;
//	newnode->rlink = head;
//	head->llink->rlink = newnode;
//	head->llink = newnode;
//}
//
////노드 removed를 삭제한다. 
//void ddelete(DListNode* head, DListNode* removed) {
//	if (removed == head) return;
//	removed->llink->rlink = removed->rlink;
//	removed->rlink->llink = removed->llink;
//	free(removed);
//}
//////////////////////////////////////
////이진트리
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
////중위순회
//void inorder(TreeNode* root) {
//	if (root != NULL) {
//		inorder(root->left);
//
//		if (i == 0) {//첫 번째 방문이면
//			head = (DListNode*)malloc(sizeof(DListNode));//헤드노드 생성
//			init(head, root->data);
//			i++;
//			j++;//노드갯수세기
//		}
//		else {//그 다음 방문부터는 
//			dinsert(head, root->data);//헤드노드에 데이터 삽입
//			j++;
//		}
//
//		inorder(root->right);
//	}
//}
//
////테스트 프로그램
//int main() {
//
//	printf("완전이진트리를 원형이중리스트로 \n");
//	inorder(root);
//	print_dlist(head);
//
//	//프리해주기
//	for (int i = 0; i < j; i++) {
//		ddelete(head, head->rlink);
//	}
//	free(head);
//
//	return 0;
//}