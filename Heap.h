#pragma once
#ifndef Heap_H
#define Heap_H
#include "List.h"
#include <iostream>
using namespace std;

struct output_file
{
	string filename;
	int upvotes;

	output_file()
	{
		filename = '\0';
		upvotes = -1;
	}
};


class Heap
{
private:
	struct output_file* arr;
	int size, rear;

public:

	Heap()
	{
		arr = NULL;
		size = 0;
		rear = 0;
	}


	void insert_array(List<output_file> a)
	{
		size = a.getsize();
		arr = new output_file[size+1];
		Node<output_file>* temp = a.ret_head();

		for (int i = 1; i <=size; i++)
		{
			if (i <= size)
			{
				arr[i] = temp->data;
				temp = temp->Next;
				rear++;
			}

		}
	}
	
	void get_sorted_list(List<output_file> a)
	{
		
		List<output_file> temp;

		for (int i = 1; i <= size; i++)
		{
			if (i <= size)
			{
				temp.add_to_head(arr[i]);
			}

		}
		a = temp;
	}


	void swap(int a, int b)
	{
		output_file temp;
		temp = arr[b];
		arr[b] = arr[a];
		arr[a] = temp;
	}


	void max_heapify(int i)
	{
		int left = 2 * i;
		int right = 2 * i + 1;
		int largest = i;

		if (i > rear)
		{
			return;
		}

		if (left <= rear && arr[left].upvotes > arr[largest].upvotes)
		{
			largest = left;
		}

		if (right <= rear && arr[right].upvotes > arr[largest].upvotes)
		{
			largest = right;
		}

		if (largest != i)
		{
			swap(largest, i);
			max_heapify(largest);
		}
	}

	void create_max_heap()
	{
		for (int i = (rear + 1) / 2; i >= 1; i--)
		{
			max_heapify(i);
		}
	}

	void heap_sort()
	{
		for (int i = 1; i <= size; i++)
		{
			arr[1] = arr[rear];
			rear--;
			create_max_heap();
		}
	}

	struct output_file Get_struct(int index)
	{
		return arr[index];
	}

	
};
#endif