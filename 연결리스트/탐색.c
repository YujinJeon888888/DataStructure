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
//ListNode* search_list(ListNode* head, element x) {
//	ListNode* p = head;//head는 곧 전체 노드를 뜻함.
//	//굳이 헤드 담는 변수를 또 만드는 이유: 헤드 자체를 가지고 연산하는 것을 꺼림.
//	while (p != NULL) {
//		//먼저 조건 검사하는 이유: 헤드값에서 바로 찾을 수 있으니까
//		if (p->data == x) {//값 찾으면
//			return p;
//		}
//		p = p->link;//다음 노드로 옮겨가기
//	}
//	return NULL;//탐색 실패. 앞 리턴문에서 안 걸리면 탐색 실패한 것임
//}
//
////테스트 프로그램
//int main() {
//	ListNode* head=NULL;//항상 널로 초기화. 쓰레기값 가질 수 있음
//	head = insert_first(head, 10);//헤드에 10 넣는다. 헤드 노드 없었는데 노드 생김->맨 처음엔 insert_first로
//	print_list(head);
//	head = insert_first(head, 20);
//	print_list(head);
//	head = insert_first(head, 30);
//	print_list(head);
//	if (search_list(head, 30) != NULL) {
//		printf("리스트에서 30을 찾았습니다.\n");
//	}
//	else
//		printf("리스트에서 30을 찾지 못했습니다.\n");
//
//
//	return 0;
//}