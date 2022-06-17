#pragma once

#include <string>
#include <utility>

//-------------------------------------------------------------------------------------------------
// MyVector 가 관리하는 오브젝트
//-------------------------------------------------------------------------------------------------
struct MyObject
{
    int _id;
};

//-------------------------------------------------------------------------------------------------
// MyVector 클래스.
//-------------------------------------------------------------------------------------------------
class MyVector
{
private: // 구현에 필요한 멤버 추가 함수/변수들을 자유롭게 아래에 정의 합니다.

    MyObject* _container = nullptr; // 컨테이너의 포인터
    size_t              _size = 0;      // 벡터 원소의 개수
    size_t              _capacity = 0;  // 벡터가 가질 수 있는 최대 원소의 개수

    // 예.1) 사이즈를 저장하는 멤버변수를 아래처럼 추가하면 됩니다.
    // int _vectorSize;

    // 예.2) 저장공간을 늘리는 함수를 아래처럼 추가하면 됩니다.
    // void Grow();

#pragma region Inheritance
    // 첫 번째 요소를 가리키는 반복자를 반환한다.
    MyObject* begin()
    {
        // 벡터가 비어있다면 end()를 반환
        if (empty())
        {
            return end();
        }

        // 벡터가 비어있지 않다면 첫 번째 원소를 가리키는 반복자를 반환한다.
        return _container;
    }

    const MyObject* begin() const
    {
        // 벡터가 비어있다면 end()를 반환
        if (empty())
        {
            return end();
        }

        // 벡터가 비어있지 않다면 첫 번째 원소를 가리키는 반복자를 반환한다.
        return _container;
    }

    // 마지막 요소의 다음 번째를 가리키는 반복자를 반환한다. (보통 비어있다.)
    // 역참조 금지
    MyObject* end() { return _container + _size; }
    // _container : 컨테이너의 주소
    // -size : 현재 가지고 있는 원소의 개수
    // _capacity : 최대 원소의 개수

    const MyObject* end() const { return _container + _size; }

    // 컨테이너가 비었는지 검사한다.
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

    // 원소의 개수를 반환한다.
    // size_t              size() const { return _size; }

    // 현재 할당된 공간의 크기를 반환한다.
    // size_t              capacity() const { return _capacity; }

    //// pos에 위치한 원소의 참조를 반환한다.
    //int& operator[](size_t pos) { return _container[pos]; }
    //const int& operator[](size_t pos) const { return _container[pos]; }

    // 컨테이너의 첫 번째 원소의 참조를 반환한다.
    MyObject& front() { return *begin(); }
    const MyObject& front() const { return *begin(); }

    // 컨테이너의 마지막 원소의 참조를 반환한다.
    MyObject& back() { return *(end() - 1); }
    const MyObject& back() const { return *(end() - 1); }

    // 컨테이너를 비운다.
    void                clear()
    {
        // 동적 할당 메모리 반환
        delete[] _container;

        // 댕글링 포인터 예방 : _container 널 포인터로.
        _container = nullptr;

        // _size, _capacity 0으로
        _size = 0;
        _capacity = 0;
    }

    // pos 이전 위치에 value를 삽입한다. -> pos의 위치에 value가 들어가게 된다.
    // value가 삽입된 곳을 가리키는 포인터를 반환한다. -> pos와 같다. 
    MyObject* insert(MyObject* pos, int value)
    {
        // 1. 얼마나 떨어져있는지 확인한다.
        int dist = pos - begin();

        // 2. 용량을 확인한다.
        if (_capacity = 0)
        {
            reserve(1);

            // 재할당하였으므로 반복자 사용 불가 -> 무효화
            // 유효한 반복자로 변경
            pos = begin() + dist;
        }
        else if (_size == _capacity)
        {
            // 보통 용량이 가득 차면 2배로 늘려준다.
            // 실험적 근거에 따른 수치
            reserve(_capacity * 2);

            pos = begin() + dist;
        }

        // 3. 삽입
        for (MyObject* iter = end(); iter != pos; --iter)
        {
            // 포인터(반복자) iter가 pos를 만날 때까지 하나씩 복사
            *iter = *(iter - 1);
        }
        pos->_id = value;

        // 4. 필드 데이터 최신화
        ++_size;

        // 5. value가 삽입된 곳을 가리키는 포인터를 반환 -> pos와 같다.
        return pos;
    }

