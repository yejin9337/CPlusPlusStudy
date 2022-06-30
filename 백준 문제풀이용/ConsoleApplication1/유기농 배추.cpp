#include <iostream>
using namespace std;

int testCase, M, N, K = 0;

void dfs(int y, int x, int (*baechuField)[50], bool(*visited)[50])
{
	visited[y][x] = true;
	static const int dy[] = { -1, 1, 0, 0 };
	static const int dx[] = { 0, 0, -1, 1 };

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;
		if (visited[ny][nx] || baechuField[ny][nx] == 0)
			continue;
		dfs(ny, nx, baechuField, visited);
	}
}

int main()
{
	cin >> testCase;

	for (int j = 0; j < testCase; j++)
	{	
		cin >> M >> N >> K;

		int baechuField[50][50] = { 0 };
		bool visited[50][50] = { false };
		int coord_x;
		int coord_y;
		for (int i = 0; i < K; i++)
		{
			cin >> coord_x >> coord_y;
			baechuField[coord_y][coord_x] = 1;
		}

		int earthWormCount = 0;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (baechuField[y][x] == 1 && visited[y][x] == false)
				{
					dfs(y, x, baechuField, visited);
					++earthWormCount;
				}
			}
		}

		cout << earthWormCount << "\n";
	}
}