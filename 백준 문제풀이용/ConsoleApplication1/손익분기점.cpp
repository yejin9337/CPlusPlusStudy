#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int result;
    
    if (b >= c)
    {
        cout << "-1";
    }
    else
    {
        result = (a / (c - b)) + 1;
        cout << result;
    }
}