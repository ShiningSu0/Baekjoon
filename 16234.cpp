#include<iostream>
using namespace std;
int ary[50][50] = { 0 };
int main() {
	int N, L, R;
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ary[i][j];
		}
	}
	int count = 0;
	bool border = true; int temp; 
	while (border) {int a = 0;
		for (int i = 0; i < N-1; i++) {
			for (int j = 0; j < N-1; j++) {
				
				if (abs(ary[i][j] - ary[i][j + 1]) >= L && abs(ary[i][j] - ary[i][j + 1]) <= R) {
					temp= (ary[i][j] + ary[i][j + 1]) / 2;
					ary[i][j] = temp;
					ary[i][j + 1] = temp;
					++a;
				}
				if (abs(ary[i][j] - ary[i + 1][j]) >= L && abs(ary[i][j] - ary[i + 1][j]) <= R) {
					temp = (ary[i][j] + ary[i+1][j]) / 2;
					ary[i][j] = temp;
					ary[i+1][j] = temp;
					++a;
					}
			}
		}
		if (a == 0) {
			break;
		}
		count++;
	}
	cout << count;
}