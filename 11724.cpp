#include<iostream>
//using namespace std;
/*
int ary[1010][1010] = { 0 };
bool visited[1010] = { 0 };
int N, M;
int count = 0;
void dfs(int index) {
	int c = 0;

	for (int i = 1; i <= N; i++) {
		
		if (ary[index][i] && !visited[i]) {
			visited[i] = true;
			c++;
			dfs(i);
		}
	}

	if (c == 0) {
		if (index <= N-1) {
			dfs(index + 1);
			count += 1;
		}
	}
}
int main() {

	std::cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		std::cin >> u >> v;
		ary[u][v] = 1;
		ary[v][u] = 1;

	}
	dfs(1);
	std::cout << count;
}
*/
//정답

#include <iostream>

#include <vector>

using namespace std;



const int MAX = 1000 + 1;



int M, N;

vector<int> graph[MAX];

bool visited[MAX];



//전형적인 DFS

void DFS(int node)

{

    visited[node] = true;



    for (int i = 0; i < graph[node].size(); i++)

    {

        int next = graph[node][i];

        //node에 연결된 다른 정점을 모두 방문

        //이미 방문했다면 방문하지 않는다

        if (!visited[next])

            DFS(next);

    }

}



int main(void)

{

    cin >> N >> M;



    for (int i = 0; i < M; i++)

    {

        int node1, node2;

        cin >> node1 >> node2;



        //undirected graph

        graph[node1].push_back(node2);

        graph[node2].push_back(node1);

    }



    int cnt = 0;

    for (int i = 1; i <= N; i++)

        if (!visited[i])

        {

            DFS(i);

            cnt++;

        }



    cout << cnt << endl;

    return 0;

}

