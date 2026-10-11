#include<iostream>
using namespace std;
int main() {
	int n;
	cout << "请输入计算中的最大整数：";
	cin >> n;
	long long sum = 0;
	long long jiecheng = 1;
	for (int i = 1; i <= n; i++) {
		jiecheng *= i;
		sum += jiecheng;
	}
	cout << "连续正阶整数为：" << sum << endl;
	return 0;


}