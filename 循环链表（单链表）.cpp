#include<iostream>//本质是把NULL判断改为head判断，并使用对象
using namespace std;
typedef char anytype;
typedef struct cycLink {
	anytype data;
	cycLink* next;
	cycLink(anytype val) :data(val), next(nullptr) {}
}CL;

class cycLinklist {
private:
	CL* head;
	CL* tail;
	int len;
public:
	cycLinklist() {
		head = new CL('0');
		head->next = head;
		tail = head;
		len = 0;
		cout << "链表初始化已完成" << endl;
	}
	~cycLinklist() {
		CL* temp = head->next;
		if (temp != head) {
			CL* r = temp;
			temp = temp->next;
			delete r;
		}
		delete head;
		cout << "链表已经删除成功！！！" << endl;
	}

	void creat_CL(anytype yuan) {
		CL* cl = new CL(yuan);
		tail->next = cl;
		tail = tail->next;
		tail->next = head;
		len++;
	}

	void print_CL(){
		cout << "目前的链表元素分别是：";
		CL* pr = head->next;
		while (pr != head) {
			cout << pr->data << " ";
			pr = pr->next;
		}
		cout << endl;
	}

	int len_CL() {
		return len;
	}

	bool empty_CL() {
		if (head->next == head) {
			return false;
		}
		else return true;
	}

	anytype num_CL(int sit) {
		if (sit >0 || sit <= len) {
			int count = 0;
			CL* r = head;
			while (count != sit) {
				count++;
				r = r->next;
			}
			 
				return r->data;
			
		}
		else {
			return '0';
		}
	}

	int find_CL(anytype yuan) {
		CL* r = head->next;
		int sit = 0;
		if (r->data != yuan) {
			sit++;
			r = r->next;
			if (sit > len)return -1;
		}
		else {
			sit++;
			return sit;
		}
	}

	void add_CL(int sit, anytype yuan) {
		if (sit <= 0 || sit > len + 1) {
			cout << "插入位置不合法！！！" << endl;
			return;
		}
		CL* r = head;
		for (int i = 1; i < sit; i++) {
			r = r->next;//塞入位置的前驱
		}
		CL* s;
		s = new CL(yuan);
		s->next = r->next;
		r->next = s;
		if (sit == len + 1) {
			tail = s;
		}
		len++;
		cout << "已经添加完毕！！！" << endl;

	}

	void del_CL(int sit) {
		if (sit > len || sit <= 0) {
			cout << "删除位置不合法！！！" << endl;
			return;
		}
		CL* r = head;
		CL* s;
		for (int i = 1; i < sit; i++) {
			r = r->next;
		}
		s = r->next;
		r->next = s->next;
		if (sit == len) {
			tail = r;
		}
		delete s;
		len--;
		cout << "删除完成！！！" << endl;
	}
};

int main() {
	const int maxnum = 20;
	anytype a[maxnum];
	int num = 0;
	cycLinklist L;
	cout << "请输入添加的元素个数：";
	cin >> num;
	cout << "请输入" << num << "个元素：";
	for (int i = 0; i < num; i++) {
		cin >> a[i];
		L.creat_CL(a[i]);
	}
	L.print_CL();
	cout << "现在的链表长度是：" << L.len_CL() << endl;
	if (L.empty_CL()) {
		cout << "链表不为空。"<<endl;
	}
	else {
		cout << "链表为空。"<<endl;
	}
	cout << "该链表的第3个元素是：" << L.num_CL(3) << endl;
	cout << "元素a在链表的第" << L.find_CL('a') << "个元素。";
	cout << "在链表的第4个位置上插入f元素。" << endl;
	L.add_CL(4, 'f');
	L.print_CL();
	cout << "删除第3个位置上的元素。" << endl;
	L.del_CL(3);
	L.print_CL();

	return 0;
}