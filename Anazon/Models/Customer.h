#pragma once
#include <string>
#include "User.h"

using namespace std;

class Customer : public User
{
public:
	Customer(string name, string email, string password) : User(name, email, password)
	{
	}
};