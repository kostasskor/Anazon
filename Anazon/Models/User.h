#pragma once
#include <string>

using namespace std;

class User
{
private:
	string name;
	string password;
	string email;
public:
	User(string name, string email, string password)
	{
		this->name = name;
		this->email = email;
		this->password = password;
	}
	string getName()
	{
		return name;
	}
	string getEmail()
	{
		return email;
	}
	string getPassword()
	{
		return password;
	}
};