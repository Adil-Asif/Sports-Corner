#pragma once
#ifndef utility_H
#define utility_H
#include "BST.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;


	int* Get_Prefix(string word ,int n) {
		int m = n;
		int* prefix= new int[m];
		int len = 0;

		prefix[0] = 0; 

		int i = 1;
		while (i < m) {
			if (word[i] == word[len]) {
				len++;
				prefix[i] = len;
				i++;
			}
			else 
			{
			if (len != 0) {
					len = prefix[len - 1];

				}
				else  
				{
					prefix[i] = 0;
					i++;
				}
			}
		}
		return prefix;
	}

	bool KMP(string Word, string Tweet)
	{
		int* prefix;
	     prefix= Get_Prefix(Word,Word.length());
		int sWord =Word.length() ;
		int sTweet = Tweet.length();
		int i = 0;
		int j = 0;
		while (i < sTweet) {
			if (Word[j]<'A' && Word[j]>'Z')
			{
				j++;
			}
			if (Tweet[i]<'A' && Tweet[i]>'Z')
			{
				i++;
			}
			else
			{
				if (Tweet[i] == Word[j]) {
					i++;
					j++;
				}
				if (j == sWord) {
					return true;
				}
				else if (i < sTweet && Word[j] != Tweet[i]) {
					if (j != 0) {
						j = prefix[j - 1];
					}
					else
						i = i + 1;
				}

			}
		}
		return false;
	}

	string upper(string a)
	{
		int m = a.length();
		string b = a;

		for (int i = 0; i < m; i++)
		{
			if (a[i] >= 'a' && a[i] <= 'z')
			{
				b[i] = a[i] - 32;
			}
			else
			{
				b[i] = a[i];
			}
		}

		return b;
	}


	void display(string filename, int votes, string tweet,string has)
	{
		int space_count = 0;
		cout<<"Tweet Code: "<<filename<<endl;
		int b = tweet.length();
		for (int i = 0; i < b; i++)
		{
			if (tweet[i] == ' ')
			{
				space_count++;
			}

			if (space_count == 10)
			{
				space_count = 0;
				cout << endl;
				i++;
			}
			cout << tweet[i];
		}
		cout << endl << has;
		cout << endl << "Upvotes: " << votes << endl;
		cout << "............................................" << endl << endl;
	}

	

	string vote_tweet(string username, tree displayed_ids, string filename)
	{
		string id;

			cout << "Enter Tweet Id you want to upvote: ";
			cin >> id;
			if (displayed_ids.search_tree(id))
			{
				ofstream fptr;
				username = username + ".txt";
				fptr.open(username.c_str(), ios::app);
				fptr << id << " "<<filename<<endl;
			}
		return id;
	}

	struct to_diplay
	{
		string category, id;
	};


	void delay(int seconds)
	{
		clock_t initial = clock();

		while (clock() < initial + (seconds * 1000))
		{
		}
	}

#endif