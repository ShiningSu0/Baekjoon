/*#include<iostream>

using namespace std;
int ary[301] = { 0 };
int ans[301] = { 0 };
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else
		return b;
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ary[i];
	}
	ans[0] = ary[0];
	if (N >= 2) {
		ans[1] = ary[0] + ary[1];
	}
	if (N >= 3) {
		ans[2] = max(ary[0] + ary[2], ary[1] + ary[2]);
	}
	for (int i = 3; i < N; i++) {
		ans[i] = max(ary[i]+ary[i-1]+ans[i-3],ary[i]+ans[i-2]);
	}
	cout << ans[N - 1];
}*/#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;
	int ary[91] = { 0 };
	ary[0] = 0;
	ary[1] = 1;

	if (n == 1) {
		cout << ary[0];
	}
	else {
		int temp;
		for (int i = 2; i < n + 1; i++) {
			ary[i] = ary[i - 1] + ary[i - 2];

		}
		cout << ary[n];

	}

	return 0;
}