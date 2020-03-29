#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> vec;
	vector<int> num1;
	vector<int> num1address;
	vector<int> num2;
	vector<int> num2address;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}
	//find min,max
	int min=vec[0], max = 0;
	for (int elem : vec) {
		if (elem < min) {
			min = elem;
		}
		if (elem > max) {
			max = elem;
		}
	}
	//1번째 대표 자연수
	for (int i = min; i <= max; i++) {
		int sum = 0;
		for (auto elem : vec) {
			sum+=abs(elem -i);
		}
		num1.push_back(sum);
		num1address.push_back(i);
	}

	//2번째 대표 자연수
	for (int i = min; i <= max; i++) {
		int sum = 0;
		for (auto elem : vec) {
			sum += pow(abs(elem - i),2);
		}
		num2.push_back(sum);
		num2address.push_back(i);
	}
	//1번째 대표 자연수 출력
	int num1min = num1[0];
	int num1minaddress;

	for (int i = 0; i < num1.size(); i++) {
		if (num1[i] < num1min) {
			num1min = num1[i];
			num1minaddress = i;
		}
	}
	//2번째 대표 자연수 출력
	int num2min = num2[0];
	int num2minaddress;
	for (int i = 0; i < num2.size(); i++) {
		if (num2[i] < num2min) {
			num2min = num2[i];
			num2minaddress = i;
		}
	}
	cout << num1address[num1minaddress] << " " << num2address[num2minaddress];
}