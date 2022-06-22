#include <iostream>

using namespace std;

void infinite_sequence (bool* arr)
{
	int num = 0;
	int result = 0;
	for (int i = 1; i < 10001; i++)
	{
		num = i;
		result = i;

		while (num != 0)
		{
			if (result > 10000)
			{
				break;
			}
			result += num % 10;
			num = num / 10;
		}
		arr[result] = true;
	}
}

int main()
{
	bool arr[10035] = { false };
	infinite_sequence(arr);

	for (int i = 1; i < 10001; i++)
	{
		if (arr[i] == false)
		{
			cout << i << "\n";
		}
	}
}