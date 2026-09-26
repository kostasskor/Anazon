#pragma once
#include "../Models/Book.h"

class IBookRepository
{
public:
	virtual ~IBookRepository() = default;
	virtual void saveBook(const Book& book);
	virtual bool removeByTitle(const std::string& title);
	virtual Book* findBookByTitle(const std::string& title);
	virtual Book* findBookById(int id);
	virtual bool UpdateBook(const std::string& title, const Book& book);
	virtual void addRating(const std::string& title, const Rating& rating);
};