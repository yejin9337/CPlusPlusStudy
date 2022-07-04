#pragma once
#include <utility>
class Set
{
    struct Node
    {
        Node(int data = 0, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr) = delete;
        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
        ~Node();

        bool    IsLeaf() const;

        int     Data = 0;
        Node* Parent = nullptr;
        Node* Left = nullptr;
        Node* Right = nullptr;
    };

public:
    // Ʈ���� ���̸� ���Ѵ�.
    int                     height() const; // ť�� �̿��Ѵ�.
    int                     height2() const; // ��͸� �̿��Ѵ�.

    // Ʈ���� ������� Ȯ���Ѵ�.
    bool                    empty() const;

    // Ʈ���� ũ�⸦ ��ȯ�Ѵ�.
    size_t                  size() const;

    // Ʈ���� ����.
    void                    clear();

    // Ʈ���� ���� �����Ѵ�.
    std::pair<Node*, bool>       insert(int value);

    // Ʈ������ ���� �����Ѵ�.
    void erase(Node* pos);
    size_t      erase(int value);

    // Ʈ������ ���� ã�´�.
    Node* find(int value);
    const Node* find(int value) const;

    // ��ȸ
    void        traverseByPreorder() const;
    void        traverseByInorder() const;
    void        traverseByPostorder() const;
    void        traverseByLevelorder() const;

private:
    Node* _root = nullptr;
    size_t _size = 0;
};


