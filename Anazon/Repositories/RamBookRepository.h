#pragma once
#include <string>
#include <vector>
#include "../Models/Book.h"
#include "../Models/Rating.h"
#include "IBookRepository.h"

class RamBookRepository : public IBookRepository
{
private:
	std::vector<Book> books;
public:
	void addBook(const Book& book) override
	{
		books.push_back(book);
	}
	bool removeByTitle(const std::string& title) override
	{
		for (int i = books.size() - 1; i >= 0; i--)
		{
			if (books[i].getTitle() == title)
			{
				books.erase(books.begin() + i);
				return true;
			}
		}
		return false;
	}
	Book* findBookByTitle(const std::string& title) override
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].getTitle() == title) return &books[i];
		}
		return nullptr;
	}
	Book* findBookById(int id) override
	{
		for (int i = 0; i < books.size(); i++) 
		{
			if (books[i].getBookId() == id) return &books[i];
		}
		return nullptr;
	}
	bool updateBook(const std::string& title, const Book& newBook) override
	{
		Book* book = findBookByTitle(title);
		if (book == nullptr) return false;
		*book = newBook;
		return true;
	}
	bool rateBook(const std::string& title, const Rating& rating) override
	{
		Book* book = findBookByTitle(title);
		if (book == nullptr) return false;
		book->addReview(rating);
		return true;
	}
};