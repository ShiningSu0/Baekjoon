#include<iostream>
using namespace std;
#include<vector>
int main() {
	int  N, M;
	cin >> N >> M;
	int num;
	int max=0;
	int a, b, c;
	vector<int> card;
	for (int i = 0; i < N; i++) {
		cin >> num;
		card.push_back(num);
	}
	for (int i = 0; i < card.size(); i++) {
		for (int j = i+1; j < card.size(); j++) {
			for (int k = j+1; k < card.size(); k++) {
				if ((card[i] + card[j] + card[k]) <= M) {
					if ((card[i] + card[j] + card[k]) > max) {
						max = card[i]+ card[j] + card[k];
					}
				}
			}
		}
	}

	cout << max;
}