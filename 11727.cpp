#include<iostream>
using namespace std;
int ary[1010] = { 0 };
int main() {
	int n;
	cin >> n;
	ary[1] = 1;
	ary[2] = 3;
	for (int i = 3; i <= n; i++) {
		ary[i] = (ary[i - 1] + 2*ary[i - 2]) % 10007;
	}
	cout << ary[n];
}