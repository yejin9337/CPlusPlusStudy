#include <iostream>
using namespace std;

int main()
{
	int num;
	int count = 1;
	cin >> num;

	while (num >= 6)
	{
		num = num - (6 * count);
		++count;
	}

	if (num % 6 > 1)
	{
		++count;
	}
	cout << count;
}