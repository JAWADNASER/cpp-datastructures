#pragma once
#include <iostream>

using namespace std;

template <class T>
class clsDynamicArray
{
protected:
	int _Size = 0;
	T* _TempArray;


public:
	T* OriginalArray;

	clsDynamicArray(int Size = 0)
	{
		if (Size < 0)
		{
			Size = 0;
		}
		_Size = Size;
		OriginalArray = new T[_Size];

	}

	~clsDynamicArray()
	{
		delete[]OriginalArray;
	}

	bool SetItem(int index, T value)
	{
		if (OriginalArray == nullptr || index < 0 || index >= _Size)
		{
			return false;
		}
		OriginalArray[index] = value;
		return true;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return _Size == 0;
	}

	void PrintArray()
	{
		for (int i = 0; i <= _Size - 1; i++)
		{
			cout << OriginalArray[i] << " - ";
		}
		cout << "\n\n";
	}

	void Resize(int newSize)
	{
		if (newSize < 0)
		{
			newSize = 0;
		}

		_TempArray = new T[newSize];

		if (newSize < _Size)
		{
			_Size = newSize;
		}

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}
		_Size = newSize;
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	T GetItem(int index)
	{
		if (index < 0 || index >= _Size)
			return -1;

		return OriginalArray[index];
	}

	void Reverse()
	{
		_TempArray = new T[_Size];

		int counter = 0;

		for (int i = _Size - 1; i >= 0; i--)
		{
			_TempArray[counter] = OriginalArray[i];
			counter++;
		}
		delete[]OriginalArray;
		OriginalArray = _TempArray;
	}

	void Clear()
	{
		_Size = 0;
		_TempArray = new T[0];
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	bool DeleteItemAt(int index)
	{
		if (index < 0 || index >= _Size)
		{
			return false;
		}

		_Size--;

		_TempArray = new T[_Size];

		for (int i = 0; i < index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		for (int i = index + 1; i < _Size + 1; i++)
		{
			_TempArray[i - 1] = OriginalArray[i];
		}

		delete[]OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}

	void DeleteFirstItem()
	{
		DeleteItemAt(0);
	}

	void DeleteLastItem()
	{
		DeleteItemAt(_Size - 1);
	}

	int Find(T value)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == value)
				return i;
		}
		return -1;
	}

	bool DeleteItem(T value)
	{
		int index = Find(value);
		if (index == -1)
		{
			return false;
		}
		DeleteItemAt(index);
		return true;
	}

	bool InsertAt(int index, T value)
	{
		if (index < 0 || index >= _Size)
		{
			return false;
		}

		_Size++;
		_TempArray = new T[_Size];

		for (int i = 0; i < index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		_TempArray[index] = value;

		for (int i = index; i < _Size -1; i++)
		{
			_TempArray[i + 1] = OriginalArray[i];
		}
		delete[]OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}

	void InsertAtBeginning(T value)
	{
		InsertAt(0, value);
	}

	void InsertAtEnd(T value)
	{
		InsertAt(_Size, value);
	}

	bool InsertBefore(int index, T value)
	{
		if (index < 1)
			return InsertAt(0, value);
		else
			return InsertAt(index - 1, value);
	}

	bool InsertAfter(int index, T value)
	{
		if (index >= _Size)
			return InsertAt(_Size - 1, value);
		else
			return InsertAt(index + 1, value);
	}
};

