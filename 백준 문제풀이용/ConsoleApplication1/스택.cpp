#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	string inputCommand;
	int inputNum;
	
	stack<int> st;

	for(int i =0; i < N; i++)
	{
		cin >> inputCommand;
	
		if (inputCommand == "push")
		{
			cin >> inputNum;
			st.push(inputNum);		
		}
		else if (inputCommand == "pop")
		{
			if (st.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << st.top() << '\n';
				st.pop();
			}
		}
		else if (inputCommand == "size")
		{
			cout << st.size() << '\n';
		}
		else if (inputCommand == "empty")
		{
			if (st.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else if (inputCommand == "top")
		{
			if (st.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << st.top() << '\n';
			}
		}			
	}
}