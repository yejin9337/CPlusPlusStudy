#include<iostream>
using namespace std;

int main()
{
	string a , b, c;
	cin >> a >> b;

	int _size;
	if (a.size() > b.size())
	{
		_size = a.size();
	}
	else if (a.size() < b.size())
	{
		_size = b.size();
	}
	else
	{
		_size = b.size();
	}



	for (int i = 0; i < _size; i++)
	{
		int temp = (a[i] - '0') + (b[i] - '0');
		
		if (temp > 9)
		{
			
			temp = temp % 10;
			c += (char)temp + '0';
		}
		else
		{
			c+= (char)temp + '0';
		}
	}
			cout << c;
}