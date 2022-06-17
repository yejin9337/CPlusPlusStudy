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
                std::cout << "������ ���� ������.\n";
            }
        } // �ڵ����� ifs.close()�� ȣ��ȴ�.

        // ���̳ʸ� ���� ���� �ʹٸ� ios::binary�� �Ѱ��ش�.
        std::ofstream of2("temp.bin", std::ios::binary);

        return 0;
    }


    

    //cout << "------------------------\n";
    //cout << setw(12) << left << "|Name" << "|";
    //cout << setw(12) << right << "Age|\n";

    //cout << "------------------------\n";
    //cout << setw(12) << left << "|���缺" << "|";
    //cout << setw(12) << right << "31|\n";

    //cout << setw(12) << left << "|������" << "|";
    //cout << setw(12) << right << "28|\n";

    //cout << setw(12) << left << "|�����" << "|";
    //cout << setw(12) << right << "25|\n";

    //cout << setw(12) << left << "|�赿��" << "|";
    //cout << setw(12) << right << "28|\n";
    //cout << "------------------------\n";


