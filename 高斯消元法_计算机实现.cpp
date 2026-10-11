#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>//：2 -5 3 1 1 3 -1 3 0 1 1 -5 -1 -4 2 -3
using namespace std;

double gaosi(vector<vector<double>>hlshi);
int main() {
	int N;
	cout << "请输入你想要计算的行列式阶数：";
	cin >> N;
	cout << "请输入" << N * N << "个数据，来填充行列式";
	vector<vector<double>>hlshi(N,vector<double>(N,0.0));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> hlshi[i][j];
		}
	}
	double result = gaosi(hlshi);
	cout << "行列式的计算结果是：" << result;
	return 0;
}
double gaosi(vector<vector<double>>hlshi) {
	int n = hlshi.size();
	//cout << n << "测试n大小" << endl;
	vector<vector<double>> temp(n ,vector<double>(n,0.0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = hlshi[i][j];
		}
	}
	double result = 1;
	int row_num;
	for (int i = 0; i < n; i++) {
		row_num = i;
		for (int k = i + 1; k < n; k++) {
			if (fabs(temp[k][i]) > fabs(temp[row_num][i]))row_num = k;
		}

		if (fabs(temp[row_num][i]) < 1e-12)return 0.0;

		if (row_num != i) {//可以使用 swap(temp[i], temp[pivot_row]); 笑死！！！
			result *= -1;
			vector<double> acase(n, 0.0);
			for (int a = 0; a < n; a++) {
				acase[a] = temp[i][a];
			}
			for (int b = 0; b < n; b++) {
				temp[i][b] = temp[row_num][b];
				temp[row_num][b] = acase[b];
			}
		}

		for (int c = i + 1; c < n; c++) {
			double fac = temp[c][i] / temp[i][i];
			for (int d = i; d < n; d++) {
				temp[c][d] = temp[c][d] - fac * temp[i][d];
			}
		}

	}

	for (int f = 0; f < n; f++) {
		result *= temp[f][f];

	}
	return result;

}