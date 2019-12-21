#include "Login.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
Login::Login() {
		
		Username = '/0' ;
		Password = '/0';
		Country = '/0';
		ph_no = 0;
}
void Login::Sign_in() {
	fstream fin;
	
	int tr = 3;
	string pass;
	cout << "Enter Username:";
	
	getline(cin,Username);
	cout << Username;
	if (check_username(Username)) {
		cout << "User DoesNot Exits"<<endl;
	}
	else
	{
		fin.open(Username + ".txt", ios::in);
	}
	
	if (!fin) {
		cout << "failed to open";
	}
	else{
		fin >> Username;
		fin >> Password;
		
	sign_pas:
		cout << "Enter Password";
		cin >> pass;
		pass = decrypt(pass);
		
		if (pass != Password) {
			cout << "Wrong Pass!(" << tr-1 << " attemp left)" << endl;
			tr--;
			if (tr == 0) {
				cout << "Terminating Program!" << endl;
				exit(0);
			}
			goto sign_pas;
		}
	}
	cout << "Sign In Successfull!";
	fin.close();
}
void Login::Sign_up() {
     

	while (1)
	{
		cout << "Enter User Name(only Alphabets and Numbers are allowed):";
		
		 getline(cin,Username);
		 cout << Username;
		string chk = Username + ".txt";
		if (username_format(Username))
		{
			if (check_username(chk))
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
		cin >> Password;
		if (check_pass(Password) == 0)
		{
			cout << "Wrong Password Format"<<endl;
			
		}
	}
	cout << "Enter Country: ";
	cin >> Country;
	cout << "Enter Your Phone Number: ";
	cin >> ph_no;
	fstream fout;
	fout.open(Username + ".txt", ios::out | ios::trunc);
	if (!fout) {
		cout << "failed TO open file!";
	}
	else {
		fout << Username << endl;
		Password = encrypt(Password);
		fout << Password << endl;
		fout << Country << endl;
		fout << ph_no << endl;
	}
	
	fout.close();
	fout.open("alluser.txt",  ios::app);
	fout << Username << endl;
	fout.close();

}

bool Login::check_username(string filename) {
	ifstream infile(filename);
	return infile.good();
}
bool Login::check_pass(string pass) {
	bool flag1 = 0;
	bool flag2 = 0;
	bool flag3 = 0;
	if (pass.size() >= 8) {
		for (int i = 0; i < pass.size(); i++) {
			if (pass[i] >= '0' && pass[i] <='9' ) {
				flag1 = 1;
			}
			else if (pass[i] >= 'A' && pass[i] <= 'Z' ) {
				flag2 = 1;
			}
			else if (pass[i] >= 'a' && pass[i] <= 'z') {
				flag3 = 1;
			}
			
		}
		if ( flag1 && flag2 && flag3  ) {
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
bool Login::username_format(string a)
{
	int len = a.length();
	for (int i = 0; i < len; i++)
	{
		if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z') || (a[i] >=48 && a[i] <= 57))
		{}
		else
		{
			return 0;
		}
	}
	return 1;
}
string Login::encrypt(string Pass) {
	for (int i = 0; i < Pass.size(); i++) {
		Pass[i] = Pass[i] + 2;
	}
	return Pass;
}

string Login::decrypt(string Pass) {
	for (int i = 0; i < Pass.size(); i++) {
		Pass[i] = Pass[i] - 2;
	}
	return Pass;
}