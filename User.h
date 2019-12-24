#pragma once
#ifndef user_H
#define user_H
#include <fstream>
#include <iostream>
#include "Login.h"
#include "Queue.h"
#include "BST.h"
#include "List.h"
#include "info.h"

using namespace std;

class user:protected Login
{
private:
	tree alluser;

public:
	   
	   user()
	   {
		   ifstream fptr;
		   string username;

		   fptr.open("alluser.txt", ios::in);
		
		   if(!fptr.fail())
		   {
			   fptr >> username;
			   while (!fptr.eof())
			   {
				 alluser.insert_tree(username);
				 fptr >> username;
			   }
		   }
		   
		   menu();
	   }

	   void menu()
	   {
		   int choice;

		   do
		   {
			   cout << "Enter 1 to sign-up\nEnter 2 to sign-in\nEnter 3 to exit\nEnter your choice: ";
			   cin >> choice;
			   delay(2);
			   system("cls");
			   system("Color B0");
			   if (choice == 1)
			   {
				   Sign_up(&alluser);
			   }
			   else if (choice == 2)
			   {
				   Sign_in(&alluser);
			   }
			   else if (choice != 3)
			   {
				   cout << "Wrong Input";
			   }
		   } while (choice != 3);
		   
	   }



};






#endif