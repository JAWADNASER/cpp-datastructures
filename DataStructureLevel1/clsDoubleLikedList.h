#pragma once
#include <iostream>

using namespace std;

template <class T>
class clsDoubleLikedList
{
protected:
    int _Size = 0;

public:

    class Node
    {
    public:
        Node* prev;
        T data;
        Node* next;
    };

    Node* head = NULL;

    void InsertAtBeginning(T data)
    {
        Node* newNode = new Node();

        newNode->data = data;
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL)
            head->prev = newNode;

        head = newNode;
        _Size++;
    }

    Node* Find(T data)
    {
        Node* Current = head;
        while (Current != NULL)
        {
            if (Current->data == data)
                return Current;
            Current = Current->next;
        }
        return NULL;
    }

    void InsertAfter(Node* Current, T data)
    {
        Node* newNode = new Node();

        newNode->data = data;
        newNode->next = Current->next;
        newNode->prev = Current;

        if (Current->next != NULL)
        {
            Current->next->prev = newNode;
        }
        Current->next = newNode;
        _Size++;
    }

    void InsertAtEnd(T data)
    {
        Node* newNode = new Node();

        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL)
        {
            newNode->prev = NULL;
            head = newNode;
        }
        else
        {
            Node* Current = head;
            while (Current->next != NULL)
            {
                Current = Current->next;
            }
            Current->next = newNode;
            newNode->prev = Current;
        }
        _Size++;
    }

    void DeleteNode(Node*& NodeToDelete)
    {
        if (head == NULL || NodeToDelete == NULL)
        {
            return;
        }

        if (head == NodeToDelete)
            head = NodeToDelete->next;

        if (NodeToDelete->next != NULL)
        {
            NodeToDelete->next->prev = NodeToDelete->prev;
        }

        if (NodeToDelete->prev != NULL)
        {
            NodeToDelete->prev->next = NodeToDelete->next;
        }
        delete NodeToDelete;
        _Size--;
    }

    void DeleteFirstNode()
    {

        if (head == NULL)
        {
            return;
        }
        Node* NodeToDelete = head;

        head = head->next;
        if (head != NULL)
            head->prev = NULL;

        delete NodeToDelete;
        _Size--;

    }

    void DeleteLastNode()
    {

        if (head == NULL)
        {
            return;
        }

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node* Current = head;
        while (Current->next->next != NULL)
        {
            Current = Current->next;
        }
        Node* temp = Current->next;
        Current->next = NULL;
        delete temp;
        _Size--;

    }

    void PrintList()
    {
        Node* Current = head;
        cout << "NULL";
        while (Current != NULL)
        {
            cout << " <--> " << Current->data;
            Current = Current->next;
        }

        cout << " <--> NULL\n\n";
    }

    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return (_Size == 0 ? true : false);
    }

    void Clear()
    {
        while (_Size > 0)
        {
            DeleteFirstNode();
        }
    }
    void Reverse()
    {
        Node* Current = head;
        Node* temp = nullptr;

        while (Current != nullptr)
        {
            temp = Current->prev;
            Current->prev = Current->next;
            Current->next = temp;
            Current = Current->prev;
        }

        if (temp != nullptr)
            head = temp->prev;
    }

    Node* GetNode(int index)
    {
        int Counter = 0;

        if (index > _Size - 1 || index < 0)
            return NULL;

        Node* Current = head;
        while (Current != NULL && Current->next != NULL)
        {
            if (Counter == index)
            {
                break;
            }
            Current = Current->next;
            Counter++;
        }

        return Current;
    }

    int GetItem(int index)
    {
        Node* Current = GetNode(index);

        if (Current == NULL)
            return NULL;
        else
            return Current->data;
    }

    bool UpdateItem(int index, T data)
    {
        Node* Current = GetNode(index);

        if (Current == NULL)
            return false;
        else
        {
            Current->data = data;
            return true;
        }
    }

    bool InsertAfter(int Index, T data)
    {
        Node* Current = GetNode(Index);

        if (Current != NULL)
        {
            InsertAfter(Current, data);
            return true;
        }
        else
        {
            return false;
        }
    }

};

