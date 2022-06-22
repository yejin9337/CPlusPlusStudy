#include <iostream>
#include <string>
#include <list>

using namespace std;


int main()
{
	//0. ����� �ӵ��� ����Ų��
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//1. ���ڿ��� �Է� �޴´�.
	string s;
	cin >> s;

	//2. ��ɾ��� ������ �Է� �޴´�
	int m;
	cin >> m;

	//3. ��ɾ ó���Ѵ�
	list<char> lst(s.begin(), s.end());
	list<char>::iterator cursor = lst.end();

	while (m--)
	{
		//3-1. ��ɾ �Է� �޴´�
		char op;
		cin >> op;

		//3-2. ��ɾ �°� �����Ѵ�
		switch (op)
		{
		case 'L':
			if (cursor != lst.begin())
				--cursor;			
			break;
		case 'D':
			if (cursor != lst.end())
				++cursor;
			break;
		case 'B':
			// ���ڸ� ���� �� Ŀ�� ��ġ ������Ʈ �ʿ���
			if (cursor != lst.begin())
			{
				--cursor;
				cursor = lst.erase(cursor);
			}
			break;
		case 'P':
			char param;
			cin >> param;

			cursor = lst.insert(cursor, param);
			++cursor;
			break;
		}
	}

	//���
	for (list<char>::iterator iter = lst.begin(); iter != lst.end(); ++iter)
	{
		cout << *iter;
	}
}