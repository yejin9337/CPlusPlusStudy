#include <iostream>
#include <limits.h>
using namespace std;

long long K, N;
long long arr[10000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> K >> N;

	long long max = 0;

	for (long long i = 0; i < K; ++i)
	{
		cin >> arr[i];
		if (max <= arr[i])
		{
			max = arr[i];
		}
	}

	long long s = 1, e = max+1;
	long long result = 0;
	while (s < e)
	{
		long long m = (s + e) / 2;

		long long count = 0;
		for (long long i = 0; i < K; i++)
		{
			count += arr[i] / m;
		}

		if (count >= N)
		{
			if (result < m)
			{
				result = m;
			}

			s = m + 1;
		}
		else
		{
			e = m;
		}
	}
	cout << result;
}