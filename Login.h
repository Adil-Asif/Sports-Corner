#pragma once
#ifndef LOGIN_H
#define LOGIN_H
#include <string>
#include <fstream>
#include <iostream>
#include "info.h"
#include "BST.h"
#include "Hashtag.h"

using namespace std;

class Login {
	private:
		Info user_data;
     public:

		void Sign_in(tree* alluser)
		{

			fstream fin;
			int tr = 3;
			string pass;
		sign_pas:
			cout << "Enter Username:";
			cin.ignore();
			getline(cin, user_data.Username);
			if (alluser->search_tree(user_data.Username) != 1) {
				cout << "User Does Not Exits" << endl;
				return;
			}
			else
			{
				fin.open(user_data.Username + ".txt", ios::in);
			}

			if (!fin) {
				cout << "failed to open";
			}
			else {

				to_diplay abc;
				fin >> user_data.Username;
				fin >> user_data.Password;
				fin >> user_data.Country;
				fin >> user_data.ph_no;

				while (!fin.eof())
				{
					fin >> abc.id;
					fin >> abc.category;
					user_data.upvote_list.add_to_head(abc);
				}
				fin.close();

				cout << "Enter Password: ";
				cin >> pass;
				string cipher = decrypt(user_data.Password);

				if (pass != cipher) {
					cout << "Wrong Username or Password!(" << tr - 1 << " attemp left)" << endl;
					tr--;
					if (tr == 0)
					{
						cout << "Maximium trials reached";
						delay(2);
						system("cls");
						system("Color B0");
						goto back;
					}
					goto sign_pas;
				}
			}
			cout << "Sign In Successfull!";
			delay(2);
			system("cls");
			system("Color B0");
			int choice;

			do
			{


				cout << "Enter 1 to Update Password\nEnter 2 to Display Saved Upvotes tweets\nEnter 3 to Display tweets\nEnter 4 to Exit\nEnter your choice: ";
				cin >> choice;
				delay(2);
				system("cls");
				system("Color B0");
				if (choice == 1)
				{
					Update_Password();
				}
				else if (choice == 2)
				{
					Display_Upvotes_Tweets();
				}
				else if (choice == 3)
				{
					Display_Tweets();
				}
				else if (choice != 4)
				{
					cout << "Invalid Input";
				}
			} while (choice != 4);
			fin.close();
		back:
			{}
		}

		void Sign_up(tree *alluser)
		{

			Info obj;

			while (1)
			{
				cout << "Enter User Name(only Alphabets and Numbers are allowed):";
				cin.ignore();
				getline(cin, obj.Username);

				if (username_format(obj.Username))
				{
					if (alluser->search_tree(obj.Username)==1)
					{
						cout << endl << "User Already Taken!" << endl;
						cout << "Re-enter" << endl;
					}
					else
					{
						break;
					}
				}
				else
				{
					cout << "Wrong Format";
				}
			}
			cout << endl;
			while (1)
			{
				cout << "Enter Password(min length 8 - should include Capital and small letters and numbers also)";
				cout << " For e.g (DSs123): ";
				cin >> obj.Password;
				if (check_pass(obj.Password) == 0)
				{
					cout << "Wrong Password Format" << endl;

				}
				else
				{
					break;
				}
			}
			cout << "Enter Country: ";
			cin >> obj.Country;
			cout << "Enter Your Phone Number: ";
			cin >> obj.ph_no;
			fstream fout;
			fout.open(obj.Username + ".txt", ios::out);
			if (!fout) {
				cout << "failed TO open file!";
			}
			else {
				fout << obj.Username << endl;
				obj.Password = encrypt(obj.Password);
				fout << obj.Password << endl;
				fout << obj.Country << endl;
				fout << obj.ph_no << endl;
			}

			fout.close();
			fout.open("alluser.txt", ios::app);
			fout << obj.Username << endl;
			alluser->insert_tree(obj.Username);
			fout.close();
			char b;
			cout <<endl<<"Press Any key to exit: ";
			cin >> b;
			delay(2);
			system("cls");
			system("Color B0");


		}

