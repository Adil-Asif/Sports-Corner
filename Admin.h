#pragma once
#ifndef Admin_H
#define Admin_H
#include "Queue.h"
#include "BST.h"
#include "List.h"
#include "Utility.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Admin {
private:
	int length;
	string tweet;
	string response,hashtag;

public:
	
	Admin()
	{
		tweet = '\0';
		response = '\0';
		length = 0;
		hashtag = '\0';
	}

	void tweet_in()
	{
		int flag = false;

		cout << "Do you want to add a new tweet: ";
		cin >> response;
		//cin.ignore();
		do
		{
			if (response == "yes" || response == "YES" || response == "Yes")
			{
			again:
				
				cout << "Enter Tweet:  ";
				cin.ignore();
				getline(cin, tweet);

				cout << endl << tweet;
				cout << endl;
			}
			else
			{
				break;
			}
			length = tweet.length();
			cout << "length is " << length << endl;
			if (length > 280)
			{
				cout << "Tweet's length greater than 280\n please make it shorter\n";
				goto again;
			}
			else {
				cout << endl << "Tweeted sucessfully" << endl;
			}
			cout << "Do you want to enter hashtag(type yes if you want to add hashtags): ";
			cin >> response;

			if (response == "yes" || response == "YES" || response == "Yes")
			{
				
				cout << "Enter HashTag: ";
				cin >> hashtag;
			}
			else
			{
				hashtag = "No";
			}
			string filename;
			
			if (category("Cricket dictionary.txt", tweet))
			{
				filename = "Cricket.txt";
				cout << "Category: Cricket";
			}
			else if (category("Tennis dictionary.txt", tweet))
			{
				filename = "Tennis.txt";
				cout << "Category: Tennis";
			}
			else
			{
				filename = "Other.txt";
				cout << "Category: Other";
			}

			cout << endl;
			insert_file(filename, tweet, hashtag);
			char a;
			cout << endl;
			cout << "Enter Any Key to exit: ";
			cin >> a;
			delay(1);
			system("cls");
			system("Color B0");
			cout << "Do you want to enter another tweet: ";
			cin >> response;
		} while (response != "No" && response != "NO" && response != "no");

	}

	
	void insert_file(string filename, string tweet, string hashtag)
	{
		fstream fptr;
		string tweet_no,vote,max;
		fptr.open(filename.c_str(), ios::in);
		
		while (!fptr.eof())
		{
			fptr >> tweet_no;
			fptr >> vote;
			if (max < tweet_no)
			{
				max=tweet_no;
			}
		}

		tweet_no = max;
		string cat;
		fptr.close();
		fptr.open(filename.c_str(), ios::app);
		int a = atoi(tweet_no.c_str());
		a++;
		tweet_no=to_string(a);
		cat = tweet_no;
		tweet_no = tweet_no + ".txt";
		fptr << cat;
		fptr << " 0"<<endl;
		fptr.close();
		fptr.open(tweet_no.c_str(), ios::out);
		fptr << tweet<<endl;
		fptr << hashtag << endl;
		fptr.close();
		cout << "Tweet ID: " << cat;
	}


	bool category(string filename , string tweet)
	{
		ifstream fptr;
		string word;
		fptr.open(filename.c_str(), ios::in);
		while (!fptr.eof())
		{
			getline(fptr,word);
			word = upper(word);
			tweet = upper(tweet);
			if(KMP(word,tweet))
			{
				fptr.close();
				return true;
			}
		}
		fptr.close();
		return false;
	}

	void signin()
	{
		string username, password;
		bool flag = false;
		int count = 0;

		do
		{

		cout << "Enter username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;

			if (username == "Adil" && password == "SportsCorner")
			{
				cout << "\n\n\n\n\t\t\t\tWelcome to the Admin Portal Adil Asif";
				delay(2);
				system("cls");
				system("Color B0");
				flag = true;

				Admin::tweet_in();
			}
			else
			{
				cout << "WRONG PASSWORD Entered";
				count++;
				cout<<endl << "Number of Tries Left " << 3 - count << endl;
			}
		} while (flag != true && count!=3);

	}

};

#endif // !LOGIN_H 
