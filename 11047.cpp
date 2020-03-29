#include<iostream>
using namespace std;
int ary[10] = { 0 };
int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> ary[i];
	}
	int sum = 0;
	for (int i = N - 1; i >= 0; i--) {
		sum+=(K / ary[i]);
		K %= ary[i];
	}
	cout << sum;
}