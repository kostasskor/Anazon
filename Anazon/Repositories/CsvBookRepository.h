#pragma once
#include <string>
#include <vector>
#include "../Models/Book.h"
#include "../Models/Rating.h"
#include "IBookRepository.h"

class RamBookRepository : public IBookRepository
{
public:
	void saveBook(const Book& book)
	{
		
	}
	bool removeByTitle(const std::string& title)
	{
		return false;
	}
	Book* findBookByTitle(const std::string& title)
	{
		return nullptr;
	}
	Book* findBookById(int id)
	{
		return nullptr;
	}
	bool UpdateBook(const std::string& title, const Book& newBook)
	{
		return false;
	}
	void addRating(const std::string& title, const Rating& rating)
	{
		
	}
};