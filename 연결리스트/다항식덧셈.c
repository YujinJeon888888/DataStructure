#include <stdio.h>
#include <malloc.h>
typedef struct {
	int coef;
	int expon;
	struct ListNode* link;
}ListNode;

//���Ḯ��Ʈ ���
typedef struct ListType {
	int size;
	ListNode* head;
	ListNode* tail;

}ListType;

void error(char* message) {
	printf("%s\n", message);
	exit(1);
}

//����Ʈ ��� �����Լ�(�ʱ�ȭ)
ListType* create() {//���ϸ�
	ListType* plist = (ListType*)malloc(sizeof(ListType));// �����Ҵ�
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}
//plist�� ���Ḯ��Ʈ�� ����� ����Ű�� ������, coef�� ���, expon�� ����
void insert_last(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) error("�޸� �Ҵ� ����");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;//���̴ϱ� �ݾ���.

	if (plist->tail == NULL) {//������ ������� ��������
		plist->head = plist->tail=temp;
	}
	else {//������ �� ������ ���� ������ ��ũ�� temp�ֱ�. 
		plist->tail->link = temp;
		plist->tail = temp;//temp�� tail�� ��.
	}
	plist->size++;
}

//list3=list1+list2;
void poly_add(ListType* plist1, ListType* plist2, ListType* plist3) {
	ListNode* a = plist1->head;//���׽� a
	ListNode* b = plist2->head;//���׽� b
	int sum;

	while (a && b) {
		if (a->expon == b->expon) {
			sum = a->coef + b->coef;
			if (sum != 0) insert_last(plist3, sum, a->expon);//����� ���� ����
		}
		else if (a->expon > b->expon) {
			insert_last(plist3, a->coef, a->expon);
			a = a->link;//���� ���� �ű�
		}
		else {
			insert_last(plist3, b->coef, b->expon);
			b = b->link;//���� ���� �̵�
		}
	}

	//a�� b�� �ϳ��� ���� ������ �Ǹ� �����ִ� �׵��� ��� ��� ���׽����� ����
	for (; a != NULL; a = a->link)//NULL���������� �����ִ°� �Ͻ� ����
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insert_last(plist3, b->coef, b->expon);
}

void poly_print(ListType* plist) {
	ListNode* p = plist->head;//���� ������ ���Ƽ� p�� �ű�.  head�� �ű� ���̴� ��带 �� �ƴ� ��
	
	printf("polynomial= ");
	for (; p; p = p->link) {
		printf("%d^%d  + ", p->coef, p->expon);
	}
	printf("\n");
}


//���� �Լ�
int main() {
	ListType* list1, * list2, * list3;
	//���Ḯ��Ʈ ��� ����
	list1 = create();
	list2 = create();
	list3 = create();
	//���׽� 1 ����
	insert_last(list1, 3, 12);//����ƮŸ�� �ְ�, ����� 3, ������ 12
	insert_last(list1, 2, 8);
	insert_last(list1, 1, 0);
	//���׽� 2
	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);

	poly_print(list1);
	poly_print(list2);

	//���׽�3=���׽�1+���׽�2
	poly_add(list1, list2, list3);
	poly_print(list3);

	free(list1); free(list2); free(list3);//����Ʈ ��������� ������ �ִ� ��:  free�ϸ� �� ����
	return 0;
}
