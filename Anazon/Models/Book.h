#pragma once
#include <string>
#include <vector>
#include "Rating.h"

class Book
{
private:
	std::string title;
	std::string author;
	double price;
	std::vector<Rating> reviews;
public:
	Book(const std::string& title, const std::string& author, double price)
	{
		this->title = title;
		this->author = author;
		this->price = price;
	}
	const std::string& getTitle() const
	{
		return title;
	}
	const std::string& getAuthor() const
	{
		return author;
	}
	double getPrice() const
	{
		return price;
	}
	const std::vector<Rating>& getReviews() const
	{
		return reviews;
	}
	void setReviews(const std::vector<Rating>& reviews)
	{
		this->reviews = reviews;
	}
};