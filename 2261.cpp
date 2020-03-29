#include<iostream>
using namespace std;
#include<vector>
#include<cmath>
int main() {
	int N;
	cin >> N;
	vector<int> x;
	vector<int> y;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		x.push_back(a);
		y.push_back(b);
	}
	int min = pow(abs(x[0]-x[1]),2)+ pow(abs(y[0] - y[1]), 2);
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (min > pow(abs(x[i] - x[j]), 2) + pow(abs(y[i] - y[j]), 2)) {
				min = pow(abs(x[i] - x[j]), 2) + pow(abs(y[i] - y[j]), 2);
			}
		}
	}
	cout << min;
}