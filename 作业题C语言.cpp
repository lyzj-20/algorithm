#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h> 
#define maxnum 50
typedef char anytype;
typedef  struct {
	anytype data[maxnum];
	int len;
}List;
void creatlist(List*& L, int n, anytype a[]) {
	int i = 0, k = 0;
	L = (List*)malloc(sizeof(List));
	for (k; k < n; k++) {
		L->data[i] = a[k];
		i++;
	}
	L->len = n;
	return;
}
void printList(List* L) {
	printf("输出顺序表：");
	for (int i = 0; i < L->len; i++) {
		printf("%c", L->data[i]);
	}
	printf("\n");
	return;
}
void printlen(List* L) {
	printf("顺序表的长度是：%d\n", L->len);
}

bool emptylist(List* L) {
	if (L->len == 0)return false;
	else { return true; }
}

void Nolist(List* L, int n) {
	printf("顺序表的第%d个元素是：%c\n", n, L->data[n - 1]);
}

void findlist(List* L, anytype n) {
	for (int j = 0; j < L->len; j++) {
		if (L->data[j] == n) {
			printf("%c", n);
			printf("在顺序表的第%d位\n", j + 1);
			return;
		}
	}
	printf("顺序表中不存在这个元素。\n");
}

void addlist(List*& L, int sit, anytype e) {
	if (sit - 1 > L->len || sit > maxnum) {
		printf("朋友这并非插入啊！");
		return;
	}
	else {
		if (sit == L->len + 1)L->data[sit] = e;
		else {
			for (int i = L->len - 1; i >= sit; i--) {
				L->data[i + 1] = L->data[i];
			}
			L->data[sit] = e;
			L->len++;
		}
		return;
	}
}


void dellist(List*& L, int sit) {
	if (sit > L->len) {
		printf("不存在的元素怎么删除？");
		return;
	}
	else {
		for (int i = sit; i < L->len; i++) {
			L->data[i - 1] = L->data[i];
		}
		L->len--;
		return;
	}
}

void destroylist(List*& L) {
	free(L);
	L = NULL;
}
int main() {
	anytype a[maxnum];
	int num = 0;
	printf("你想要输入几个元素呢？");
	scanf("%d", &num);
	printf("请输入吧：");
	for (int i = 0; i < num; i++) {
		scanf(" %c", &a[i]);
	}
	List* L;
	creatlist(L, num, a);
	printList(L);
	printlen(L);
	if (emptylist(L)) {
		printf("顺序表不为空");
	}
	else {
		printf("顺序表为空");
	}
	printf("请输入你想要查询的位置吧：");
	scanf(" %d", &num);
	Nolist(L, num);
	printf("请输入你想要查询的元素吧：");
	anytype c;
	scanf(" %c", &c);
	findlist(L, c);
	printf("接下来我会在第四个位置上插入f");
	addlist(L, 4, 'f');
	printList(L);
	printf("我会删除第三个元素");
	dellist(L, 3);
	printList(L);
	destroylist(L);
	return 0;
}

