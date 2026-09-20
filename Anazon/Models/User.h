#pragma once
#include <string>

class User
{
private:
	std::string name;
	std::string password;
	std::string email;
public:
	User(const std::string& name, const std::string& email, const std::string& password)
	{
		this->name = name;
		this->email = email;
		this->password = password;
	}
	const std::string& getName() const
	{
		return name;
	}
	const std::string& getEmail() const
	{
		return email;
	}
	const std::string& getPassword() const
	{
		return password;
	}
};