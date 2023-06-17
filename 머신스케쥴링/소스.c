#include <stdio.h>
#define MAX_ELEMENT 200

typedef struct {
	int id;
	int avail;
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
//삽입함수
void insert_min_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	//트리를 거슬러 올라가면서 부모노드와 비교하는 과정
	//i!=이고: 최상위루트면 비교할 부모노드가 없으니까
	while ((i != 1) && (item.avail) < h->heap[i / 2].avail)//부모의 실행시간이 더 많다면
	{
		h->heap[i] = h->heap[i / 2];//바꾼다(실행시간 많은게 아래로 끌어내려져야 하니까)
		i /= 2;//이제 인덱스 부모노드로 올린다
	}
	h->heap[i] = item;//부모노드에 새로운 아이템 삽입(비로소 교체됨)
}

//삭제 함수(가장 아래의 노드를 삭제한다.)
element delete_min_heap(HeapType* h) {
	int parent, child;
	element item,temp;

	item = h->heap[1];//삭제하는노드
	temp = h->heap[(h->heap_size)--];//비교하는노드
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		//현재 노드의 자식노드 중 더 작은 자식노드를 찾는다.
		if((child<h->heap_size)&&(h->heap[child].avail>h->heap[child+1].avail)) break;
		child++;
		if (temp.avail < h->heap[child].avail) break;

		//한 단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child += 2;
	}
	h->heap[parent] = temp;
	return item;
}

#define JOBS 7
#define MACHINE 3

int main() {
	int jobs[JOBS] = { 8,7,6,5,3,2,1 };
	element m = { 0,0 };
	HeapType* h;
	h = create();
	init(h);
	//여기사 avail값은 기계가 사용 가능하게 되는 시간이다. 
	for (int i = 0; i < MACHINE; i++) {
		m.id = i + 1;
		m.avail = 0;
		insert_min_heap(h, m);
	}
	//최소히프에서 기계를 꺼내서 작업을 할당하고 사용가능 시간을 증가시킨 후에
	//다시 최소 히프에 추가한다.
	for (int i = 0; i < JOBS; i++) {
		m = delete_min_heap(h);
		printf("JOB %d를 시간 = %d부터 시간= %d까지 기계 %d번에 할당한다.\n",
			i, m.avail, m.avail + jobs[i] - 1, m.id);
		m.avail += jobs[i];
		insert_min_heap(h, m);
	}
	return 0;
}