#pragma once
#include <string>
#include "User.h"

class Customer : public User
{
private:
	int customerId;
public:
	Customer(const std::string& name, const std::string& email, const std::string& password, int customerId) 
	: User(name, email, password)
	{
		this->customerId = customerId;
	}
	int getCustomerId() const
	{
		return customerId;
	}
};