#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef char anytype;
typedef struct dlink {
	anytype data;
	struct dlink* head;
	struct dlink* next;
}DLL;
DLL* creatdLinklist(DLL*& L, anytype a[], int num) {
	L = (DLL*)malloc(sizeof(DLL));
	L->head = NULL;
	L->next = NULL;
	DLL* s, * r = L;
	for (int i = 0; i < num; i++) {
		s = (DLL*)malloc(sizeof(DLL));
		s->data = a[i];
		r->next = s;
		s->head = r;
		r = s;
	}
	r->next = NULL;
	return r;
}

void printdLinklist(DLL* L) {
	DLL* r = L;
	while (r->next != NULL) {
		r = r->next;
		printf("%c ", r->data);
	}
	printf("\n");
	return;
}

int lendLinklist(DLL* L) {
	int len = 0;
	DLL* r = L;
	while (r->next != NULL) {
		r = r->next;
		len++;
	}
	return len;
}
bool emptydLinklist(DLL* L) {
	DLL* r = L;
	if (r->next == NULL)return false;
	else return true;
}

anytype numdLinklist(DLL* L,DLL* R, int num,int len) {
	if (num > len||num<=0) {
		return '-';
	}
	else {
		if (num <= len / 2) {
			DLL* n = L;
			for (int i = 0; i < num; i++) {
				n = n->next;
			}
			return n->data;
		}
		else {
			DLL* h = R;
			for (int i = len; i > num; i--) {
				h = h->head;
			}
			return h -> data;
		}
		
	}
}

int finddLinklist(DLL* L, anytype a) {
	DLL* r = L->next;
	int sit = 1;
	while (r->next != NULL&&r->data!=a) {
		r = r->next;
		sit++;
	}
	if (r->data == a) {
		return sit;
	}
	else {
		return -1;
	}

}

void add_dLinklist(DLL* &L, DLL* &R, int sit, anytype a ,int len) {
	if (sit > len+1 || sit <= 0) {
		printf("无法实现。\n");
		return;
	}
	else {
		if (sit < (len + 1) / 2)  {
			DLL* n = L,*s;
			s = (DLL*)malloc(sizeof(DLL));
			s->data = a;
			for (int i = 1; i < sit; i++) {
				n = n->next;
			}
			s->next = n->next;
			s->head = n;
			n->next = s;
		}
		else {
			DLL* h = R, * S;
			S = (DLL*)malloc(sizeof(DLL));
			S->data = a;
			if (sit == len + 1) {
				S->next = NULL;
				S->head = h;
				h->next = S;
			}
			else {
				for (int i = len; i > sit; i--) {
					h = h->head;
				}
				S->next = h;
				S->head = h->head;
				h->head->next = S;
				h->head = S;
			}

		}
	}
	return;
}

void deldLinklist(DLL*& L, DLL* &R, int sit,int len) {
	if (sit > len || sit <= 0) {
		printf("无法实现。\n");
		return;
	}
	else {
		if (sit <=(len + 1) / 2) {
			DLL* n = L, * s;
			
			for (int i = 1; i < sit; i++) {
				n = n->next;
			}
			s = n->next;
			n->next = s->next;
			s->next->head = n;
			free(s);
		}
		else {
			DLL* h = R, * S;
			if (sit == len) {
				S=h;
				h->head->next = NULL;
				free(S);
			}
			else {
				for (int i = len; i > sit; i--) {
					h = h->head;
				}
				S = h->head;
				h->head = S->head;
				S->head -> next = h;//注意，头尾地址一起更新
				free(S);
			}
			

		}
	}

}
DLL* findR(DLL* L) {
	DLL* r = L;
	while (r->next != NULL) {
		r= r->next;
	}
	return r;
}

void desdLinklist(DLL*& L) {
	DLL* r = L->next,*pre=L;
	while (r->next != NULL) {
		free(pre);
		pre = r;
		r = r->next;
	}
	free(pre);
	free(r);
	return;
}

int main() {
	int num = 0;
	anytype a[50];
	DLL* L, * R;
	printf("请输入想要输入元素的个数：");
	scanf_s("%d", &num);
	printf("请输入%d个元素：", num);
	for (int i = 0; i < num; i++) {
		scanf_s(" %c", &a[i]);
	}
	R=creatdLinklist(L, a, num);
	printf("现在的链表是：");
	printdLinklist(L);
	int len = lendLinklist(L);
	printf("目前的链表长度是：%d\n",len);
	if (emptydLinklist(L)) {
		printf("链表不为空。\n");
	}
	else { printf("链表为空\n"); }
	int sit = 0;
	printf("请输入想要查找的元素的序号：");
	scanf_s("%d", &sit);
	printf("第%d个元素是%c\n", sit, numdLinklist(L, R, sit, len));
	anytype b;
	printf("请输入想要在链表中查询的元素：");
	scanf_s(" %c", &b);
	if (finddLinklist(L, b) == -1) {
		printf("不存在这个元素。\n");
	}
	else {
		printf("你要查找的元素%c在第%d位。\n", b, finddLinklist(L, b));
	}
	printf("接下来你可以在某个位置上插入你想要的元素\n");
	int sit_2;
	anytype yuan;
	printf("请输入你想要插入的位置(建议不要超过%d+1):", len);
	scanf_s("%d", &sit_2);
	printf("请输入你想要插入的元素(建议类型与上述类型一致):");
	scanf_s(" %c", &yuan);
	add_dLinklist(L, R, sit_2, yuan, len);
	printf("现在的链表是：");
	printdLinklist(L);
	int sit_3;
	printf("接下来在链表中删除一个元素。\n");
	len = lendLinklist(L);
	printf("请输入你想要删除的元素的位置(建议不要超过%d):", len);
	scanf_s("%d", &sit_3);
	R = findR(L);
	deldLinklist(L, R, sit_3, len);
	printf("现在的链表是：");
	printdLinklist(L);
	printf("释放链表。\n");
	desdLinklist(L);
	return 0;



}



	
