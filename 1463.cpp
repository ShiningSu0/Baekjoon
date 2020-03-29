#include<iostream>
using namespace std;
int ary[10000000] = { 0 };
void calc(int n) {
	for (int i = 2; i <= n; i++) {
		ary[i] = ary[i - 1] + 1;
		if (i % 3 == 0) {
			ary[i] = (ary[i] > ary[i / 3] + 1) ? ary[i / 3] + 1 : ary[i];
			}
		if (i % 2 == 0) {
			ary[i] = (ary[i] > ary[i / 2] + 1) ? ary[i / 2] + 1 : ary[i];
			}
	}
}
int main() {
	int N;
	cin >> N;
	calc(N);
	cout << ary[N];
	return 0;
}