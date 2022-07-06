#include <unordered_map>
#include <string>
#include <iostream>
enum Gender{ Male, Female};

struct Student
{
	bool IsOnGlasses;
	Gender Gender;
	bool IsCodingGosu;
	int Age;

};

using namespace std;

ostream& operator << (ostream& oss, const Student& student)
{
	oss << "-----------------------------------\n";
	if (student.IsOnGlasses)
	{
		oss << "�� �л��� �Ȱ��� ����ϴ�\n";
	}
	else
	{
		oss << "�Ȱ� �� ��\n";
	}

	if (student.Gender == Female)
	{
		oss << "����\n";
	}
	else
	{
		oss << "����\n";
	}

	if (student.IsCodingGosu)
	{
		oss << "�����\n";
	}
	else
	{
		oss << "�ʺ�\n";
	}
		oss << student.Age <<"\n";
		return oss;
}

int main()
{
	unordered_map<string, Student> hashTable;

	hash<string> hash;
	size_t value = hash("dsjflkjalfk;jas;lkjlfja");

	hashTable["�ּ���"] = { false, Female, true, 22 };
	cout << hashTable["�ּ���"];
	hashTable["�̼���"] = { false, Female, false, 26 };
	cout << hashTable["�̼���"];
}