#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "../Models/Book.h"

class BookManager
{
private:
	std::vector<Book> books;
public:
	void AddBook(const Book& book)
	{
		books.push_back(book);
	}
	void RemoveBook(const std::string& title)
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].getTitle() == title)
			{
				books.erase(books.begin() + i);
				std::cout << "Book removed." << std::endl;
				return;
			}
		}
		std::cout << "Book not found." << std::endl;
	}
	Book* findBook(const std::string& title)
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].getTitle() == title) 
				return &books[i];
		}
		return nullptr;
	}
	void updateBook(const std::string& title, const Book& newBook)
	{
		Book* book = findBook(title);
		if (book == nullptr)
			return;
		*book = newBook;
	}
	void rateBook(const std::string& title, const Rating& rating)
	{
		Book* book = findBook(title);
		if (book == nullptr)
			return;
		book->addReview(rating);
	}
};