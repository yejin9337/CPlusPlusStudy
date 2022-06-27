#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

vector<int> graph[1001];
int N, M, V;

void dfs()
{
	// 1. 방문 여부 저장
	bool isVisited[1001] = { false };

	// 2. DFS에 사용할 스택을 만든다.
	stack<int> st;  // 스택에 앞으로 방문할 정점이 저장된다
	st.push(V); // 첫 번째로 방문할 정점
	isVisited[V] = true;

	while (st.empty() == false) //스택이 비었다면 모든 정점을 방문한 것
	{
		// 3-1. 정점을 방문한다
		int node = st.top();
		st.pop();
		cout << node << ' ';

		// 3-2. 다음으로 방문할 정점을 찾는다
		for (int nextNode : graph[node])
		{
			if (isVisited[nextNode] == false)
			{
				st.push(nextNode);
				isVisited[nextNode] = true;
			}
		}

	}
}

void bfs()
{
	// 1. 방문 여부 저장
	bool isVisited[1001] = { false };

	// 2. DFS에 사용할 스택을 만든다.
	queue<int> que;  // 스택에 앞으로 방문할 정점이 저장된다
	que.push(V); // 첫 번째로 방문할 정점
	isVisited[V] = true;

	while (que.empty() == false) //스택이 비었다면 모든 정점을 방문한 것
	{
		// 3-1. 정점을 방문한다
		int node = que.front();
		que.pop();
		cout << node << ' ';

		// 3-2. 다음으로 방문할 정점을 찾는다
		for (int nextNode : graph[node])
		{
			if (isVisited[nextNode] == false)
			{
				que.push(nextNode);
				isVisited[nextNode] = true;
			}
		}

	}
}

int main()
{
	// 1. 그래프 구성
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> V;
	for (int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;

		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	// 2. 작은 정점부터 방문 시키기 위해 정렬
	for (int i = 1; i <= N; ++i)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	// 3. DFS
}