#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef char anytype;
typedef struct Linknode{
	anytype data;
	Linknode* next;
}Linklist;

void onelink(Linklist*& L) {
	L = (Linklist*)malloc(sizeof(Linklist));
	L->next = NULL;
	return;
}
void creatLinklist(Linklist*& L, anytype n[], int num) {
	Linklist* s, * tail;
	tail = L;
	for (int i = 0; i < num; i++) {
		s = (Linklist*)malloc(sizeof(Linklist));
		s->data = n[i];
		tail->next = s;
		tail = s;
	}
	tail->next = NULL;
}

void printLinklist(Linklist*& L) {
	Linklist* p = L->next;
	while (p != NULL) {
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n");
}

int lenLinklist(Linklist*& L) {
	int n = 0;
	Linklist* p = L->next;
	while (p != NULL) {
		n++;
		p = p->next;
	}
	return n;
}
bool emptyLinklist(Linklist* L) {
	if (L->next == NULL) {
		return false;
	}
	return true;
}

anytype NO_Linklist(Linklist* L,int sit){
	Linklist* p = L->next;
	for (int i = 1; i < sit; i++) {
		p = p->next;
	}
	//printf("第%d个元素是%c", sit, p->data);
	return p->data;
}

int find_Linklist(Linklist*& L, anytype thefind) {
	Linklist* p = L->next;
	int sit=1;
	while (p->data != thefind&&p->next!=NULL) {
		p = p->next;
		sit++;
	}
	if (p->next == NULL&&p->data!=thefind)return -1;
	else return sit;
}

void add_Linklist(Linklist*& L, int sit, anytype a) {
	Linklist* s, * p;
	p = L->next;
	s = (Linklist*)malloc(sizeof(Linklist));
	s->data = a;
	for (int i = 1; i < sit-1; i++) {
		p = p->next;
	}
	s->next = p->next; 
	p->next = s;
}

void delLinklist(Linklist*& L, int sit) {
	Linklist* p,*s;
	p = L->next;
	s = L;
	for (int i = 1; i < sit; i++) {
		s = p;
		p = p->next;
	}
	s->next = p->next;
	free(p);
	return;
}

void free_Linklist(Linklist*& L) {
	Linklist* pre = L, * p = L->next;
	while (p->next != NULL) {
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(p);
	return;
}

int main() {
	anytype a[50];
	int num = 0;
	Linklist *L;
	printf("请输入你想要输入的元素个数(注请不要输入超过50的数)：");
	scanf_s(" %d", &num);
	printf("请输入%d个元素：", num);
	for (int i = 0; i < num; i++) {
		scanf_s(" %c", &a[i]);
	}
	onelink(L);
	creatLinklist(L, a, num);
	printf("现在的链表是：");
	printLinklist(L);
	printf("现在的链表长度是：%d\n", lenLinklist(L));
	
	if (emptyLinklist(L)) {
		printf("链表不为空。\n");
	}
	else { printf("链表为空。\n"); 
	}
	int find_sit;
	printf("请输入想要查询的位置：");
	scanf_s("%d", &find_sit);
	if (find_sit > lenLinklist(L)||find_sit<=0) {
		printf("不存在这个位置。\n");
	}
	else { printf("第%d个位置是%c\n", find_sit, NO_Linklist(L, find_sit)); }
	printf("请输入想要查询的元素：");
	anytype find_yuan;
	scanf_s(" %c", &find_yuan);
	if (find_Linklist(L,find_yuan) == -1) {
		printf("不存在这个元素。\n");
	}
	else { printf("在第%d个位置\n", find_Linklist(L, find_yuan)); }
	printf("接下来会在第4个位置上插入f元素\n");
	add_Linklist(L, 4, 'f');
	printf("现在的链表是：");
	printLinklist(L);
	printf("接下来删除第3个元素\n");
	delLinklist(L, 3);
	printf("现在的链表是：");
	printLinklist(L);
	free_Linklist(L);
	return 0;
}


