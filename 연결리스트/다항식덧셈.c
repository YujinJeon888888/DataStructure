#include <stdio.h>
#include <malloc.h>
typedef struct {
	int coef;
	int expon;
	struct ListNode* link;
}ListNode;

//연결리스트 헤더
typedef struct ListType {
	int size;
	ListNode* head;
	ListNode* tail;

}ListType;

void error(char* message) {
	printf("%s\n", message);
	exit(1);
}

//리스트 헤더 생성함수(초기화)
ListType* create() {//리턴만
	ListType* plist = (ListType*)malloc(sizeof(ListType));// 공간할당
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}
//plist는 연결리스트의 헤더를 가리키는 포인터, coef는 계수, expon은 지수
void insert_last(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) error("메모리 할당 에러");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;//끝이니까 닫아줌.

	if (plist->tail == NULL) {//테일이 비었으면 꼬랑지에
		plist->head = plist->tail=temp;
	}
	else {//테일이 차 있으면 테일 꼬랑지 링크에 temp넣기. 
		plist->tail->link = temp;
		plist->tail = temp;//temp가 tail이 됨.
	}
	plist->size++;
}

//list3=list1+list2;
void poly_add(ListType* plist1, ListType* plist2, ListType* plist3) {
	ListNode* a = plist1->head;//다항식 a
	ListNode* b = plist2->head;//다항식 b
	int sum;

	while (a && b) {
		if (a->expon == b->expon) {
			sum = a->coef + b->coef;
			if (sum != 0) insert_last(plist3, sum, a->expon);//계수와 지수 넣음
		}
		else if (a->expon > b->expon) {
			insert_last(plist3, a->coef, a->expon);
			a = a->link;//다음 노드로 옮김
		}
		else {
			insert_last(plist3, b->coef, b->expon);
			b = b->link;//다음 노드로 이동
		}
	}

	//a나 b중 하나가 먼저 끝나게 되면 남아있는 항들을 모두 결과 다항식으로 복사
	for (; a != NULL; a = a->link)//NULL만날때까지 남아있는거 싹싹 긁음
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insert_last(plist3, b->coef, b->expon);
}

void poly_print(ListType* plist) {
	ListNode* p = plist->head;//원본 보존이 좋아서 p로 옮김.  head를 옮긴 것이니 노드를 다 아는 셈
	
	printf("polynomial= ");
	for (; p; p = p->link) {
		printf("%d^%d  + ", p->coef, p->expon);
	}
	printf("\n");
}


//메인 함수
int main() {
	ListType* list1, * list2, * list3;
	//연결리스트 헤더 생성
	list1 = create();
	list2 = create();
	list3 = create();
	//다항식 1 생성
	insert_last(list1, 3, 12);//리스트타입 주고, 계수는 3, 지수는 12
	insert_last(list1, 2, 8);
	insert_last(list1, 1, 0);
	//다항식 2
	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);

	poly_print(list1);
	poly_print(list2);

	//다항식3=다항식1+다항식2
	poly_add(list1, list2, list3);
	poly_print(list3);

	free(list1); free(list2); free(list3);//리스트 헤더정보를 가지고 있는 애:  free하면 다 프리
	return 0;
}
