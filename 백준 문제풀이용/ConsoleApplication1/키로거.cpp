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
		//1. 문자열을 입력 받는다
		string input;
		cin >> input;

		//2. 컨테이너 2개를 만든다
		// 하나는 커서 왼편에 존재하는 문자열로 정방향 저장
		vector<char> left, rightReverse;

		//3. 다른 하나는 커서 오른편에 존재하는 문자열로 역 방향으로 저장

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