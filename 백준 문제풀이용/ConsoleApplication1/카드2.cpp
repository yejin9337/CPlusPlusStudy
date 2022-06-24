#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N;
	cin >> N;
	queue<int> qu;
	for (int i = 1; i <= N; i++)
	{
		qu.push(i);
	}

	while(qu.size()!=1)
	{
		qu.pop();
		int temp = qu.front();
		qu.pop();
		qu.push(temp);
	}
	cout << qu.front();
}