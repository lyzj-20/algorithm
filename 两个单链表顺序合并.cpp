#include<iostream>
using namespace std;
typedef int anytype;
typedef struct Link {
	anytype data;
	Link* next;
	Link(anytype val) :data(val), next(nullptr){}
}SLL;

void creat_L(SLL*& L, anytype a[], int num) {
	if (num <= 0) {
		cout << "链表建立不合法！！！" << endl;
		return;
	}
	SLL* tail = L;
	for (int i = 0; i < num; i++) {
		SLL* s = new SLL(a[i]);
		tail->next = s;
		tail = s;
	}
	cout << "链表建立完毕！！！" << endl;
	return;
}


int len_L(SLL* L) {
	int count = 0;
	SLL* r = L;
	while (r->next != NULL) {
		count++;
		r = r->next;
	}
	return count;
}

void compare_L(SLL*& L3, SLL* L1, SLL* L2) {
	SLL* l1 = L1->next;
	SLL* l2 = L2->next;
	SLL* l3 = L3;
	while (l1 != NULL && l2 != NULL) {
		if (l1->data < l2->data) {
			
			SLL* s = new SLL(l1->data);
			l3->next = s;   
			l3 = s;        
			l1 = l1->next;  
		}
		else {
			
			SLL* s = new SLL(l2->data);
			l3->next = s;
			l3 = s;         
			l2 = l2->next;
		}
	}

	

	if (l1 != NULL) {
		while (l1 != NULL) {
			SLL* s = new SLL(l1->data);
			l3->next = s;
			l1 = l1->next;
		}
		
	}
	else {
		while (l2 != NULL) {
			SLL* s = new SLL(l2->data);
			l3->next = s;
			l2 = l2->next;
		}
		
	}

	cout << "链表顺序排列已完成！！！" << endl;
	return;
}

void print_L(SLL* L,int num) {
	cout << "此时" << num << "链表所含有的元素是：";
	SLL* r = L->next;
	while(r!=NULL){
		cout << r->data << " ";
		r = r->next;
	}
	cout << endl;
	return;
}

void del_L(SLL*& L) {
	SLL* r = L;
	while (r != NULL) {
		SLL* s;
		s = r;
		r = r->next;
		delete s;
	}
	cout << "链表已销毁。" << endl;
	return;
}

int main() {
	const int maxnum = 50;
	cout << "接下来请按照提示输入两组顺序数据。" << endl;
	int num1, num2;
	cout << "请输入第一组数据的个数：";
	cin >> num1;
	cout << "请输入第一组的" << num1 << "个数据：";
	anytype l_1[maxnum];
	for (int i = 0; i < num1; i++) {
		cin >> l_1[i];
	}
	SLL* L1=new SLL(0);
	creat_L(L1, l_1, num1);
	print_L(L1, 1);

	cout << "请输入第二组数据的个数：";
	cin >> num2;
	cout << "请输入第二组的" << num2 << "个数据：";
	anytype l_2[maxnum];
	for (int i = 0; i < num2; i++) {
		cin >> l_2[i];
	}
	SLL* L2=new SLL(0);
	creat_L(L2, l_2, num1);
	print_L(L2, 2);

	cout << "现在开始排序！！！" << endl;
	SLL* L3=new SLL(0);
	compare_L(L3, L1, L2);
	print_L(L3, 3);
	del_L(L1);
	del_L(L2);
	del_L(L3);
	return 0;
}

