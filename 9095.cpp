#include<iostream>
using namespace std;
int ary[12] = { 0 };
	
int main() {
	int T, n;
	ary[1] = 1;
	ary[2] = 2;
	ary[3] = 4;

	cin >> T;
	int* ary2= new int[T];
	for (int i = 0; i < T; i++) {
		cin >> n;
		ary2[i] = n;
		
	}
	for (int j = 4; j <= 11; j++) {
		ary[j] = ary[j - 1] + ary[j - 2] + ary[j - 3];
	}
	for (int i = 0; i < T; i++) {
		cout << ary[ary2[i]] << endl;
	}

}