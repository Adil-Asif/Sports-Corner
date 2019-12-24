#pragma once
#ifndef info_H
#define info_H
#include <iostream>
#include "List.h"
#include "Utility.h"
using namespace std;


struct Info
{

	//int unique_id;
	string Username, Password;
	string Country, ph_no; // phone number
	List<to_diplay> upvote_list; //this list will contain the upvotes tweet ids by the user 
	Info()
	{
		Username = '\0';
		Password = '\0';
		Country = '\0';
		ph_no = '\0';
	}
};

#endif