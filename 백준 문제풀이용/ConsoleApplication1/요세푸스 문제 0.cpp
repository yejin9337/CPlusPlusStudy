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

	int K;
	do
	{
		cin >> K;
	} while (1 > K || K > N);

	cout << "<";
	while (qu.size() != 1)
	{
		for (int i = 1; i < K; i++)
		{
			int temp = qu.front();
			qu.pop();
			qu.push(temp);
		}
		cout << qu.front() << ", ";
		qu.pop();
	}

	for (int i = 1; i < K; i++)
	{
		int temp = qu.front();
		qu.pop();
		qu.push(temp);
	}
	cout << qu.front() << ">";

}