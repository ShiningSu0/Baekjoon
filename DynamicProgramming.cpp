#include<iostream>
using namespace std;
#include<string>
int memo[100];
int fibonacci(int n) {
	if (n <= 1)
		return n;
	if (memo[n] != 0)
		return memo[n];
	memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
	return memo[n];
}

int fibonacci2(int n) {
	if (n <= 2) {
		return 1;
	}
	else
		return fibonacci2(n - 1) + fibonacci2(n - 2);
}
int main() {
	cout << fibonacci(4);
}
