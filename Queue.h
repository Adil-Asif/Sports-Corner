#pragma once
#ifndef Queue_H
#define Queue_H
#include <iostream>
using namespace std;


template <typename T>
struct Node
{
     T  data;
	Node<T>* Next;

	Node()
	{
		data = NULL;
		Next = NULL;
	}

	Node(T data, Node<T>* Next)
	{
		this->data = data;
		this->Next = Next;   //It will point to the next element in the Queue
	}

};

template <typename T>
class Queue
{
private:
	Node<T>* First; //This pointer points to the first element in the queue

public:

	Queue()
	{
		First = NULL;
	}
	void EnQueue(T element)
	{
		if (IsEmpty())
		{
			this->First = new Node<T>(this->element, NULL);
		}
		else
		{

			this->First = new Node<T>(this->element, this->First);
		}
	}

	void DeQueue()
	{
		if (!IsEmpty())
		{
			Node<T>* Temp = this->First;
			this->First = this->First->Next;
			delete Temp;
		}
	}

	bool IsEmpty()
	{
		return (this->First==NULL)
	}

	void Top()
	{
		cout << First->data;
	}
};

#endif