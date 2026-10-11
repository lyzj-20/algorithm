#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main() {
	int n;
	long long Jiecheng=1;
	cout << "请输入n的值:";
	cin >> n;

	for (int i = 1; i <= n; i++) {
		long long duishu;
		duishu = log(i) / log(2);
		cout << fixed << setprecision(2);
		cout << duishu<< " ";
		cout << sqrt(i) << " ";
		cout << i << " ";
		cout << i * duishu << " ";
		cout << pow(i, 2) << " ";
		cout << pow(i, 3) << " ";
		cout << pow(2, i) << " ";
		Jiecheng *= i;
		cout << Jiecheng << endl;

	}

	return 0;
}