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

//���߿��Ḯ��Ʈ�� ��带 ���
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


//��� newnode�� ��� before�� �����ʿ� �����Ѵ�.
void dinsert(DListNode* before, element data) {
	//1. �Ҵ�
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	//2. ������ ����
	strcpy_s(newnode->data, data,100);
	//3. ����
	//before�� ���� ����
	newnode->llink = before;
	newnode->rlink = before->rlink;
	//before�� �� ����� ���ʿ� newnode ����
	before->rlink->llink = newnode;
	//�������� before ���� �ǵ帮��. before�� rlink�� newnode����
	before->rlink = newnode;
}

//��� removed�� �����Ѵ�. 
void ddelete(DListNode* head, DListNode* removed) {
	//1. ��带 �����Ϸ� �ϸ� �����Ѵ�. 
	if (removed == head) {
		return;
	}
	//2. ����
	//removed�� �����ʾֶ� before�� ����
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	//3. ����
	free(removed);
}

int main() {
	char ch;
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);

	dinsert(head, "������");
	dinsert(head, "Ű�̳��丮�ڴ�");
	dinsert(head, "�繫������Ʈ");

	current = head->rlink;
	printf_dlist(head);

	do {
		printf("\n��ɾ �Է��Ͻÿ�(<,>,q): ");
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