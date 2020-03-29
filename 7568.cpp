#include<iostream>
#include<vector>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> X;
	vector<int> Y;
	vector<int> score;
	int x, y;
	for (int i = 1; i <= N; i++) {
		cin >> x >> y;
		X.push_back(x);
		Y.push_back(y);
	}



	for (int i = 0; i < X.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < X.size() - 1; j++) {
			if (X[i] > X[j + 1] && Y[i] > Y[j + 1]) {
				cnt++;
			}
			else if (X[i] < X[j + 1] && Y[i] < Y[j + 1]) {
				cnt--;
			}
			else {

			}
		}
		score.push_back(cnt);
	}

	vector<int> rank;
	for (int i = 0; i < score.size(); i++) {
		int r = 1;
		for (int j = 0; j < score.size(); j++) {

			if (score[i] < score[j]) {
				r++;
			}

		}
		rank.push_back(r);
	}
	for (auto elem : rank) {
		cout << elem << ' ';
	}
}