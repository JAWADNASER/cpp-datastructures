#pragma once
#include <iostream>
#include "clsQueueArr.h"

using namespace std;
template <class T>
class clsStackArr : public clsQueueArr<T>
{
public:
	void push(T item)
	{
		clsQueueArr<T>::_MyArr.InsertAtBeginning(item);
	}

	T top()
	{
		return clsQueueArr<T>::front();
	}

	T Bottom()
	{
		return clsQueueArr<T>::bcak();
	}
};

