#include <iostream>
//#include <string>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	queue<int> qu;
	string inputCommand;
	int inputNum;
	cin >> inputNum;
	int n;

	for (int i = 0; i < inputNum; i++)
	{
		cin >> inputCommand;

		if (inputCommand == "push")
		{
			cin >> n;
			qu.push(n);
		}
		else if (inputCommand == "pop")
		{
			if (qu.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << qu.front() << "\n";
				qu.pop();
			}
		}
		else if (inputCommand == "size")
		{
			cout << qu.size() << "\n";
		}
		else if (inputCommand == "empty")
		{
			if (qu.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else if (inputCommand == "front")
		{
			if (qu.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << qu.front() << "\n";
			}
		}
		else if (inputCommand == "back")
		{
			if (qu.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << qu.back() << "\n";
			}
		}
	}
}