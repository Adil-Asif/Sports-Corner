#pragma once
#ifndef Hashtag_H
#define Hashtag_H
#include <fstream>
#include<string>
#include <iostream>
#include "Utility.h"
#include "Heap.h"
#include "List.h"
#include "BST.h"

class Hashtag
{

private:
	
	List<output_file> Selected_Hashtag_Display;
	Heap sorted_Selected_Hashtag_Display;
	tree diplayed_ids;


public:


	void setting_up(string username)
	{
		string hash, filename;
		int option;

			cout << "............................................" << endl;
			cout << ".Welcome to trending section of our project." << endl;
			cout << ".``````````````````````````````````````````." << endl;
			cout << "............................................" << endl << endl;
			cout << "Here you can view trends of the following sports:\n~Enter 1 for Cricket\n~Enter 2 for tennis\n~Enter 3 for Other Sports\nEnter your choice: ";
			cin >> option;
			if (option == 1)
			{
				filename = "Cricket.txt";
			}
			else if (option == 2)
			{
				filename = "Tennis.txt";
			}
			else if (option == 3)
			{
				filename = "Other.txt";
			}
			if(option==1 || option==2 || option == 3)
			{
				create_list(filename);
				Node<output_file> *temp=Selected_Hashtag_Display.ret_head();
				sorted_Selected_Hashtag_Display.insert_array(Selected_Hashtag_Display);
				sorted_Selected_Hashtag_Display.get_sorted_list(Selected_Hashtag_Display);
				display_hashtag();
				cout << "Enter the hashtag for which you want to search:" << endl;
				cin >> hash;
				search(hash,username,filename);
			}
				

	}

	void create_list(string filename)
	{
		output_file store;
		ifstream fptr;
		

		fptr.open(filename, ios::in);

		if (!fptr.fail())
		{
			while (!fptr.eof())
			{
				fptr >> store.filename;
				fptr >> store.upvotes;
				Selected_Hashtag_Display.add_to_head(store);
			}
		   fptr.close();
		}
	}

	void display_hashtag()
	{
		string temp1, temp3 , temp2;

		Node<output_file>* temp = Selected_Hashtag_Display.ret_head();
		List<string> hashl;
		for (temp; temp != NULL; temp = temp->Next)
		{
			temp1= temp->data.filename;
			temp1 = temp1 + ".txt";
			ifstream fptr;
			fptr.open(temp1.c_str(), ios::in);

			if (!fptr.fail())
			{

				getline(fptr, temp2);

				while (!fptr.eof())
				{
					fptr >> temp3;
					if (temp3 == "NO" || temp3 == "No")
					{
						break;
					}
					else
					{
						hashl.add_to_head(temp3);
					}
				}
				fptr.close();
			}
		}

		hashl.remove_duplicate();
		displayhash(hashl);
	}
		
	
	void displayhash(List<string> hashl)
	{
		Node<string>* temp = hashl.ret_head();
		cout << "These are the following hastags available: " << endl;
		for (int i = 1; temp != NULL; temp = temp->Next, i++)
		{
			cout << i << ": " << temp->data << endl;
		}
		cout << "---------------------------------------------------------------------------------";
		cout << endl << endl;
	}
	

	void search(string hashtag,string username,string filename)
	{//	cout<<"hashtag is "<<hashtag<<endl;
		string temp1, temp3;
		string temp2, has;
		has = hashtag;
		Node<output_file>* temp=Selected_Hashtag_Display.ret_head();
		
		//	cout<<"we are here"<<endl;
		for (temp; temp != NULL; temp = temp->Next)
		{
			//cout<<"we are here"<<endl;	
		     temp1 = temp->data.filename;

			temp1 = temp1 + ".txt";
			ifstream fptr;
			fptr.open(temp1.c_str(), ios::in);
               
			if (!fptr.fail())
			{
			  getline(fptr,temp2);
			  int i = temp2.length();
			  List<string> hashl;
			  while (!fptr.eof())
			  {
			    fptr>> temp3;
			    hashl.add_to_head(temp3);
			  }
			  
			  find_tag(temp2, hashl.ret_head(), hashtag,temp->data.filename, temp->data.upvotes);
			  fptr.close();

			}

		}

		string choice;
		cout << "Enter Yes if you want to upvote a tweet: ";
		cin >> choice;
		if (choice == "yes" || choice == "YES" || choice == "Yes")
		{
			string id = vote_tweet(username, diplayed_ids, filename);
			 Node<output_file>* temp7 = Selected_Hashtag_Display.ret_head();

			bool flag = false;
			while (1)
			{
				if (temp7->data.filename == id)
				{
					temp7->data.upvotes++;
					break;
				}
				else
				{
					temp7 = temp7->Next;
				}
			}

			temp7= Selected_Hashtag_Display.ret_head();
			fstream fptr;
			fptr.open(filename.c_str(),ios::out);
			temp7 = temp7->Next;
			while (temp7 != NULL)
			{
				fptr << temp7->data.filename << " " << temp7->data.upvotes << endl;
				temp7 = temp7->Next;
			}


		}

	}

	void find_tag(string tweets, Node<string>* temp, string hashtag,string filename , int vote)
	{
		for (temp; temp->Next != NULL; temp = temp->Next)
		{	//cout<<temp->hasht<<endl;
			if (temp->data== "NO"|| temp->data== "No")
			{
				//	cout<<"it has no hastag"<<endl;
				return;
			}

			else if (temp->data == hashtag)
			{
				diplayed_ids.insert_tree(filename);
				display(filename, vote, tweets,hashtag);
				return;
			}
			else {
				//cout<<"Searching "<<endl;
			}
		}
	}




};


#endif // !Hastag_H

