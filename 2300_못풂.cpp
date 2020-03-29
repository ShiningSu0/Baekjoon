#include<iostream>

using namespace std;
int ary[10010][2] = { 0 };
int ans[10010] = { 0 };
int max(int a, int b) {
	if(a > b) {
		return a;
	}
	else
		return b;
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ary[i][0] >> ary[i][1];
	}
	ans[0] = abs(ary[0][1]) * 2;

	for (int i = 1; i < N; i++) {
		if(ary[i][0]-ary[i-1][0]){
	}
	cout << ans[N - 1];
}