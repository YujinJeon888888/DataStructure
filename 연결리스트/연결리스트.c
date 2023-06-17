//#include <stdio.h> 
//#include <malloc.h>
//typedef int element;
//typedef struct {
//	element data;
//	struct ListNode* link;//자기참조구조체
//}ListNode;
//
//
////오류 처리 함수
//void error(char* message) {
//	printf("%s\n", message);
//	exit(1);
//}
//
//ListNode* insert_first(ListNode* head, element value) {
//	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
//	p->data = value;
//	p->link = head;//head 노드를 가리키도록
//	head = p;//이제 head는 p임.
//	return head;// head를 리턴함: 리턴형은 ListNode*. 항상 노드는 참조변수가 가리킴. 
//}
//
////노드 pre 뒤에 새로운 노드 삽입
//ListNode* insert(ListNode* head, ListNode* pre, element value)//항상 헤드 필요. 헤드 리턴해야 하니까
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
//	head = removed->link;//헤드를 삭제함-> 그 뒤 노드가 헤드가 됨-> 헤드링크를 받아서 그 뒤 노드가 헤드가 되도록.
//	free(removed);//꼭 free해주기
//
//}
//
////pre가 가리키는 노드의 다음 노드를 삭제한다.
//ListNode* delete(ListNode* head, ListNode* pre) {
//	ListNode* removed;
//	removed = pre->link;//프리의 링크필드는 삭제할 노드를 가리킴. 
//	pre->link = removed->link;//줄 갈아끼움
//	free(removed);
//	return head;
//
//}
//
//void print_list(ListNode* head) {
//	for (ListNode* p = head; p != NULL; p = p->link) {//다음 노드로 넘어감
//		printf("%d->", p->data);
//	 }
//	printf("NULL \n");
//}
////=============연결리스트 끝=============
//
////테스트 프로그램
//int main() {
//	ListNode* head = NULL;//항상 null로 두기. 아직 참조변수가 뭐 안 가리켰으니까
//	
//	for (int i = 0; i < 5; i++) {
//		head = insert_first(head, i);//리턴값: head
//		print_list(head);
//	}
//
//
//	return 0;
//}
