#include <iostream>
using namespace std;


long long treeNum, useTree = 0;
long long tree[1000000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> treeNum >> useTree;
	long long max = 0;

	for (long long i = 0; i < treeNum; i++)
	{
		cin >> tree[i];

		if (max < tree[i])
			max = tree[i];
			
	}

	long long start = 1, end = max + 1;
	long long temp = 0;
	long long middle = 0;

	while (start < end)
	{
		middle = (start + end) / 2;
		long long result = 0;

		for (long long i = 0; i < treeNum; i++)
		{
			if (tree[i] > middle)
			{
				result += tree[i] - middle;
			}
		}

		if (result >= useTree)
		{
			if (temp < middle)
			{
				temp = middle;
			}
			start = middle + 1;
		}
		else
		{
			end = middle;
		}
	}

	cout << temp;
}