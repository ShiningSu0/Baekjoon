#include<iostream>
#include<queue>
using namespace std;
int ary[1010][1010] = { 0 };
bool visited[1010] = { 0 };
queue<int> q;
int N, M, V;

void dfs(int idx) {
	cout << idx << " ";
	for (int i = 1; i <= N; i++) {
		if (ary[idx][i] == 1 && visited[i] == 0) {
			visited[i] = true;
			dfs(i);
		}
	}
}
void bfs(int idx) {
	q.push(idx);
	visited[idx] = true;
	while (!q.empty()) {
		idx = q.front();
		q.pop();
		cout << idx << " ";
		for (int i = 1; i <= N; i++) {
			if (ary[idx][i] == 1 && visited[i] == 0) {
				visited[i] = true;
				q.push(i);
			}
		}
	}

}
int main() {
	
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		ary[x][y] = 1;
		ary[y][x] = 1;
	}
	visited[V] = 1;

	dfs(V);
	cout << endl;
	memset(visited, false, sizeof(visited));


	bfs(V);
	return 0;

}