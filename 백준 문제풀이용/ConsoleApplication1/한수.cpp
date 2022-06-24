
// 풀긴 했는데 좀 더 확장성 있게 바꿔볼 것

#include <iostream>

using namespace std;

#pragma region 내가 쓴 코드
//
//int hansu(int num)
//{
//	while (num != 0)
//	{
//		int temp = num % 10;
//	}
//}
//
//int main()
//{
//	int inputNum = 0;
//	cin >> inputNum;
//	if (inputNum == 1000)
//	{
//		cout << 144;
//	}
//	else if (inputNum > 99)
//	{
//		hansu(inputNum);
//		cout << hansu(inputNum);
//	}
//	else
//	{
//		cout << inputNum;
//	}
//}

#pragma endregion


#pragma region 다른 사람 코드 (n-1, n, n+1은 (n-1 + n+1) == (2 * n) 이라는 점 이용

int hansu(int n)
{
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i < 100 || (i / 100 + i % 10) == ((i / 10) % 10)* 2)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	int inputNum;
	cin >> inputNum;

	hansu(inputNum);
	cout << hansu(inputNum);
}

#pragma endregion