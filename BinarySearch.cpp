#include<iostream>
using namespace std;

int BinarySearch(int* ary, int num, int val) {
	int first = 0;
	int last = num - 1;
	while (first<=last) {
		int key = (first + last) / 2;
		if (ary[key] == val) {
			return key;
		}
		else if (ary[key] > val) {
			last =key-1;
		}
		else {
			first = key+1;
			
		}
	}
	cout << "그 값의 요소가 없습니다.";
	exit(100);
}
int main() {
	int num;
	cout << "요솟수 : ";
	cin >> num;
	int* ary = new int[num];
	cout << "오름차순으로 입력하세요." << endl;
	for (int i = 0; i < num; i++) {
		cout << "x[" << i << "] : ";
		cin >> ary[i];
		if(i)
	}
	int val;
	cout << "검색할 값 : ";
	cin >> val;
	cout << val << "은 x[" << BinarySearch(ary, num, val) << "]에 있습니다.";
	
}