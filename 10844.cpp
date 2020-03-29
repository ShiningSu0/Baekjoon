
/*#include<iostream>
using namespace std;
#include<string>
int main() {
	int N;
	cin >> N;
	//자리수 1인 경우 배제
	int count = 0;
	
	if (N == 1) {
		count = 9;
	}
	else {
		for (int i = pow(10, N - 1); i < pow(10, N); i++) {
			string s = to_string(i);
			
			
			int check = 0;
			for (int j = 0; j < N - 1; j++) {


				if (!(int(s[j])==int(s[j+1])+1|| int(s[j]) == int(s[j + 1]) - 1))
				{
					check++;
				}
			}
			if (check == 0) {
					count++;
				}


		}
	}


	cout << count;
}
*/

#include <iostream>
using namespace std;

int d[101][10];

int main() {

	int n;
	long long sum = 0;
	const int mod = 1000000000;
	cin >> n;
	for (int j = 1; j < 10; j++)
		d[1][j] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 9){ d[i][j] = d[i - 1][j - 1];
			cout << "1 :" << d[i][j] << endl;
		}else if (j == 0) {
				d[i][j] = d[i - 1][j + 1];
				cout << "2 :" << d[i][j] << endl;
			}
			else {
				d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % mod;
				cout << "3 :" << d[i][j] << endl;
			}
		}
	}

	for (int i = 0; i < 10; i++)
		sum += d[n][i];

	cout << sum % mod;

	return 0;
}
