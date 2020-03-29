#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
bool cmp(char a, char b)

{

	if (a > b)

		return true;

	return false;

}
int main() {
	string N;
	cin >> N;
	string s;
	
	int sum = 0;
	for (auto elem : N) {
		sum += int(elem);
	}
	if (N.find("0") == -1 || sum % 3 != 0) {
		cout << -1;
		exit(100);
	}
	else {
		sort(N.begin(), N.end(), cmp);
		cout << N;
	}

}