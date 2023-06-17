#define SIZE 8
#define MAX_ELEMENT 200
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int key;
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

//생성함수
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

//초기화함수
void init(HeapType* h) {
	h->heap_size = 0;
}

//현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
//삽입 함수
void insert_max_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	//트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key > h->heap[i / 2].key))
	{
		h->heap[i] = h->heap[i / 2];//부모노드를 끌어내린다.
		i /= 2;
	}
	h->heap[i] = item;//새로운 노드를 그 자리에 삽입
}

//삭제함수
//최대히프에서 삭제연산: 최대값을 가진 요소를 삭제하는 것
//최대값: 루트노드
element delete_max_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];//루트노드삭제

	//루트노드 삭제 후 재구성 필요
	//빈 루트노드 자리에는 히프의 마지막 노드를 가져온다
	//새로운 루트와 자식 노드를 비교해 교환한다. (자식 중 더 큰 값과 교환)
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;//왼쪽 자식부터 비교

	while (child <= h->heap_size) {//유효 힙사이즈동안
		//현재 노드의 자식노드 중 더 큰 자식 노드를 찾는다.
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		//한 단계 아래로 이동
		h->heap[parent] = h->heap[child];//자식 값을 부모로 끌어올린다.
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;//교환
	return item;
}

////////////////////////////////////////

//우선순위 큐인 히프를 이용한 정렬
void heap_sort(element a[], int n) {
	int i;
	HeapType* h;

	h = create();

	init(h);
	for (i = 0; i < n; i++) {//배열개수만큼
		insert_max_heap(h, a[i]);//힙 h에 배열요소 추가
	}
	for (i = 0; i < n; i++) {//인덱스 거꾸로 꺼낸다.==오름차순. 내림차순: 인덱스 올바르게
		a[i] = delete_max_heap(h);
	}
	free(h);
}

int main() {
	int k;
	element Arr[] = { 1, 23, 12, 9, 30, 2, 23, 50 };
	//배열 사이즈 구해야한다.
	int size = sizeof(Arr) / sizeof(int);
	heap_sort(Arr, size);//소트한다. 

	//사용자 입력 받기
	while (1)
	{
		printf("출력할 수의 갯수를 입력하세요: ");
		scanf_s("%d", &k);
		if (k > size || k < 0) {
			printf("유효한 범위가 아닙니다. \n");
		}
		else
			break;
	}

	for (int i = 0; i < k; i++) {
		printf("%d ", Arr[i].key);//내림차순 정렬한 값
		while (1) {//중복되는 수 끝날때까지 출력
			if (Arr[i].key == Arr[i + 1].key) {//옆에 중복되는 수 있으면
				printf("%d ", Arr[i + 1].key);
				i++;
			}
			else
				break;
		}
	}

	return 0;
}

