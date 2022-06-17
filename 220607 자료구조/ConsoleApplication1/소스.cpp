#include <iostream>
#include <vector>
using namespace std; // ���Ͱ� std��� �̸����� ���

int main()
{
	// ���� �����ϱ�
	vector<int> vec;
	cout << boolalpha << vec.empty() << endl;
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;

	// �б� / �˻� / ���� / ����
	// ����
	// insert / push_back

	vec.push_back(3);                                                                             
	vec.push_back(4);
	vec.push_back(2);
	// {3 , 4 , 2}

	// �ݺ���
	// begin() : �����̳��� ù ���Ҹ� ����Ű�� �ݺ���
	// end() : �����̳��� ������ ������ ������ ����Ű�� �ݺ���
	// rbegin() : �����̳��� ������ ���Ҹ� ����Ű�� �ݺ���
	// rend() : �����̳��� ù ������ ������ ����Ű�� �ݺ���


	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter) //iter�� �ǵ��� ���� ���������� ����
	{
		cout << *iter << ",";
	}
	cout << endl;
	// end()�� �ǽð����� �޶� �� �� �־ �׳� ȣ���ؼ� ����Ѵ� (�������� ���� ��)

	for (vector<int>::reverse_iterator iter = vec.rbegin(); iter!=vec.rend(); ++iter) // ���ʿ� ���谡 ���������� �Ǿ�����
	{
		cout << *iter << ",";
	}
	cout << endl;


	// insert : pos ������ �����͸� �����Ѵ�
	vector<int>::iterator iter = vec.begin();
	++iter;

	iter = vec.insert(iter, 10); // { 3 , 10 , 4 , 2 }, iter : &vec[1] (10)
	vec.insert(iter, 3, 5); //{ 3, 5 , 5 , 5 , 10 , 4 , 2 }, iter : &vec[1] (5)
	vec.insert(iter, vec.begin() + 3, vec.end() - 1); //{3 5 10 4 5 5 5 10 4 2} , iter : &vec[1] (5)

	//����
	// pop_back : �� ���� �ִ� �����͸� ����
	// vec : {3 5 10 4 5 5 5 10 4 2}
	vec.pop_back();
	vec.pop_back();
	vec.pop_back();
	// {3 5 10 4 5 5 5 }

	// erase : pos�� �ִ� �����͸� ����
	vec.erase(vec.begin()); // {5 10 4 5 5 5 }
	vec.erase(vec.begin() + 1, vec.begin() + 3); // {5 5 5 5 }

	//�б�
	cout << vec.front() << endl; // �� ���� 5
	cout << vec.back() << endl; // �� ���� 5
	cout << vec[2] << endl; //�ι�° 5

	//ã��(�˻�) -> �޼ҵ尡 �ƴ϶� �˰��� ���̺귯���� ����

	//�ٸ� ����
	vector<int> vec2(5); //{0 0 0 0 0}
	vector<int> vec2(10); //{10 10 10 10 10}



	return 0;
}












/* ������ �ּҰ��� �����ΰ����� ������ Ÿ��

&a <- � ������ �޸� �ּ�
�� �ּ� ���� ������ �ִ� ������ Ÿ���� �����ʹ�

�Ű������� �Ű������� ���� ���� �߰�ȣ �ȿ��� ����ȴ� -> �ܺο� ������ ���ش�
�Ű������� �����ͷ� ���� ��� �������� ���� ���� �ٲ��ָ� �޸��� ���� �ٲ�� ������
�Լ� ���ο��� ���� �ٲٴ°� ����������


���ø��� ������ Ÿ�Կ��� �����ο����� ������
���� ����� Ŭ����, ���� ����� �Լ����� �پ��� ������ Ÿ���� ó���� �� �ְ� �ϰ�ʹ�
���� �����̴��� ������ Ÿ���� �ٸ��� �Լ� �������� �������Ѵ�
�׷��� ���ø��� ����
T sum (T a, T b)
{
	return a+b;
}


����� ���� �׽�Ʈ
�ݿ��� �н� ��Ʈ



*/