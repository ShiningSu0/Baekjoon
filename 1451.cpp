#include<iostream>
using namespace std;
#include<vector>
int ary[101][101] = { 0 };

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char s;
			cin >> s;
			ary[i][j] += (s - '0');
		}
	}
	//case1
	//i,j가 구분선의 역할
	vector<long long> findmax;
	
	long long s11=0, s12=0, s13=0, sum = 0;
	
	for (int i = 1; i <= M - 2; i++) {
		for (int j = i + 1; j <= M - 1; j++) {
			//s1

			for (int a = 0; a < N; a++) {
				for (int b = 0; b < i; b++) {
					s11 += ary[a][b];
				}
			}
			//s2

			for (int a = 0; a < N; a++) {
				for (int b = i; b < j; b++) {
					s12 += ary[a][b];
				}
			}
			//s3
			for (int a = 0; a < N; a++) {
				for (int b = j; b < M; b++) {
					s13 += ary[a][b];
				}
			}
			sum = s11 * s12 * s13;
			findmax.push_back(sum);
			s11 = 0, s12 = 0, s13 = 0,sum=0;
		}
	}
	

		//case2
	
		long long s21 = 0, s22 = 0, s23 = 0, sum2 = 0;
		for (int i = 1; i <= N - 2; i++) {
			for (int j = i + 1; j <= N - 1; j++) {
				//s21
				
				for (int a = 0; a < i; a++) {
					for (int b = 0; b < M; b++) {
						s21 += ary[a][b];
					}
				}
				//s2

				for (int a = i; a < j; a++) {
					for (int b = 0; b < M; b++) {
						s22 += ary[a][b];
					}
				}
				//s3
				for (int a = j; a < N; a++) {
					for (int b = 0; b < M; b++) {
						s23 += ary[a][b];
					}
				}
				sum2 = s21 * s22 * s23;
				
				findmax.push_back(sum2);
				s21 = 0, s22 = 0, s23 = 0,sum2=0;
			}
		}
	
	//case3
		long long s31 = 0, s32 = 0, s33 = 0, sum3 = 0;
		for (int i = 1; i <= N - 1; i++) {
			for (int j = 1; j <= M - 1; j++) {
				//s31
				for (int a = 0; a < i; a++) {
					for (int b = 0; b < j; b++) {
						s31 += ary[a][b];
					}
				}
				//s32
				for (int a = 0; a < i; a++) {
					for (int b = j; b < M; b++) {
						s32 += ary[a][b];
					}
				}
				//s33
				for (int a = i; a < N; a++) {
					for (int b = 0; b < M; b++) {
						s33 += ary[a][b];
					}
				}
				sum3 = s31 * s32 * s33;
				findmax.push_back(sum3);
				s31 = 0, s32 = 0, s33 = 0,sum3=0;
			}
		}
	//case4
		long long s41 = 0, s42 = 0, s43 = 0, sum4 = 0;
		for (int i = 1; i <= N - 1; i++) {
			for (int j = 1; j <= M - 1; j++) {
				//s41
				for (int a = i; a < N; a++) {
					for (int b = 0; b < j; b++) {
						s41 += ary[a][b];
					}
				}
				//s42
				for (int a = i; a < N; a++) {
					for (int b = j; b < M; b++) {
						s42 += ary[a][b];
					}
				}
				//s43
				for (int a = 0; a < i; a++) {
					for (int b = 0; b < M; b++) {
						s43 += ary[a][b];
					}
				}
				sum4 = s41 * s42 * s43;
				findmax.push_back(sum4);
				s41 = 0, s42 = 0, s43 = 0,sum4=0;
			}
		}
		//case5
		long long s51 = 0, s52 = 0, s53 = 0, sum5 = 0;
		for (int i = 1; i <= N - 1; i++) {
			for (int j = 1; j <= M - 1; j++) {
				for (int a = 0; a < i; a++) {
					for (int b = 0; b < j; b++) {
						s51 += ary[a][b];
					}
				}
				for (int a = i; a < N; a++) {
					for (int b = 0; b < j; b++) {
						s52 += ary[a][b];
					}
				}
				for (int a = 0; a < N; a++) {
					for (int b = j; b < M; b++) {
						s53 += ary[a][b];
					}
				}
				sum5 = s51 * s52 * s53;
				findmax.push_back(sum5);
				s51 = 0, s52 = 0, s53 = 0,sum5=0;
			}
		}
		//case6
		long long s61 = 0, s62 = 0, s63 = 0, sum6 = 0;
		for (int i = 1; i <= N - 1; i++) {
			for (int j = 1; j <= M - 1; j++) {

				for (int a = 0; a < i; a++) {
					for (int b = j; b < M; b++) {
						s61 += ary[a][b];
					}
				}
				for (int a = i; a < N; a++) {
					for (int b = j; b < M; b++) {
						s62 += ary[a][b];
					}
				}
				for (int a = 0; a < N; a++) {
					for (int b = 0; b < j; b++) {
						s63 += ary[a][b];
					}
				}
				sum6 = s61 * s62 * s63;
				
				findmax.push_back(sum6);
				s61 = 0, s62 = 0, s63 = 0,sum6=0;
			}
		}

		long long finalmax=0;
		for (auto elem : findmax) {
			if (elem > finalmax) {
				finalmax = elem;
			}
		}
		cout << finalmax;


}
	
