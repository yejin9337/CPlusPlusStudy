#include <forward_list> // std::forward_list를 쓰기 위한 헤더
#include <iostream>
using namespace std;

int main()
{
    std::forward_list<int> Tonkatsu = {1, 2, 3, 4};

    Tonkatsu.push_front(1);

    std::cout << Tonkatsu << endl;
       

}
