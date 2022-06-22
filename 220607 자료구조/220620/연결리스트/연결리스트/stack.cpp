#include <stack> // std::stack�� ���� ���
#include <iostream>

int main()
{
    std::stack<int> s;

    // ����
    for (int i = 1; i <= 5; ++i)
    {
        s.push(i); // push() : ���ÿ� �����͸� �����Ѵ�.
    }
    // s { 5, 4, 3, 2, 1 }

    // �����̳� ����ʹ� �ݺ��ڰ� �������� �ʴ´�.
    //  => ��ȸ �뵵�� ������� �ʱ� �����̴�.

    // ����
    s.pop(); // pop() : ������ ������ ���� ������.
    // s { 4, 3, 2, 1 }

    // �б�
    std::cout << "stack.top() : " << s.top() << "\n";
    // top() : ���� ���������� ���Ե� ���Ҹ� �����´�.

    // ũ��
    if (s.empty())
    {
        std::cout << "stack is empty\n";
    }
    std::cout << "stack.size() : " << s.size() << "\n";
    // size() : ���� ������ ������ ��ȯ�Ѵ�.
}
