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
	// 1. �湮 ���� ����
	bool isVisited[1001] = { false };

	// 2. DFS�� ����� ������ �����.
	stack<int> st;  // ���ÿ� ������ �湮�� ������ ����ȴ�
	st.push(V); // ù ��°�� �湮�� ����
	isVisited[V] = true;

	while (st.empty() == false) //������ ����ٸ� ��� ������ �湮�� ��
	{
		// 3-1. ������ �湮�Ѵ�
		int node = st.top();
		st.pop();
		cout << node << ' ';

		// 3-2. �������� �湮�� ������ ã�´�
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
	// 1. �湮 ���� ����
	bool isVisited[1001] = { false };

	// 2. DFS�� ����� ������ �����.
	queue<int> que;  // ���ÿ� ������ �湮�� ������ ����ȴ�
	que.push(V); // ù ��°�� �湮�� ����
	isVisited[V] = true;

	while (que.empty() == false) //������ ����ٸ� ��� ������ �湮�� ��
	{
		// 3-1. ������ �湮�Ѵ�
		int node = que.front();
		que.pop();
		cout << node << ' ';

		// 3-2. �������� �湮�� ������ ã�´�
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
	// 1. �׷��� ����
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

	// 2. ���� �������� �湮 ��Ű�� ���� ����
	for (int i = 1; i <= N; ++i)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	// 3. DFS
}