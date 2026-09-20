#pragma once
#include <string>
#include "User.h"

class Seller : public User
{
private:
	std::string address;
	int sellerId;
public:
	Seller(std::string name, std::string email, std::string password, std::string address) 
	: User(name, email, password)
	{
		this->address = address;
		this->sellerId = sellerId;
	}
	const std::string& getAddress() const
	{
		return address;
	}
};