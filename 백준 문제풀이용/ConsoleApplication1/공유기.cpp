#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long house_x[10000];
	long long houseNum, wifiNum = 0;
	cin >> houseNum >> wifiNum;

	for (long long i = 0; i < houseNum; i++)
	{
		cin >> house_x[i];
	}
	
	

	long long start = 1;
	long long end = house_x[houseNum-1] + 1;
	long long count = 0;
	long long result = 0;

	while (start < end)
	{
		long long mid = (start + end) / 2;

		for (long long i = 0; i < houseNum; i++)
		{
			result = house_x[i] - mid;
			if (result < 0)
			{
				-(result);
			}

			if (mid - start < result)
			{
				++count;
			}
		}

		if (count < wifiNum)
		{
			end = mid;
		}
		else
		{
			if (result < mid)
			{
				result = mid;
				start = mid + 1;
			}
		}
	}
	cout << result;
}