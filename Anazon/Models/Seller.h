#pragma once
#include <string>
#include "User.h"

using namespace std;

class Seller : public User
{
private:
	string address;

public:
	Seller(string name, string email, string password, string address) : User(name, email, password)
	{
		this->address = address;
	}
	string getAddress()
	{
		return address;
	}
};