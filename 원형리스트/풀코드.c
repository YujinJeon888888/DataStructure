#include <stdio.h> 
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

//리스트의 항목 출력
void print_list(ListNode* last) {
	ListNode* p;
	if (last == NULL) return;//아무것도 없으면 리턴
	p = last->link;// last->link: head
	do {
		printf("%d->", p->data);//데이터 출력
		p = p->link;//옆으로 이동
	} while (p != last);//last 만나면 끝난다. 
	printf("%d->", p->data);//last의 데이터까지 출력하고 리턴. 
}

ListNode* insert_first(ListNode* last, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));//동적할당
	node->data = data;//새로운 노드에 인자로 받은 데이터 값 넣는다. 
	if (last == NULL) {//아무 노드도 없으면
		last = node;//새로운 노드가 마지막 노드가 됨
		node->link = last;//유일무이한 노드->노드가 자기 자신을 가리킴->헤드이자 라스트인 유일무이 노드
	}
	else {//다른 노드 있는 상태면
		node->link = last->link;//새로운 노드는 헤드를 가리킨다. 
		last->link = node;//헤드는 새로운 노드가 된다. 
	}
	return last;//last노드를 리턴한다. 
}

ListNode* insert_last(ListNode* last, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));//동적할당
	node->data = data;//새로운 노드 데이터에 인자 값 넣는다. 
	if (last == NULL) {//아무것도없으면
		last = node;//새로운노드==last;
		node->link = last;//새로운노드는 자기자신을 가리킨다. (유일무이노드)
	}
	else {//뭐 있으면
		node->link = last->link;//새로운 노드는 헤드를 가리킨다. 
		last->link = node;//라스트링크는 노드를 가리킨다.(노드는 라스트가 됨)
		last = node;//노드는 라스트가 됨
	}
	return last;//라스트 리턴
}

//원형연결 리스트 테스트 프로그램
int main() {
	ListNode* last = NULL;//라스트는 널로 초기화하고 시작.

	//list=10->20->30->40
	last = insert_last(last, 20);//라스트에 계속 넣어줌
	last = insert_last(last, 30);
	last = insert_last(last, 40);
	last = insert_first(last, 10);//헤드에 10 넣음
	print_list(last);
	
	return 0;
}