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
		oss << "이 학생은 안경을 썼습니다\n";
	}
	else
	{
		oss << "안경 안 씀\n";
	}

	if (student.Gender == Female)
	{
		oss << "여자\n";
	}
	else
	{
		oss << "남자\n";
	}

	if (student.IsCodingGosu)
	{
		oss << "개고수\n";
	}
	else
	{
		oss << "초보\n";
	}
		oss << student.Age <<"\n";
		return oss;
}

int main()
{
	unordered_map<string, Student> hashTable;

	hash<string> hash;
	size_t value = hash("dsjflkjalfk;jas;lkjlfja");

	hashTable["최서연"] = { false, Female, true, 22 };
	cout << hashTable["최서연"];
	hashTable["이수연"] = { false, Female, false, 26 };
	cout << hashTable["이수연"];
}