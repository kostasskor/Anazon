#pragma once
#include <string>
#include "User.h"

class Seller : public User
{
private:
	std::string address;
	int sellerId;
public:
	Seller(const std::string& name, const std::string& email, const std::string& password, const std::string& address, int sellerId) 
	: User(name, email, password)
	{
		this->address = address;
		this->sellerId = sellerId;
	}
	const std::string& getAddress() const
	{
		return address;
	}
	int getSellerId() const
	{
		return sellerId;
	}
};