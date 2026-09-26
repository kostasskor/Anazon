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
	void saveBook(const Book& book)
	{
		books.push_back(book);
	}
	bool removeByTitle(const std::string& title)
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].getTitle() == title)
			{
				books.erase(books.begin() + i);
				return;
			}
		}
	}
	Book* findBookByTitle(const std::string& title)
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].getTitle() == title) return &books[i];
		}
		return nullptr;
	}
	Book* findBookById(int id)
	{
		for (int i = 0; i < books.size(); i++) 
		{
			if (books[i].getBookId() == id) return &books[i];
		}
	}
	bool UpdateBook(const std::string& title, const Book& newBook)
	{
		Book* book = findBookByTitle(title);
		if (book == nullptr) return;
		*book = newBook;
	}
	void addRating(const std::string& title, const Rating& rating)
	{
		Book* book = findBookByTitle(title);
		if (book == nullptr) return;
		book->addReview(rating);
	}
};