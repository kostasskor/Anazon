#pragma once
#include <map>
#include <string>
#include <vector>
#include "../Models/User.h"
#include "../Models/Customer.h"
#include "../Models/Seller.h"

class UserManager
{
private:
	std::vector<User*> users;
	std::map<std::string, int> nextIds;

	bool emailTaken(const std::string& email)
	{
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i]->getEmail() == email)
				return true;
		}
		return false;
	}
public:
	User* Login(const std::string& email, const std::string& password)
	{
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i]->getEmail() == email && users[i]->getPassword() == password)
				return users[i];
		}
		return nullptr;
	}
	bool Register(User* user)
	{
		if (user == nullptr) return false;

		if (emailTaken(user->getEmail()))
		{
			delete user;
			return false;
		}

		std::string role = user->getRole();

		nextIds[role] = nextIds[role] + 1;
		int newId = nextIds[role];
		user->setId(newId);
		users.push_back(user);
		return true;
	}
	Seller* findSeller(int seller_id)
	{
		for (size_t i = 0; i < users.size(); i++)
		{
			Seller* seller = dynamic_cast<Seller*>(users[i]);
			if (seller != nullptr && seller->getSellerId() == seller_id)
				return seller;
		}
		return nullptr;
	}
	~UserManager()
	{
		for (size_t i = 0; i < users.size(); i++)
			delete users[i];
	}
};