#include<iostream>
#include<vector>
using namespace std;
void swap(int* arr, int a, int b) {
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}
void Quick(int* arr, int start, int end) {
	int pivot = arr[start];
	int left = start + 1;
	int right = end;

	while (left <= right) {
		while (arr[left] < pivot) { left++; }
		while (arr[right] > pivot) { right--; }
		if (left <= right) { swap(arr, left, right); }
	}
	if (start < end) {
		swap(arr, start, right);
		Quick(arr, start, right - 1);
		Quick(arr, right + 1, end);
	}

}

void Partition(int* arr) {
	

}
void Merge(int* arr, int start, int end) {
	
}
e



int main() {

	int N;

	cin >> N;
	int* a = new int[N];
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		a[i] = n;

	}

	Quick(a, 0, N - 1);
	vector<int> b;
	for (int i = 0; i < N; i++) {
		if (a[i] == a[i + 1]) {
			continue;
		}
		b.push_back(a[i]);
	}
	for (auto elem : b) {
		cout << elem << endl;
	}

}