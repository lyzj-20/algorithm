#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 5;
int main() {
	int list[N];
	cout << "数组的大小是" << N << ",请输入" << N << "个整数元素：";
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	cout << endl;
	//
	//
	int sit;
	cout << "请输入想要在数组中查找元素的下标：";
	cin >> sit;
	if (sit > N - 1)cout << "不存在此下标。";
	else cout << "元素是：" << list[sit] << endl;
	//
	//
	cout << "请输入在列表中想要查找的元素，我会返回下标：";
	int find_num;
	cin >> find_num;
	int list_find[N];
	for (int i = 0; i < N; i++) {
		list_find[i] = -1;
	}
	int list_f_sit = 0;
	for (int i = 0; i < N; i++) {
		if (list[i] == find_num) {
			list_find[list_f_sit] = i;
			list_f_sit++;
		}
	}
	if (list_find[0] == -1)cout << "数组中不存在你寻找的元素。";
	else {
		cout << "元素在数组中的：";
		int i = 0;
		while (list_find[i] != -1) {
			cout << list_find[i] << ' ';
			i++;
		}
	}
	cout << endl;
	//
	//
	cout << "请在0—" << N - 1 << "中选一个下标，对其上元素进行删除：";
	int erase;
	cin >> erase;
	for (int i = erase+1; i <=N - 1; i++) {
		list[i - 1] = list[i];
	}
	list[N - 1] = 0;
	cout << "现在的数组是：";
	for (int i = 0; i < N - 1; i++) {
		cout << list[i] << ' ';
	}
	cout << endl;
	//
	//
	cout << "请在0—" << N - 1 << "中选一个下标，对其上添加一个元素：";
	int add_sit,add_num;
	cin >> add_sit>>add_num;
	for (int i = N - 2; i >=add_sit; i--) {
		list[i + 1] = list[i];
	}
	list[add_sit] = add_num;
	cout << "现在的数组是：";
	for (int i = 0; i < N ; i++) {
		cout << list[i]<<' ';
	}
	cout << endl;
	//
	//
	cout << "现在创建一个大小为5的顺序数组"<<endl;
	int list_2[5] = { 1,2,5,6,9 };
	cout << "并将两个数组顺序合并";
	vector<int>list_copy(N); 
	for (int i = 0; i < N; i++) {
		list_copy[i] = list[i];
	}
	sort(list_copy.begin(), list_copy.end()); 
	vector<int>list_all(5 + N, 0); 
	int point_1=0, point_2=0,i=0;
	while (point_1 != N&& point_2 !=5) {//判断是与门还是或门
		if (list_copy[point_1] <= list_2[point_2]) {
			list_all[i] = list_copy[point_1];
			point_1++;
			i++;
		}
		else {
			list_all[i] = list_2[point_2];
			point_2++;
			i++;
		}
	}
	if (point_1 == N) {
		for (int j = point_2; j < 5; j++) {
			list_all[i] = list_2[j];
			i++;
		}
	}
	else{
		for (int j = point_1; j < N; j++) {
			list_all[i] = list_copy[j];
			i++;
		}

	}
	cout << "排序后的数组是：";
	for (int x : list_all) {
		cout << x << ' ';
	}
	return 0;
	

}