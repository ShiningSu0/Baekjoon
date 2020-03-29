#include<iostream>
using namespace std;
long ary[91] = {0};

int main() {
	int N;
	cin >> N;
	ary[1] = 1;
	ary[2] = 1;
	for (int i = 3; i <= N; i++) {
		ary[i] = ary[i - 1] + ary[i - 2];
	}
	cout << ary[N];
}