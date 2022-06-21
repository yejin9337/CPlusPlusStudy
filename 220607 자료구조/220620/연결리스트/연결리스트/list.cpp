#include <forward_list> // std::forward_list를 쓰기 위한 헤더
#include <iostream>
#include "list.h"
using namespace std;
List::Node::Node(int data, Node* prev, Node* next)
	: Data(data), Prev(prev), Next(next)
{

}

List::const_iterator::const_iterator(Node* p)
	: _p(p)
{

}

List::const_iterator::~const_iterator()
{
	_p = nullptr;
}

const int& List::const_iterator::operator*() const
{
	return _p->Data;
}

const int* List::const_iterator::operator->() const
{
	return &(_p->Data);
}

List::const_iterator& List::const_iterator::operator++()
{
	_p = _p->Next;

	return *this;
}

List::const_iterator List::const_iterator::operator++(int)
{
	const_iterator temp = *this;
	_p = _p->Next;

	return temp;
}

List::const_iterator& List::const_iterator::operator--()
{
	_p = _p->Prev;

	return *this;
}

List::const_iterator List::const_iterator::operator--(int)
{
	const_iterator temp = *this;
	_p = _p->Prev;

	return temp;
}

bool List::const_iterator::operator==(const const_iterator& rhs) const
{

}

bool List::const_iterator::operator!=(const const_iterator& rhs) const
{

}

bool List::const_iterator::operator==(nullptr_t p) const
{

}

bool List::const_iterator::operator!=(nullptr_t p) const
{

}

// iterator 기본생성자

int& List::iterator::operator*() const
{
	return (int&)const_iterator::operator*();
}

int* List::iterator::operator->() const
{
	return (int*)const_iterator::operator->();
}

List::iterator& List::iterator::operator++()
{
	const_iterator::operator++();

	return *this;
}

List::iterator List::iterator::operator++(int)
{
	iterator temp = *this;
	const_iterator::operator++();

	return temp;
}

List::iterator& List::iterator::operator--()
{
	const_iterator::operator--();

	return *this;
}

List::iterator List::iterator::operator--(int)
{

}

size_t List::size() const
{
	return _size;
}

bool List::empty() const
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

void List::clear()
{
	while (false == empty())
	{
		pop_front();
	}
}

void List::push_front(int value)
{
	insert(begin(), value);
}

void List::push_back(int value)
{
	insert(end(), value);
}

void List::pop_front()
{
	erase(begin());
}

void List::pop_back()
{
	erase(--end());
}

int& List::front()
{
	return *begin();
}

const int& List::front() const
{
	return *begin();
}

int& List::back()
{
	return *(--end());
}

const int& List::back() const
{
	return *(--end());
}

List::iterator List::begin()
{
	return iterator(_end->Next);
}

List::const_iterator List::begin() const
{
	return iterator(_end->Next);
}

List::iterator List::end()
{
	return _end;
}

List::const_iterator List::end() const
{
	return _end;
}

List::iterator List::insert(iterator pos, int value)
{
	Node* beforeNode = pos._p;
	Node* afterNode = beforeNode->Prev;
	Node* newNode = new Node(value); 
	// 아래 뉴노드 앞뒤 정해주는거 지우고 애초에 설정을 (value, insertAfter, insertBefore) 해도 됨
	

	newNode->Prev = afterNode;
	newNode->Next = beforeNode;
	beforeNode->Next = newNode;
	afterNode->Prev = newNode;

	++_size;

	return newNode;
}

List::iterator List::erase(iterator pos)
{
	Node* removeNode = pos._p;
	Node* removePrev = removeNode->Prev;
	Node* removeNext = removeNode->Next;

	removePrev->Next = removeNext;
	removeNext->Prev = removePrev;
	delete removeNode;
	--_size;

	return removeNext;
}

bool List::contains(int value) const
{
	for (const_iterator iter = begin(); iter != end(); iter++)
	{
		if (*iter == value)
		{
			return true;
		}
	}

	return false;
}