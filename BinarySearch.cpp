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
	cout << "�� ���� ��Ұ� �����ϴ�.";
	exit(100);
}
int main() {
	int num;
	cout << "��ڼ� : ";
	cin >> num;
	int* ary = new int[num];
	cout << "������������ �Է��ϼ���." << endl;
	for (int i = 0; i < num; i++) {
		cout << "x[" << i << "] : ";
		cin >> ary[i];
		if(i)
	}
	int val;
	cout << "�˻��� �� : ";
	cin >> val;
	cout << val << "�� x[" << BinarySearch(ary, num, val) << "]�� �ֽ��ϴ�.";
	
}