#pragma once
#include <iostream>
#include "clsQueue.h"


template <class T>
class clsStack : public clsQueue<T>
{
public:
	void push(T item)
	{
		clsQueue<T>::_MyList.InsertAtBeginning(item);
	}

	T top()
	{
		return clsQueue<T>::front();
	}

	T Bottom()
	{
		return clsQueue<T>::bcak();
	}
};