    // pos에 위치한 원소를 지운다.
    //  -> 빈 칸이 남지 않고 땡겨진다. 마지막 빈 칸은 남는다.
    // 삭제된 요소의 다음 포인터를 반환한다. -> pos와 같다.
    MyObject* erase(MyObject* pos)
    {
        // 1. 비어있다면 end() 반환
        if (_size == 0)
        {
            return end();
        }

        // 2. 데이터 이동(삭제)
        MyObject* last = end() - 1;
        for (MyObject* iter = pos; iter != last; ++iter)
        {
            // 포인터(반복자) iter가 last를 만날 때까지 하나씩 복사
            *iter = *(iter + 1);
        }

        // 3. 필드 업데이트
        --_size;

        // 4. 삭제된 요소의 다음 포인터를 반환 -> pos와 같다.
        return pos;
    }

    // 컨테이너의 맨 끝에 원소를 추가한다.
    void                push_back(int value) { insert(end(), value); }

    // 컨테이너의 마지막 원소를 삭제한다.
    void                pop_back() { erase(end() - 1); }

    // value가 존재하는지 검사한다.
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

    // 저장 공간을 예약한다.
    // 컨테이너의 용량을 newCapacity보다 같거나 크게 늘린다.
    // newCapacity > _capacity라면 새로운 메모리를 할당하고,
    // 그렇지 않다면 아무 동작도 수행하지 않는다.

    // 주의 : reserve()는 벡터의 사이즈를 바꾸지 않는다.
    // 할당하면서 이전 메모리에 있던 데이터를 옮겨온다.

    // 반복자를 이전에 사용했다면
    // reserve를 사용하여 할당이 일어난 후
    // 반복자를 다시 호출할 수 없다.
    // 새로운 메모리를 할당하여 이전 메모리의 데이터를 옮기고
    // 이전 메모리는 free하기 때문에,
    // 반복자 iter는 댕글링 포인터가 되기 때문.
    void                reserve(size_t newCapacity)
    {
        // 1. newCapacity가 _capacity 보다 큰지 비교
        if (_capacity >= newCapacity) { return; }

        // 2. 새로운 메모리를 할당
        MyObject* temp_container = new MyObject[newCapacity];

        // 3. 이전 메모리의 데이터를 복사
        for (int i = 0; i < _size; i++)
        {
            temp_container[i]._id = _container[i]._id;
        }

        // 4. 이전 메모리 해제
        delete[] _container;
        _container = temp_container;

        // 5. 필드 데이터 수정 _capacity = newCapacity
        _capacity = newCapacity;


    }
#pragma endregion

public: // 생성자, 복사생성자, 할당연산자, 소멸자를 .cpp 파일에 구현합니다.
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

    // 할당 연산자. 매개변수에 const가 붙으면 swap을 못 쓴다.
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

public: // 아래 기능 함수들을 .cpp 파일에 구현합니다.

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
        // 새로운 Object 생성.
        MyObject* obj = new MyObject;

        // Object의 필드에 매개변수 할당.
        obj->_id = id;

        // vector의 마지막에 id 추가.
        push_back(id);

    }

    // Returns the first occurrence of MyObject instance with the given ID.
    // Returns nullptr if not found.
    MyObject* FindById(int MyObjectId) const
    {
        // 컨테이너 중 멤버가 MyObjectId와 일치하는 Object 탐색.
        for (size_t i = 0; i < _size; i++)
        {
            if (MyObjectId == _container[i]._id)
            {
                return &_container[i];
            }
        }

        // 해당하는 Object포인터를 못 찾을 경우, null포인터 반환
        return nullptr;
    }

    // Trims the capacity of this vector to current size.
    void TrimToSize()
    {
        // 임시 컨테이너 선언.
        MyObject* temp_container;

        // 용량을 현재 크기로 줄임.
        _capacity = _size;

        // 동적 할당. 현재 크기 만큼.
        temp_container = new MyObject[_capacity];

        // 데이터 복사.
        for (size_t i = 0; i < _capacity; i++)
        {
            temp_container[i]._id = _container[i]._id;
        }

        // 이전 컨테이너의 메모리 반환 후,
        delete[] _container;
        // 컨테이너 주소 변경.
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
            // 한 숫자씩 string에 변환 후 할당.
            str += std::to_string(_container[i]._id);
        }

        return str;
    }

    // Remove all MyObject instances with the given ID in this vector.
    void RemoveAll(int MyObjectId)
    {
        // 해당하는 Object 탐색 후 메모리 반환.
        delete FindById(MyObjectId);
    }

    // Returns a newly allocated array of MyVector objects,
    // each of whose elements have the same "_id" value of the MyObject struct.
    // The 'numGroups' is an out parameter, and its value should be set to
    // the size of the MyVector array to be returned.
    MyVector* GroupById(int* numGroups)
    {
        // 벡터들 중 같은 _id를 요소로 가진 벡터를 모아 배열로 만든다.
        // 근데 뭘 어떻게 해야하는지 감도 안 잡힌다.
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