#pragma once
#ifndef List_H
#define List_H
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
class List
{
private:
	Node<T>* head, * tail;
	int size;

public:

	List()
	{
		size = 0;
		head = NULL;
		tail = NULL;
	}

	void add_to_head(T element)
	{	
		if (head == NULL)
		{
			head=tail=new Node<T> (element,head);
		}
		else
		{
			head = new Node<T>(element, head);
		}
		size++;
	}


	void add_to_tail(T element)
	{
		if (head == NULL)
		{
			head = tail = new Node<T>(element, head);
		}
		else
		{
			tail->Next = new Node<T>(element, NULL);
			tail=tail->Next
		}
		size++;
	}

};






#endif
