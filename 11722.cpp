#include<iostream>
using namespace std;
int ary[1001];
int ans[1001];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ary[i];
	}
	ans[0] = 1;
	int max = ary[0]; int len = 1;
	for (int i = 1; i < N; i++) {
		if (ary[i - 1] > ary[i]) {
			len++;
			ans[i] = len;
			continue;
		}
	
			if (ary[i] > max) {
				max = ary[i];
				len = 1;
				
			}
			ans[i] = ans[i - 1];
		
		
	}
	cout << ans[N-1];
}