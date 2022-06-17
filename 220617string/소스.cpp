#include <iostream>
#include <fstream> // 파일 입출력을 위한 헤더다.
#include <string>
#include <iomanip>  // 입출력과 관련된 조작을 위한 헤더다.
using namespace std;

    int main()
    {
        // 파일 출력은 ofstream을 이용한다.
        std::ofstream of("temp.txt");

        // 사용법은 표준 파일과 비슷하다.
        of << "Hello World!";

        // close()로 명시적으로 파일을 닫을 수 있다.
        // 물론 굳이 하지 않아도 소멸자에서 자동으로 호출한다.
        of.close();

        {
            // 파일 입력은 ifstream을 이용한다.
            std::ifstream ifs;

            // is_open()으로 파일을 열었는지 확인할 수 있다.
            if (false == ifs.is_open())
            {
                // open()으로 파일을 열 수 있다.
                ifs.open("temp.txt");
            }

            std::string str;
            std::getline(ifs, str);
            std::cout << str << "\n";

            // eof()로 파일의 끝에 도달했는지 알 수 있다.
            if (ifs.eof())
            {
                std::cout << "파일의 끝에 도달함.\n";
            }
        } // 자동으로 ifs.close()가 호출된다.

        // 바이너리 모드로 열고 싶다면 ios::binary를 넘겨준다.
        std::ofstream of2("temp.bin", std::ios::binary);

        return 0;
    }


    

    //cout << "------------------------\n";
    //cout << setw(12) << left << "|Name" << "|";
    //cout << setw(12) << right << "Age|\n";

    //cout << "------------------------\n";
    //cout << setw(12) << left << "|김재성" << "|";
    //cout << setw(12) << right << "31|\n";

    //cout << setw(12) << left << "|용준헌" << "|";
    //cout << setw(12) << right << "28|\n";

    //cout << setw(12) << left << "|김재민" << "|";
    //cout << setw(12) << right << "25|\n";

    //cout << setw(12) << left << "|김동현" << "|";
    //cout << setw(12) << right << "28|\n";
    //cout << "------------------------\n";


