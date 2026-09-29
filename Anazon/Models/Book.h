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
	int bookId;
	std::vector<Rating> reviews;
public:
	Book(const std::string& title, const std::string& author, double price, int bookId)
	{
		this->title = title;
		this->author = author;
		this->price = price;
		this->bookId = bookId;
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
	int getBookId() const
	{
		return bookId;
	}
	const std::vector<Rating>& getReviews() const
	{
		return reviews;
	}
	double totalPrice(int quantity) const
	{
		return price * quantity;
	}
	size_t getReviewCount() const
	{
		return reviews.size();
	}
	float getAverageRating() const
	{
		if (reviews.empty()) 
		{
			return 0.0;
		}

		int total = 0;
		for (size_t i = 0; i < reviews.size(); i++) 
		{
			total += reviews[i].getScore();
		}
		return (float)total / reviews.size();
	}
	void addReview(const Rating& review)
	{
		reviews.push_back(review);
	}
};