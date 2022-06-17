#include <iostream>
#include <fstream> // ���� ������� ���� �����.
#include <string>
#include <iomanip>  // ����°� ���õ� ������ ���� �����.
using namespace std;

int main()
{
    // ���� ����� ofstream�� �̿��Ѵ�.
    std::ofstream of("temp.txt");

    // ������ ǥ�� ���ϰ� ����ϴ�.
    of << "Hello World!";

    // close()�� ��������� ������ ���� �� �ִ�.
    // ���� ���� ���� �ʾƵ� �Ҹ��ڿ��� �ڵ����� ȣ���Ѵ�.
    of.close();

    {
        // ���� �Է��� ifstream�� �̿��Ѵ�.
        std::ifstream ifs;

        // is_open()���� ������ �������� Ȯ���� �� �ִ�.
        if (false == ifs.is_open())
        {
            // open()���� ������ �� �� �ִ�.
            ifs.open("temp.txt");
        }

        std::string str;
        std::getline(ifs, str);
        std::cout << str << "\n";

        // eof()�� ������ ���� �����ߴ��� �� �� �ִ�.
        if (ifs.eof())
        {
            std::cout << "������ ���� ������.\n\n\n";
        }
    } // �ڵ����� ifs.close()�� ȣ��ȴ�.

    // ���̳ʸ� ���� ���� �ʹٸ� ios::binary�� �Ѱ��ش�.
    std::ofstream of2("temp.bin", std::ios::binary);

    const char* Name[4] = { "���缺", "������", "������", "�̼���" };
    const int Age[4] = { 31, 28, 27, 26 };

    printf("---------------------------\n");
    printf("|%-12s|%12s|\n", "Name", "Age");
    printf("---------------------------\n");
    for (int i = 0; i < 4; i++)
    {
    printf("|%-12s|%12d|\n", Name[i], Age[i]);
    }
    printf("---------------------------\n");

    
    cout << "\n\n";

    cout << "---------------------------\n";
    cout << "|" << setw(12) << left << "Name" << "|";
    cout << setw(12) << right << "Age" <<"|\n";

    cout << "---------------------------\n";
    cout << "|" << setw(12) << left << "���缺" << "|";
    cout << setw(12) << right << "31" << "|\n";

    cout << "|" << setw(12) << left << "������" << "|";
    cout << setw(12) << right << "28" << "|\n";

    cout << "|" << setw(12) << left << "������" << "|";
    cout << setw(12) << right << "27" << "|\n";

    cout << "|" << setw(12) << left << "�̼���" << "|";
    cout << setw(12) << right << "26" << "|\n";
    cout << "---------------------------\n";
}



