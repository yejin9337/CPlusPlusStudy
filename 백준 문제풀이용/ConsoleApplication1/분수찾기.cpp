#include <iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;

	bool exit = false;
	int count = 0;
	int k = 1;
	
	while(exit == false)
	{
		for (int i = k; i >= 1; i--)
		{

			count++;
			if (count == num)
			{
				cout << i;
				exit = true;
				break;
			}
		}
		k++;

		if (exit == false)
		{
			for (int i = 1; i <= k; i++)
			{
				count++;
				if (count == num)
				{
					cout << i;
					exit = true;
					break;
				}
			}
			k++;
		}
	}

	cout << "/";

	count = 0;
	k = 1;
	while (exit == true)
	{
		for (int i = 1; i <= k; i++)
		{
			count++;
			if (count == num)
			{
				cout << i;
				exit = false;
				break;
			}
		}
		k++;

		if (exit == true)
		{
			for (int i = k; i >= 1; i--)
			{
				count++;
				if (count == num)
				{
					cout << i;
					exit = false;
					break;
				}
			}
			k++;
		}
	}
}