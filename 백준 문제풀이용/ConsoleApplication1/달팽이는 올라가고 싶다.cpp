#include <iostream>
using namespace std;

int main()
{
	int A, B, V;
	int goodMorning = 1;
	cin >> A >> B >> V;

	goodMorning += (V - A) / (A - B);
	if (A >= V)
		cout << "1";
	else if ((V - A) % (A - B) == 0)
		cout << goodMorning;
	else
		cout << goodMorning + 1;
}