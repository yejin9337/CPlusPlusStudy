
// Ǯ�� �ߴµ� �� �� Ȯ�强 �ְ� �ٲ㺼 ��

#include <iostream>

using namespace std;

#pragma region ���� �� �ڵ�
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


#pragma region �ٸ� ��� �ڵ� (n-1, n, n+1�� (n-1 + n+1) == (2 * n) �̶�� �� �̿�

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