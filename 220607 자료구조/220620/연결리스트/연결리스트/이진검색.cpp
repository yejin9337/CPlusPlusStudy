#include <algorithm>
#include <iostream>

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // std::binary_search�� ���� �˻����� �־��� ���� ã�´�.
    if (std::binary_search(arr, arr + 10, 3))
    {
        std::cout << "arr���� 3�� �����Ѵ�.\n";
    }

    int arr2[] = { 1, 2, 4, 5, 5, 6 };

    // std::lower_bound�� ���� �˻�����
    // element >= value�� ������ �����ϴ� ���� ã�´�.
    std::cout << "\n[lower_bound]\n";
    for (int i = 0; i < 8; ++i)
    {
        int* lowerBound = std::lower_bound(arr2, arr2 + 6, i);

        std::cout << i << " <= ";
        if (lowerBound == arr2 + 6)
        {
            std::cout << "not found\n";
        }
        else
        {
            std::cout << *lowerBound << " at index " << lowerBound - arr2 << "\n";
        }
    }

    // std::upper_bound�� ���� �˻�����
    // element > value�� ������ �����ϴ� ���� ã�´�.
    std::cout << "\n[upper_bound]\n";
    for (int i = 0; i < 8; ++i)
    {
        int* upperBound = std::upper_bound(arr2, arr2 + 6, i);

        std::cout << i << " < ";
        if (upperBound == arr2 + 6)
        {
            std::cout << "not found\n";
        }
        else
        {
            std::cout << *upperBound << " at index " << upperBound - arr2 << "\n";
        }
    }

    // std::equal_range�� ���� �˻�����
    // value�� ���� ������ ������ ã�´�.
    std::cout << "\n[equal_range]\n";
    // pair�� �ܼ��� 2������ �����͸�
    // ���� �� �ִ� Ÿ���̴�.
    std::pair<int*, int*> range = std::equal_range(arr2, arr2 + 6, 5);
    if (range.first == arr2 + 3 && range.second == arr2 + 5)
    {
        std::cout << "arr2���� 5�� �ִ� ���� arr2�� �� ��° ���Һ��� �� ��° ���ұ�����.\n";
    }

}
