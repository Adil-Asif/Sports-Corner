#pragma once
#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
using namespace std;
class Login {
	private:
		//int unique_id;
		string Username, Password;
		string Country;
		long int ph_no; // phone number
	public:
		Login();
		void Sign_in();
		void Sign_up();
		//utility func
		string encrypt(string pass);
		string decrypt(string pass);
		bool check_pass(string pass);
		//int get_unique();
		bool check_username(string fileName);
		bool username_format(string);

};

#endif // !LOGIN_H