#pragma once
#include <string>
#include <vector>
#include "..\Models\User.h"
#include "..\Models\Customer.h"
#include "..\Models\Seller.h"

using namespace std;

class UserManager
{
private:
	static vector<User> users;
public:
	static bool Login(string email, string password)
	{
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i].getEmail() == email && users[i].getPassword() == password)
			{
				return true;
			}
		}
		return false;
	}
	static bool Register(Customer customer) 
	{
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i].getEmail() == customer.getEmail())
			{
				return false;
			}
		}
		users.push_back(customer);
		return true;
	}
	static bool Register(Seller seller) 
	{
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i].getEmail() == seller.getEmail())
			{
				return false;
			}
		}
		users.push_back(seller);
		return true;
	}
};