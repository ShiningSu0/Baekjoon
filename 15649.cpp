#include<iostream>
using namespace std;

void dfs(int row);
int n;
int main() {
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int col[16];
		col[1] = i;
	
		dfs(2);
	}
	cout << ans;
}
void dfs(int row) {
	if (row > n)
}
