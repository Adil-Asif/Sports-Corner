#pragma once
#ifndef List_H
#define List_H
#include "Utility.h"
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
	Node<T>* head;
	int size;

public:

	List()
	{
		size = 0;
		head = NULL;
	}

	void add_to_head(T element)
	{	
		if (head == NULL)
		{
			head=new Node<T> (element,NULL);
		}
		else
		{
			head = new Node<T>(element, head);
		}
		size++;
	}

	void Display()
	{
		Node<T>* temp = head;
		while (temp != NULL)
		{
			cout << temp->data;
			temp = temp->Next;
		}
	}

	void operator = (List<T> temp)
	{
		head = temp.ret_head();
	}

	int getsize(void)const
	{
		return size;
	}

	T Get_Head()
	{
		T temp = head->data;
		head = head->Next;
		size--;
		return temp;
	}

	Node<T>* ret_head()
	{
		return head;
	}

	bool list_empty()
	{
		return head == NULL;
	}
	bool delete_Node(string id)
	{
		Node <T>* temp=head;
		Node <T>* temp1;
		
		while (temp != NULL)
		{
			if (temp->Next->data.id == id)
			{
				temp1 = temp->Next;
				temp->Next = temp->Next->Next;
				delete temp1;
				return true;
			}
			else
			{
				temp = temp->Next;
			}
		}
		return false;
	}

	void remove_duplicate()
	{
		Node<string>* temp1 = head;
		Node<string>* temp2;
		Node<string>* dup;
		for (temp1; temp1 != NULL && temp1->Next != NULL; temp1 = temp1->Next)
		{
			temp2 = temp1;
			for (temp2; temp2->Next != NULL;)
			{
				if (temp1->data == temp2->Next->data)
				{
					dup = temp2->Next;
					temp2->Next = temp2->Next->Next;
					delete dup;
				}
				else
					temp2 = temp2->Next;

			}
		}


	}



};


#endif
