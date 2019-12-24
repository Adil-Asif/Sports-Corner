#pragma once
#ifndef Queue_H
#define Queue_H
#include <iostream>
using namespace std;


template <typename T>
struct QNode
{
     T  data;
	QNode<T>* Next;

	QNode()
	{
		data = NULL;
		Next = NULL;
	}

	QNode(T data, QNode<T>* Next)
	{
		this->data = data;
		this->Next = Next;   //It will point to the next element in the Queue
	}

};

template <typename T>
class Queue
{
private:
	QNode<T>* First; //This pointer points to the first element in the queue

public:

	Queue()
	{
		First = NULL;
	}
	void EnQueue(T element)
	{
		if (IsEmpty())
		{
			this->First = new QNode<T>(this->element, NULL);
		}
		else
		{

			this->First = new QNode<T>(this->element, this->First);
		}
	}

	void DeQueue()
	{
		if (!IsEmpty())
		{
			QNode<T>* Temp = this->First;
			this->First = this->First->Next;
			delete Temp;
		}
	}

	bool IsEmpty()
	{
		return (this->First == NULL);
	}

	void Top()
	{
		cout << First->data;
	}
};

#endif