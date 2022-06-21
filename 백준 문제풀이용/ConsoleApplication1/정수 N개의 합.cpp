#include <iostream>
#include <vector>
using namespace std;

long long sum(vector<int>& a)
{
	long long ans = 0;
	vector<int>::iterator iter;

	for (iter = a.begin(); iter != a.end(); iter++)
	{
		ans += *iter;

	}
	return ans;
}

int main()
{
	vector<int> a;

	sum(a);

}