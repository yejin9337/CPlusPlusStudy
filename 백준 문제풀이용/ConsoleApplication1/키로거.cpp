#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		//1. ���ڿ��� �Է� �޴´�
		string input;
		cin >> input;

		//2. �����̳� 2���� �����
		// �ϳ��� Ŀ�� ���� �����ϴ� ���ڿ��� ������ ����
		vector<char> left, rightReverse;

		//3. �ٸ� �ϳ��� Ŀ�� ������ �����ϴ� ���ڿ��� �� �������� ����

		for (char ch : input)
		{
			switch ()
			{
			case '<':
				if (false == left.empty())
					rightReverse.push_back(left.back());
					rightReverse.pop_back();
				break;
			case '>':
				if (false == rightReverse.empty())
				{
					left.push_back(rightReverse.back());
					rightReverse.pop_back();
				}
				break;
			case '-':
				if (false == left.empty())
				{
					left.pop_back();
				}
				break;
			default:
				left.push_back(ch);
				break;
			}
		}

	}

	cout << string(left.begin(), left.end()) << string(rightReverse.rbegin(), rightReverse.rend()) << "\n";

}