#pragma once
#include <iostream>
#include "clsDynamicArray.h"

using namespace std;

template <class T>
class clsQueueArr
{
protected:
	clsDynamicArray <T> _MyArr;

public:
	void push(T item)
	{
		_MyArr.InsertAtEnd(item);
	}

	void pop()
	{
		_MyArr.DeleteFirstItem();
	}

	void Print()
	{
		_MyArr.PrintArray();
	}

	int Size()
	{
		return _MyArr.Size();
	}

	bool IsEmpty()
	{
		return _MyArr.IsEmpty();
	}

	T front()
	{
		return _MyArr.GetItem(0);
	}

	T back()
	{
		return _MyArr.GetItem(Size() - 1);
	}

	int GetItem(int index)
	{
		return _MyArr.GetItem(index);
	}

	void Reverse()
	{
		_MyArr.Reverse();
	}

	void UpdateItem(int index, T data)
	{
		_MyArr.SetItem(index, data);
	}

	bool InsertAfter(int Index, T data)
	{
		if (_MyArr.InsertAfter(Index, data))
			return true;
		else
			return false;
	}

	void InsertAtFront(T data)
	{
		_MyArr.InsertAtBeginning(data);
	}

	void InsertAtBack(T data)
	{
		_MyArr.InsertAtEnd(data);
	}

	void Clear()
	{
		_MyArr.Clear();
	}
};

