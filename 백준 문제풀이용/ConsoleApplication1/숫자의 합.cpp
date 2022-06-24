#include <iostream>
#include <cstring>
using namespace std;

int sum(int count)
{
	string input = " ";
	cin >> input;
	int result = 0;

	for (int i = 0; i < count; i++)
	{
		result += (input[i]-48);
	}
	return result;
}

int main()
{
	int count;
	cin >> count;
	cout << sum(count);
}