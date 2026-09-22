#pragma once
#include <string>
#include "User.h"

class Customer : public User
{
public:
	Customer(const std::string& name, const std::string& email, const std::string& password)
	: User(name, email, password)
	{
	}
	std::string getRole() const override
	{
		return "Customer";
	}
	int getCustomerId() const
	{
		return getId();
	}
};