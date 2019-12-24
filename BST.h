#pragma once
#ifndef BST_H
#define BST_H
#include <fstream>
#include <iostream>

using namespace std;


struct BNode
{

	BNode* right, * left;
	string data;

	BNode()
     {
	     right = NULL;
		left = NULL;
	}

	BNode(string a, BNode* r, BNode* l)
	{
		this->data = a;
		this->right = r;
		this->left = l;
	}

};


class tree
{
private:

	BNode* root;

	BNode* insert_tree(string element, BNode* temp)
	{
		if (temp == NULL)
		{
			temp = new BNode(element, NULL, NULL);
			return temp;
		}

		else if (element > temp->data)
		{
			temp->right = insert_tree(element, temp->right);
			return temp;
		}
		else if (element < temp->data)
		{

			temp->left = insert_tree(element, temp->left);
			return temp;
		}

	}

	void Delete_Tree(BNode* temp)
	{
		if (temp != NULL)
		{
			Delete_Tree(temp->left);
			Delete_Tree(temp->right);
			delete temp;
		}
	}



	int check_bst(BNode* temp, string min, string max)
	{
		if (temp == NULL)
			return 1;
		else if (temp->data<min || temp->data >max)
			return 0;
		else
			return (check_bst(temp->left, min, temp->data) && check_bst(temp->right, temp->data, max));

	}


	string findmax(string max, BNode* temp)
	{
		if (temp == NULL)
		{
			cout << "Tree is empty";

		}
		else if (temp->right!= NULL)
		{
			 string a = findmax(max, temp->right);
		}
		else
		{
			max = temp->data;
			return max;
		}
	}


	string findmin(string min, BNode* temp)
	{
		if (temp == NULL)
		{
			cout << "Tree is empty";

		}
		else if (temp->left != NULL)
		{
		     string a = findmin(min, temp->left);
		}
		else
		{
			min = temp->data;
			return min;
		}
	}

	bool search_tree(string element, BNode* temp)
	{
		if (temp != NULL)
		{
			if (element > temp->data)
			{
			   bool a= search_tree(element, temp->right);
			   return a;
			}
			else if (element < temp->data)
			{
				bool a= search_tree(element, temp->left);
				return a;
			}

			else
			{
				return true;
			}
			
		}
	}

	void inorder(BNode *temp)
	{
		if (temp != NULL)
		{
			cout << temp->data << endl;
			inorder(temp->left);
			inorder(temp->right);
		}
		
	}

public:

	tree()
	{
		root = NULL;
	}

	void inorder()
	{
		if (root != NULL)
		{
			inorder(root);
		}
		
	}

	void insert_tree(string element)
	{
		root = insert_tree(element, root);
	}

	bool search_tree(string element)
	{
	  bool a = search_tree(element, root);
	  return (a == true);
	}

	~tree()
	{
		Delete_Tree(root);
	}


	int isbst()
	{
		if (root != NULL)
		{
			return check_bst(root, findmin(root->data, root->left), findmax(root->data, root->right));
		}

		else
			return 0;
	}

	

};


#endif
