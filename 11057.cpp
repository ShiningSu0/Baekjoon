#include<iostream>
using namespace std;
int ary[1010][10] = { 0 };
int main() {
	int N;
	cin >> N;
	for (int k = 0; k < 10; k++) {
		ary[1][k] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <10; j++) {
			int a = 0;
			for (int k = j; k < 10; k++) {
				a += ary[i - 1][k];
			}
			ary[i][j] += a%10007;
		}

	}
	int sum = 0;
	for (int j = 0; j < 10; j++) {
		sum += ary[N][j];
	}
	cout << sum;
}

/*#include<iostream>
using namespace std;
int ary[1010][10] = { 0 };
int main() {
	int N;
	cin >> N;
	for (int k = 0; k < 10; k++) {
		ary[1][k] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <10; j++) {

			for (int k = j; k < 10; k++) {
				ary[i][j] += ary[i - 1][k];
			}
		}

	}
	int sum = 0;
	for (int j = 0; j < 10; j++) {
		sum += ary[N][j];
	}
	cout << sum;
}*/