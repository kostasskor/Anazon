#pragma once
#include <string>
#include <vector>

using namespace std;

class Book
{
private:
	string title;
	string author;
	double price;
	vector<string> reviews;
public:
	Book(string title, string author, double price)
	{
		this->title = title;
		this->author = author;
		this->price = price;
	}
	string getTitle()
	{
		return title;
	}
	string getAuthor()
	{
		return author;
	}
	double getPrice()
	{
		return price;
	}
	vector<string> getReviews()
	{
		return reviews;
	}
	vector<string> setReviews(vector<string> reviews)
	{
		this->reviews = reviews;
	}
};