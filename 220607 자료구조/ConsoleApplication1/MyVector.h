#pragma once

#include <utility>

class MyVector
{
public:
    // �⺻ ������
    MyVector() = default;

    // count��ŭ ������ �Ҵ�� ������
    explicit MyVector(size_t count)
        : _container(new int[count]), _size(count), _capacity(count)
    {
        for (size_t i = 0; i < count; ++i)
        {
            _container[i] = 0;
        }
    }

    // ���� ������. ���� ����(deep copy)�� �̷����� �Ѵ�.
    MyVector(const MyVector& other)
        : _container(new int[other._capacity]), _size(other._size), _capacity(other._capacity)
    {
        for (size_t i = 0; i < _size; ++i)
        {
            _container[i] = other._container[i];
        }
    }

    // �Ҵ� ������. ���� ����(deep copy)�� �̷����� �Ѵ�.
    MyVector& operator=(MyVector rhs)
    {
        std::swap(_container, rhs._container);
        std::swap(_size, rhs._size);
        std::swap(_capacity, rhs._capacity);

        return *this;
    }

    // �Ҹ���
    ~MyVector()
    {
        clear();
    }

    // ù ��° ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    int* begin()
    {
        // ���Ͱ� ����ִٸ� end()�� ��ȯ�ϰ�
        if (empty())
        {
            return end();
        }
        // ���Ͱ� ������� �ʴٸ� ù ��° ���Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�
        return _container;
    }

    const int* begin() const
    {
        // ���Ͱ� ����ִٸ� end()�� ��ȯ�ϰ�
        if (empty())
        {
            return end();
        }
        // ���Ͱ� ������� �ʴٸ� ù ��° ���Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�
        return _container;
    }

    // ������ ����� ���� ��°�� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    int* end()
    {
        //_container : �����̳��� �ּ�
        // _size : ���� ������ �ִ� ������ ����
        // �ִ� ������ ����
        return _container + _size;
    }
    const int* end() const
    {
        return _container + _size;
    }

    // �����̳ʰ� ������� �˻��Ѵ�.
    bool                empty() const
    {
        if (_size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // ������ ������ ��ȯ�Ѵ�.
    size_t              size() const 
    {
        return _size;
    }

    // ���� �Ҵ�� ������ ũ�⸦ ��ȯ�Ѵ�.
    size_t              capacity() const
    {
        return _capacity;
    }

    // pos�� ��ġ�� ������ ������ ��ȯ�Ѵ�. ���� pos�� �������� ����� std::out_of_range ���ܰ� ��������.
    //int& at(size_t pos);
    //const int& at(size_t pos) const;

    // pos�� ��ġ�� ������ ������ ��ȯ�Ѵ�.
    // vector<int> v;
    // v[2];
    int& operator[](size_t pos)
    {
        return _container[pos];
    }
    const int& operator[](size_t pos) const
    {
        return _container[pos];
    }

    // �����̳��� ù ��° ������ ������ ��ȯ�Ѵ�.
    int& front()
    {
        return *begin();
    }
    const int& front() const
    {
        return *begin();
    } //begin�� �������̱� ������ ������ ������ ����

    // �����̳��� ������ ������ ������ ��ȯ�Ѵ�.
    int& back()
    {
        return *(end() -1);
    }
    const int& back() const
    {
        return *(end() - 1);
    }

    // �����̳ʸ� ����.
    void                clear()
    {
        delete[] _container;
        _container = nullptr;
            _size = 0;
        
    }

    // pos ���� ��ġ�� value�� �����Ѵ�.
    // value�� ���Ե� ���� ����Ű�� �����͸� ��ȯ�Ѵ�.
    int* insert(int* pos, int value)
    {
        // 1. ��ŭ �������ִ��� Ȯ���Ѵ�
        int dist = pos - begin(); //���� ����° ���Ҹ� ����Ű�� �ִٸ� 2�� ����

        // 2. �뷮�� Ȯ���Ѵ�
        if (_capacity == 0)
        {
            reserve(1);

            pos = begin() + dist; // ���� ����Ű���ִ� �޸𸮰� ��ȿ�ϱ⶧���� �ʱ�ȭ
        }
        else if (_size == _capacity)
        {
            reserve(_capacity * 2);

            pos = begin() + dist;
        }

        // 3. ����
        for (int* iter = end(); iter != pos; --iter) // ��ĭ�� �о ����
        {
            *iter = *(iter - 1);
        }
        *pos = value;  // ����

        // 4. �ʵ� ������ �ֽ�ȭ
        ++_size; 

        return pos;
    }

    // pos�� ��ġ�� ���Ҹ� �����.
    // ������ ����� ���� �����͸� ��ȯ�Ѵ�.
    int* erase(int* pos)
    {
        // 1. ����ִٸ� end() ��ȯ
        if (_size == 0 )
        {
            return end();
        }
        
        // 2. ������ ������ ����(����)
        int* last = end() - 1;
        for (int* iter = pos; iter != last; ++iter) // 
        {
            *iter = *(iter + 1);
        }

        // 3. �ʵ� ������Ʈ
        --_size;
        return pos;
    }

    // �����̳��� �� ���� ���Ҹ� �߰��Ѵ�.
    void                push_back(int value)
    {
        insert(end(), value);
    }

    // �����̳��� ������ ���Ҹ� �����Ѵ�.
    void                pop_back()
    {
        erase(end() - 1);
    }

    // value�� �����ϴ��� �˻��Ѵ�.
    bool                contains(int value)
    {
        for (size_t i = 0; i < _size; ++i)
        {
            if (_container[i] == value)
            {
                return true;
            }
        }
        return false;
    }


    // �����̳��� �뷮�� newCapacity���� ���ų� ũ�� �ø���.
    // newCapacity > _capacity��� ���ο� �޸𸮸� �Ҵ��ϰ�,
    // �׷��� �ʴٸ� �ƹ� ���۵� �������� �ʴ´�.
    void                reserve(size_t newCapacity)
    {
        // 1. newCapacity > _capacity ���� ��
        // 2. ũ�� ���ο� �޸� �Ҵ�
        // 3. ���� �޸��� �����͸� ����
        // 4. ���� �޸� ����
        // 5. �ʵ� ������ ���� _capacity = newCapacity;

        if (newCapacity > _capacity) // 1
        {
            int* newContainer = new int [newCapacity]; // 2

            for (size_t i = 0; i < _size; i++) // 3
            {
                newContainer[i] = _container[i];
            }

            delete[] _container; // 4

            _capacity = newCapacity; // 5
            _container = newContainer; // ���� �ּҸ� ����Ű�� �ִ� �����͸� ���� �ּҷ� ����
            
        }

    }
private:
    int*                _container = nullptr;
    size_t              _size = 0; // ���� ������ ����
    size_t              _capacity = 0;  //���Ͱ� ���� �� �ִ� �ִ� ������ ����
};

