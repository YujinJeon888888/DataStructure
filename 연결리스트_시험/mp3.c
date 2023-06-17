#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
typedef char element[100];

typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;

}DListNode;

DListNode* current;

void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

//이중연결리스트의 노드를 출력
void print_dlist(DListNode *phead) {
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		if (p == current) {
			printf("<-| #%s# |->", p->data);
		}
		else
			printf("<-| %s |->",p->data);
	}
	printf("\n");
}


//노드 newnode를 노드 before의 오른쪽에 삽입한다.
void dinsert(DListNode* before, element data) {
	//1. 할당
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	//2. 데이터 삽입
	strcpy_s(newnode->data, data,100);
	//3. 연결
	//before에 먼저 연결
	newnode->llink = before;
	newnode->rlink = before->rlink;
	//before의 옆 노드의 왼쪽에 newnode 연결
	before->rlink->llink = newnode;
	//마지막에 before 직접 건드리기. before의 rlink에 newnode연결
	before->rlink = newnode;
}

//노드 removed를 삭제한다. 
void ddelete(DListNode* head, DListNode* removed) {
	//1. 헤드를 삭제하려 하면 리턴한다. 
	if (removed == head) {
		return;
	}
	//2. 연결
	//removed의 오른쪽애랑 before랑 연결
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	//3. 프리
	free(removed);
}

int main() {
	char ch;
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);

	dinsert(head, "빨간맛");
	dinsert(head, "키미노토리코니");
	dinsert(head, "사무라이하트");

	current = head->rlink;
	printf_dlist(head);

	do {
		printf("\n명령어를 입력하시오(<,>,q): ");
		ch = getchar();
		if(ch == '<') {
			current = current->llink;
			if (current == head) {
				current = current->llink;
			}
		}
		else if (ch == '>') {
			current = current->rlink;
			if (current == head) {
				current = current->rlink;
			}
		}
		print_dlist(head);
		getchar();

	} while (ch != 'q');

	return 0;
}