#include <iostream>
#include <string>
#include "Admin.h"

using namespace std;

Admin::Admin()
{
  tweet = '\0';
  response = '\0';
  length = 0;
  hashtag = '\0';
}

void Admin::tweet_in()
{
	cout << "Do you want to add a new tweet ? \n";
	cin >> response;
	cin.ignore();
	if (response == "yes" || response == "YES" || response == "Yes")
	{
	again:
		cout << "Tweet here: ";

		getline(cin, tweet);
		cout << endl << tweet;
		cout << endl;
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
	cout << "Do you want to ennter hashtag(type yes if you want to add hashtags): ";
	cin >> response;

	if (response == "yes" || response == "YES" || response == "Yes")
	{
		cin >> hashtag;
	}
	else
	{
		hashtag = "No";
	}
}
