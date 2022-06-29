#include <string>
#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int map[25][25];
string arr;
bool isVisited[25][25] = {false};

// 반환 값의 의미는 단지 내 집의 개수
//
int dfs(int r, int c)
{
	isVisited[r][c] = true;

	static const int dr[] = { -1, 1, 0, 0 };
	static const int dc[] = { 0, 0, -1, 1 };

	int house = 1;
	for (int i = 0; i < 4; i++)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nr >= N || nc < 0 || nc >= N)
			continue;
		if (isVisited[nr][nc] || map[nr][nc] == 0)
			continue;
		house += dfs(nr, nc);
	}
	return house;
}

int main()
{
	
	cin >> N;
	//for (int r = 0; r < N; ++r)
	//{
	//	for (int c = 0; c < N; ++c)
	//	{
	//		cin >> map[r][c];
	//	}
	//}
	for (int c = 0; c < N; ++c)
	{
		cin >> arr; 
		for (int r = 0; r < N; ++r)
		{
			map[c][r] = arr[r]-48;
		}
	}

	

	//3. 단지 수와 단지 내 집의 개수를 구한다
	int complexCount = 0;
	vector<int> house;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			if (1 == map[r][c] && isVisited[r][c] == false)
			{
				int result = dfs(r, c);
				house.push_back(result);
				++complexCount;
			}
		}
	}
	sort(house.begin(), house.end());
	cout << complexCount << "\n";
	for (int i = 0; i < complexCount; i++)
	{
		cout << house[i]<<"\n";
	}

	//3-1. 방문 여부를 저장할 배열을 정의한다
	

	//3-2. 다음에 방문 할 곳을 스택에 저장한다

}