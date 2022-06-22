
// 풀긴 했는데 좀 더 확장성 있게 바꿔볼 것

#include <iostream>

using namespace std;

int hansu(int num)
{
	int han = 99;
	int j = 100;
	while (j <= num)
	{
		int arr[3];
		int temp = j;
		for (int i = 0; i < 3; i++)
		{
			arr[i] = temp % 10;
			temp = temp / 10;

		}

		if ((arr[1] - arr[0]) == (arr[2] - arr[1]))
		{
			++han;
		}
		j++;
	}
	return han;
}

int main()
{
	int inputNum = 0;
	cin >> inputNum;
	if (inputNum == 1000)
	{
		cout << 144;
	}
	else if (inputNum > 99)
	{
		hansu(inputNum);
		cout << hansu(inputNum);
	}
	else
	{
		cout << inputNum;
	}
}