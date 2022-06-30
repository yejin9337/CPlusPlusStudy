#include <utility>
#include <iostream>
#include <queue>
using namespace std;

int M, N;
int tomatoState[1000][1000];

using Coord = pair<int, int>;
enum 
{
	EMPTY = -1,
	TOMATO,
	RIPENED
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 1. M, N을 입력받는다
	cin >> M >> N;

	//2. 토마토 상자의 정보를 입력 받는다	
	queue<Coord> que;
	int tomatoCount = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> tomatoState[y][x];

			if (tomatoState[y][x] == RIPENED)
			{
				que.emplace(y, x);
			}
			else if (tomatoState[y][x] == TOMATO)
			{
				++tomatoCount;
			}
		}
	}

	if (tomatoCount == 0)
	{
		cout << 0;
		return 0;
	}

	// 3. 토마토 숙성
	int oneDay = 0;
	while (false == que.empty())
	{
		const int size = que.size();
		for (int i = 0; i < size; ++i)
		{
			int y = que.front().first;
			int x = que.front().second;
			que.pop();

			const int dy[] = { -1, 1, 0, 0 };
			const int dx[] = { 0, 0, -1, 1 };
			
			for (int i = 0; i < 4; i++)
			{
				const int ny = y + dy[i];
				const int nx = x + dx[i];

				if (ny < 0 || ny >= N || nx < 0 || nx > M)
					continue;
				if (tomatoState[ny][nx] == TOMATO)
				{
					que.emplace(ny, nx);
					tomatoState[ny][nx] = RIPENED;
					--tomatoCount;
				}
			}
		}
		++oneDay;
	}

	if (tomatoCount > 0)
		cout << -1;
	else
		cout << oneDay - 1;
	
}