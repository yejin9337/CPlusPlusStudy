#pragma once

#include <string>
#include <utility>

//-------------------------------------------------------------------------------------------------
// MyVector �� �����ϴ� ������Ʈ
//-------------------------------------------------------------------------------------------------
struct MyObject
{
    int _id;
};

//-------------------------------------------------------------------------------------------------
// MyVector Ŭ����.
//-------------------------------------------------------------------------------------------------
class MyVector
{
private: // ������ �ʿ��� ��� �߰� �Լ�/�������� �����Ӱ� �Ʒ��� ���� �մϴ�.

    MyObject* _container = nullptr; // �����̳��� ������
    size_t              _size = 0;      // ���� ������ ����
    size_t              _capacity = 0;  // ���Ͱ� ���� �� �ִ� �ִ� ������ ����

    // ��.1) ����� �����ϴ� ��������� �Ʒ�ó�� �߰��ϸ� �˴ϴ�.
    // int _vectorSize;

    // ��.2) ��������� �ø��� �Լ��� �Ʒ�ó�� �߰��ϸ� �˴ϴ�.
    // void Grow();

#pragma region Inheritance
    // ù ��° ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    MyObject* begin()
    {
        // ���Ͱ� ����ִٸ� end()�� ��ȯ
        if (empty())
        {
            return end();
        }

        // ���Ͱ� ������� �ʴٸ� ù ��° ���Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
        return _container;
    }

    const MyObject* begin() const
    {
        // ���Ͱ� ����ִٸ� end()�� ��ȯ
        if (empty())
        {
            return end();
        }

        // ���Ͱ� ������� �ʴٸ� ù ��° ���Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
        return _container;
    }

    // ������ ����� ���� ��°�� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�. (���� ����ִ�.)
    // ������ ����
    MyObject* end() { return _container + _size; }
    // _container : �����̳��� �ּ�
    // -size : ���� ������ �ִ� ������ ����
    // _capacity : �ִ� ������ ����

    const MyObject* end() const { return _container + _size; }

