#pragma once
#include <string>
#include <vector>
#include "../Models/User.h"
#include "../Models/Customer.h"
#include "../Models/Seller.h"

using namespace std;

class UserManager
{
private:
	vector<User*> users;
public:
	User* Login(string email, string password)
	{
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i]->getEmail() == email && users[i]->getPassword() == password)
			{
				return users[i];
			}
		}
		return nullptr;
	}
	bool Register(User* user) 
	{
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i]->getEmail() == user->getEmail())
			{
				return false;
			}
		}
		users.push_back(user);
		return true;
	}
};