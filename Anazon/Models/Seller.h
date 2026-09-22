#pragma once
#include <string>
#include "User.h"

class Seller : public User
{
private:
	std::string address;
public:
	Seller(const std::string& name, const std::string& email, const std::string& password, const std::string& address)
	: User(name, email, password)
	{
		this->address = address;
	}
	std::string getRole() const override
	{
		return "Seller";
	}
	const std::string& getAddress() const
	{
		return address;
	}
	int getSellerId() const
	{
		return getId();
	}
};