    // �����̳ʰ� ������� �˻��Ѵ�.
    bool                empty() const
    {
        if (0 == _size) // or, (begin() == end())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // ������ ������ ��ȯ�Ѵ�.
    // size_t              size() const { return _size; }

    // ���� �Ҵ�� ������ ũ�⸦ ��ȯ�Ѵ�.
    // size_t              capacity() const { return _capacity; }

    //// pos�� ��ġ�� ������ ������ ��ȯ�Ѵ�.
    //int& operator[](size_t pos) { return _container[pos]; }
    //const int& operator[](size_t pos) const { return _container[pos]; }

    // �����̳��� ù ��° ������ ������ ��ȯ�Ѵ�.
    MyObject& front() { return *begin(); }
    const MyObject& front() const { return *begin(); }

    // �����̳��� ������ ������ ������ ��ȯ�Ѵ�.
    MyObject& back() { return *(end() - 1); }
    const MyObject& back() const { return *(end() - 1); }

    // �����̳ʸ� ����.
    void                clear()
    {
        // ���� �Ҵ� �޸� ��ȯ
        delete[] _container;

        // ��۸� ������ ���� : _container �� �����ͷ�.
        _container = nullptr;

        // _size, _capacity 0����
        _size = 0;
        _capacity = 0;
    }

    // pos ���� ��ġ�� value�� �����Ѵ�. -> pos�� ��ġ�� value�� ���� �ȴ�.
    // value�� ���Ե� ���� ����Ű�� �����͸� ��ȯ�Ѵ�. -> pos�� ����. 
    MyObject* insert(MyObject* pos, int value)
    {
        // 1. �󸶳� �������ִ��� Ȯ���Ѵ�.
        int dist = pos - begin();

        // 2. �뷮�� Ȯ���Ѵ�.
        if (_capacity = 0)
        {
            reserve(1);

            // ���Ҵ��Ͽ����Ƿ� �ݺ��� ��� �Ұ� -> ��ȿȭ
            // ��ȿ�� �ݺ��ڷ� ����
            pos = begin() + dist;
        }
        else if (_size == _capacity)
        {
            // ���� �뷮�� ���� ���� 2��� �÷��ش�.
            // ������ �ٰſ� ���� ��ġ
            reserve(_capacity * 2);

            pos = begin() + dist;
        }

        // 3. ����
        for (MyObject* iter = end(); iter != pos; --iter)
        {
            // ������(�ݺ���) iter�� pos�� ���� ������ �ϳ��� ����
            *iter = *(iter - 1);
        }
        pos->_id = value;

        // 4. �ʵ� ������ �ֽ�ȭ
        ++_size;

        // 5. value�� ���Ե� ���� ����Ű�� �����͸� ��ȯ -> pos�� ����.
        return pos;
    }

    // pos�� ��ġ�� ���Ҹ� �����.
    //  -> �� ĭ�� ���� �ʰ� ��������. ������ �� ĭ�� ���´�.
    // ������ ����� ���� �����͸� ��ȯ�Ѵ�. -> pos�� ����.
    MyObject* erase(MyObject* pos)
    {
        // 1. ����ִٸ� end() ��ȯ
        if (_size == 0)
        {
            return end();
        }

        // 2. ������ �̵�(����)
        MyObject* last = end() - 1;
        for (MyObject* iter = pos; iter != last; ++iter)
        {
            // ������(�ݺ���) iter�� last�� ���� ������ �ϳ��� ����
            *iter = *(iter + 1);
        }

        // 3. �ʵ� ������Ʈ
        --_size;

        // 4. ������ ����� ���� �����͸� ��ȯ -> pos�� ����.
        return pos;
    }

    // �����̳��� �� ���� ���Ҹ� �߰��Ѵ�.
    void                push_back(int value) { insert(end(), value); }

    // �����̳��� ������ ���Ҹ� �����Ѵ�.
    void                pop_back() { erase(end() - 1); }

    // value�� �����ϴ��� �˻��Ѵ�.
    bool                contains(int value)
    {
        for (size_t i = 0; i < _size; i++)
        {
            if (_container[i]._id == value)
            {
                return true;
            }
        }

        return false;
    }

    // ���� ������ �����Ѵ�.
    // �����̳��� �뷮�� newCapacity���� ���ų� ũ�� �ø���.
    // newCapacity > _capacity��� ���ο� �޸𸮸� �Ҵ��ϰ�,
    // �׷��� �ʴٸ� �ƹ� ���۵� �������� �ʴ´�.

    // ���� : reserve()�� ������ ����� �ٲ��� �ʴ´�.
    // �Ҵ��ϸ鼭 ���� �޸𸮿� �ִ� �����͸� �Űܿ´�.

    // �ݺ��ڸ� ������ ����ߴٸ�
    // reserve�� ����Ͽ� �Ҵ��� �Ͼ ��
    // �ݺ��ڸ� �ٽ� ȣ���� �� ����.
    // ���ο� �޸𸮸� �Ҵ��Ͽ� ���� �޸��� �����͸� �ű��
    // ���� �޸𸮴� free�ϱ� ������,
    // �ݺ��� iter�� ��۸� �����Ͱ� �Ǳ� ����.
    void                reserve(size_t newCapacity)
    {
        // 1. newCapacity�� _capacity ���� ū�� ��
        if (_capacity >= newCapacity) { return; }

        // 2. ���ο� �޸𸮸� �Ҵ�
        MyObject* temp_container = new MyObject[newCapacity];

        // 3. ���� �޸��� �����͸� ����
        for (int i = 0; i < _size; i++)
        {
            temp_container[i]._id = _container[i]._id;
        }

        // 4. ���� �޸� ����
        delete[] _container;
        _container = temp_container;

        // 5. �ʵ� ������ ���� _capacity = newCapacity
        _capacity = newCapacity;


    }
#pragma endregion

public: // ������, ���������, �Ҵ翬����, �Ҹ��ڸ� .cpp ���Ͽ� �����մϴ�.
    MyVector() = default;

    // Constructor.
    MyVector(int capacity)
        : _container(new MyObject[capacity]), _size(0), _capacity(capacity) {}

    // Copy constructor.
    MyVector(const MyVector& other)
        : _container(new MyObject[other._capacity]), _size(other._size), _capacity(other._capacity)
    {
        for (size_t i = 0; i < _size; ++i)
        {
            _container[i] = other._container[i];
        }
    }

    // Assignment operator.
    MyVector& operator=(const MyVector& other)
    {
        if (this == &other)
        {
            return *this;
        }

        MyVector temp(other);
        std::swap(_container, temp._container);
        std::swap(_size, temp._size);
        std::swap(_capacity, temp._capacity);

        return *this;
    }

    // �Ҵ� ������. �Ű������� const�� ������ swap�� �� ����.
    /*MyVector& operator=(MyVector& other)
    {
        std::swap(_container, other._container);
        std::swap(_size, other._size);
        std::swap(_capacity, other._capacity);

        return *this;
    }*/


    // Destructor.
    ~MyVector()
    {
        clear();
    }

public: // �Ʒ� ��� �Լ����� .cpp ���Ͽ� �����մϴ�.

    // Returns current capacity of this vector.
    int GetCapacity() const
    {
        return _capacity;
    }

    // Returns current size of this vector.
    int GetSize() const
    {
        return _size;
    }

    // Creates a new MyObject instance with the given ID, and appends it to the end of this vector.
    void Add(int id)
    {
        //if (_size == _capacity)
        //{
        //    reserf(_capacity == 0) ? 1; -capacity;
        //}
        // 
        // ���ο� Object ����.
        MyObject* obj = new MyObject;

        // Object�� �ʵ忡 �Ű����� �Ҵ�.
        obj->_id = id;

        // vector�� �������� id �߰�.
        push_back(id);

    }

    // Returns the first occurrence of MyObject instance with the given ID.
    // Returns nullptr if not found.
    MyObject* FindById(int MyObjectId) const
    {
        // �����̳� �� ����� MyObjectId�� ��ġ�ϴ� Object Ž��.
        for (size_t i = 0; i < _size; i++)
        {
            if (MyObjectId == _container[i]._id)
            {
                return &_container[i];
            }
        }

        // �ش��ϴ� Object�����͸� �� ã�� ���, null������ ��ȯ
        return nullptr;
    }

    // Trims the capacity of this vector to current size.
    void TrimToSize()
    {
        // �ӽ� �����̳� ����.
        MyObject* temp_container;

        // �뷮�� ���� ũ��� ����.
        _capacity = _size;

        // ���� �Ҵ�. ���� ũ�� ��ŭ.
        temp_container = new MyObject[_capacity];

        // ������ ����.
        for (size_t i = 0; i < _capacity; i++)
        {
            temp_container[i]._id = _container[i]._id;
        }

        // ���� �����̳��� �޸� ��ȯ ��,
        delete[] _container;
        // �����̳� �ּ� ����.
        _container = temp_container;
    }

    // Returns the MyObject instance at the specified index.
    MyObject& operator[](size_t index)
    {
        return _container[index];
    }

    // Returns string representation of the vector.
    std::string ToString() const
    {
        std::string str;
        for (size_t i = 0; i < _capacity; i++)
        {
            // �� ���ھ� string�� ��ȯ �� �Ҵ�.
            str += std::to_string(_container[i]._id);
        }

        return str;
    }

    // Remove all MyObject instances with the given ID in this vector.
    void RemoveAll(int MyObjectId)
    {
        // �ش��ϴ� Object Ž�� �� �޸� ��ȯ.
        delete FindById(MyObjectId);
    }

    // Returns a newly allocated array of MyVector objects,
    // each of whose elements have the same "_id" value of the MyObject struct.
    // The 'numGroups' is an out parameter, and its value should be set to
    // the size of the MyVector array to be returned.
    MyVector* GroupById(int* numGroups)
    {
        // ���͵� �� ���� _id�� ��ҷ� ���� ���͸� ��� �迭�� �����.
        // �ٵ� �� ��� �ؾ��ϴ��� ���� �� ������.
        MyVector* ids;
        for (size_t i = 0; i < _size; ++i)
        {
            if (nullptr == ids->FindById(_container[i]._id))
            {
                ids->Add(_container[i]._id);
            }
        }

        int count = ids->GetSize();
        //MyVector* result = new MyVector[count];

        for (size_t i = 0; i < _size; ++i)
        {
            size_t index = ids->FindById(_container[i]._id) - ids.begin();
            result[index].Add(_container[i]._id);
        }

        *numGroups = count;
        return result;
    }
};