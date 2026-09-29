#pragma once
#include "../Models/Book.h"

class IBookRepository
{
public:
	virtual ~IBookRepository() = default;
	virtual void addBook(const Book& book) = 0;
	virtual bool removeByTitle(const std::string& title) = 0;
	virtual Book* findBookByTitle(const std::string& title) = 0;
	virtual Book* findBookById(int id) = 0;
	virtual bool updateBook(const std::string& title, const Book& book) = 0;
	virtual bool rateBook(const std::string& title, const Rating& rating) = 0;
};