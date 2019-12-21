#pragma once
#ifndef info_H
#define info_H
#include <iostream>
using namespace std;

struct Info
{

	//int unique_id;
	string Username, Password;
	string Country;
	long int ph_no; // phone number
	
	Info()
	{
		Username = '/0';
		Password = '/0';
		Country = '/0';
		ph_no = 0;
	}

};






#endif