#include "Set.h"
#include <iostream>
#include <queue>

Set::Node::Node(int data, Node* parent, Node* left, Node* right)
	:Data(data), Parent(parent), Left(left), Right(right)
{

}

Set::Node::~Node()
{
	Parent = nullptr;
	Left = nullptr;
	Right = nullptr;
}

bool Set::Node::IsLeaf() const
{
	if (Left == nullptr && Right == nullptr)
		return true;
	else
		return false;
}

bool Set::empty() const
{
	if (_size == 0)
		return true;
	else
		return false;
}

size_t Set::size() const
{
	return _size;
}

bool Set::insert(int value)
{
	// 새 노드 만들고
	Node* newNode = new Node(value);

	// 만약 루트 노드가 없다면
	if (_head->Parent == nullptr)
	{
		_head->Parent = newNode;
		newNode->Parent = _head;
		++_size;

		return true;
	}

	// 부모노드 찾기
	Node* parent = nullptr;
	Node* p = _head->Parent;

	while (p)
	{
		parent = p;

		if (p->Data == value)
		{
			return false;
		}
		else if (value < p->Data)
		{
			p = p->Left;
		}
		else
		{
			p = p->Right;
		}
	}
	
	//3. 찾은 부모노드 아래에 새로운 노드 삽입
	if (value < parent->Data)
	{
		parent->Left = newNode;
	}
	else
	{
		parent->Right = newNode;
	}
	newNode->Parent = parent;
	++_size;

	return true;
}

void Set::erase(int value)
{
	
}



Set::Node* Set::find(int value) const
{
	Node* result = _head->Parent;
	while (result)
	{
		if (result->Data == value)
		{
			break;
		}
		else if (result->Data < value)
		{
			result = result->Right;
		}
		else
		{
			result = result->Left;
		}
	}
}

void Set::traverseByPreorder() const
{
	traverseByPreorderHelper(_head->Parent);
}

void Set::traverseByPreorderHelper(Node* node) const
{
	if (node == nullptr)
	{
		return;
	}
	std::cout << node->Data << "->";
	traverseByPreorderHelper(node->Left);
	traverseByPreorderHelper(node->Right);
}

void Set::traverseByInorder() const
{
	traverseByInorderHelper(_head->Parent);
}

void Set::traverseByInorderHelper(Node* node) const
{

}

void Set::traverseByPostorder() const
{
	traverseByPostorderHelper(_head->Parent);
}


void Set::traverseByPostorderHelper(Node* node) const
{

}

void Set::traverseByLevelorder() const
{
	Node* node = _head->Parent;
	std::queue<Node*> qu;
	qu.push(node);

	while (qu.empty() == false)
	{
		Node* node = qu.front();
		qu.pop();

		std::cout << node->Data << "->";
		if (node->Left)
		{
			qu.push();
		}
	}

}


