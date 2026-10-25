#pragma once
#include <iostream>
#include "clsDoubleLikedList.h"

using namespace std;

template <class T>
class clsQueue
{
protected:
	clsDoubleLikedList<T> _MyList;

public:
	void push(T item)
	{
		_MyList.InsertAtEnd(item);
	}

	void pop()
	{
		_MyList.DeleteFirstNode();
	}

	void Print()
	{
		_MyList.PrintList();
	}

	int Size()
	{
		return _MyList.Size();
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	T front()
	{
		return _MyList.GetItem(0);
	}

	T back()
	{
		return _MyList.GetItem(Size() - 1);
	}

	int GetItem(int index)
	{
		return _MyList.GetItem(index);
	}

	void Reverse()
	{
		_MyList.Reverse();
	}

	bool UpdateItem(int index, T data)
	{
		if (_MyList.UpdateItem(index, data))
			return true;
		else
			return false;
	}

	bool InsertAfter(int Index, T data)
	{
		if (_MyList.InsertAfter(Index, data))
			return true;
		else
			return false;
	}

	void InsertAtFront(T data)
	{
		_MyList.InsertAtBeginning(data);
	}

	void InsertAtBack(T data)
	{
		_MyList.InsertAtEnd(data);
	}

	void Clear()
	{
		_MyList.Clear();
	}
};