		bool check_pass(string pass) {
			bool flag1 = 0;
			bool flag2 = 0;
			bool flag3 = 0;
			if (pass.length() >= 8) {
				int b = pass.length();
				for (int i = 0; i < b; i++) {
					if (pass[i] >= '0' && pass[i] <= '9') {
						flag1 = 1;
					}
					else if (pass[i] >= 'A' && pass[i] <= 'Z') {
						flag2 = 1;
					}
					else if (pass[i] >= 'a' && pass[i] <= 'z') {
						flag3 = 1;
					}

				}
				if (flag1 && flag2 && flag3) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				cout << "Password length should be greater than 7";
				return false;
			}
		}
		bool username_format(string a)
		{
			int len = a.length();
			for (int i = 0; i < len; i++)
			{
				if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 48 && a[i] <= 57))
				{
				}
				else
				{
					return 0;
				}
			}
			return 1;
		}
		string encrypt(string Pass) {
			int b = Pass.length();
			for (int i = 0; i < b; i++) {
				Pass[i] = Pass[i] + 2;
			}
			return Pass;
		}

		string decrypt(string Pass) {
			int b = Pass.length();
			for (int i = 0; i < b; i++) {
				Pass[i] = Pass[i] - 2;
			}
			return Pass;
		}

		void Update_Password()
		{
			string pass, Npass1, Npass2;

			int count = 0;
			do
			{
				cout << "Enter Old Password: ";
				cin >> pass;
				cout << "Enter New Password: ";
				cin >> Npass1;
                    cout << "Re-enter New Password: ";
				cin >> Npass2;
				if (check_pass(Npass1))
				{
					string cipher= decrypt(user_data.Password);
					if (cipher == pass)
					{
						if (Npass1 == Npass2)
						{
							user_data.Password = encrypt(Npass1);
							ofstream fptr;
							fptr.open(user_data.Username.c_str(), ios::out);
							fptr << user_data.Username<<endl;
							fptr << user_data.Password<<endl;
							fptr << user_data.Country<<endl;
							fptr << user_data.ph_no<<endl;
							while (!user_data.upvote_list.list_empty())
							{
								to_diplay a = user_data.upvote_list.Get_Head();
								fptr << a.category<<a.id<<endl;
							}
						}
						else
						{
							cout << "New Passwords do not match";
						}
					}
					else
					{
						cout << "Wrong Old PassWord";
					}
				}

			} while (count!=3);
			

		}

		void Display_Tweets()
		{
			Hashtag abc;
			abc.setting_up(user_data.Username);

			char a;
			cout << "Press Any character to exit: ";
			cin >> a;
			delay(1);
			system("cls");
			system("Color B0");
		}
		void Display_Upvotes_Tweets()
		{
			ifstream fptr;
			string filename, nam ,a;
			int vote=0;
			Node<to_diplay> *temp = user_data.upvote_list.ret_head();
			string tweet, hastag;
			temp = temp->Next;


			cout << "............................................" << endl;
			cout << ".Welcome to Upvotes Tweet section of our project." << endl;
			cout << ".``````````````````````````````````````````." << endl;
			cout << "............................................" << endl << endl;


			while (temp != NULL)
			{
				filename = temp->data.category;
				nam = temp->data.id;
				fptr.open(filename.c_str(), ios::in);
				while (!fptr.eof())
				{
					fptr >> a;
					fptr >> vote;
					if (a == nam)
					{
						break;
					}
				}
				fptr.close();

				nam = nam + ".txt";
				fptr.open(nam.c_str(), ios::in);
				getline(fptr, tweet);
				fptr >> hastag;
				fptr.close();
				display(temp->data.id, vote, tweet, hastag);
				temp = temp->Next;
			}
			char b;
			cout << "Press Any character to exit: ";
			cin >> b;
			delay(1);
			system("cls");
			system("Color B0");
			
		}

		
};

#endif // !LOGIN_H