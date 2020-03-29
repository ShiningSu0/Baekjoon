#include<iostream>
using namespace std;
int ary[10010] = { 0 };
int ans[10010] = { 0 };
int max(int a,int b) {
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
		ans[1] = ary[1] + ans[0];
	}
	if (N >= 3) {
		ans[2] = max(max(ary[0] + ary[2], ary[1] + ary[2]), ans[1]);
	}
	for (int i = 3; i < N; i++) {
		ans[i] = max(max(ary[i] + ans[i - 2], ary[i] + ary[i - 1] + ans[i - 3]),ans[i-1]);
	}
	cout << ans[N-1];
}