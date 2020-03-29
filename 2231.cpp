#include<iostream>
using namespace std;
int creator(int n) {
	int num=0;
	num += n;
	while (n) {
		num += (n % 10);
		n /= 10;
	}
	return num;
}
int main() {
	int N;
	int cnt = 0;
	cin >> N;
	for (int i = 1; i < N; i++) {
		if (creator(i) == N) {
			cout << i;
			cnt++;
			break;
		}
		
	}
	if (cnt == 0) {
		cout << 0;
		return 0;
	}
}