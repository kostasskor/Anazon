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
	int getReviewCount() const
	{
		return reviews.size();
	}
	double getAverageRating() const
	{
		if (reviews.empty()) 
		{
			return 0.0;
		}

		int total = 0;
		for (int i = 0; i < reviews.size(); i++) 
		{
			total += reviews[i].getScore();
		}
		return total / reviews.size();
	}
	void addReview(const Rating& review)
	{
		reviews.push_back(review);
	}
};