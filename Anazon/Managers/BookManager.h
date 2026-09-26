#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "../Models/Book.h"
#include "../Repositories/IBookRepository.h"

class BookManager
{
private:
	IBookRepository* bookRepo;

public:
	BookManager(IBookRepository* bookRepo)
	{
		this->bookRepo = bookRepo;
	}
	void AddBook(const Book& book)
	{
		bookRepo->saveBook(book);
	}
	void RemoveBook(const std::string& title)
	{
		bookRepo->removeByTitle(title);
	}
	Book* findBook(const std::string& title)
	{
		return bookRepo->findBookByTitle(title);
	}
	bool updateBook(const std::string& title, const Book& newBook)
	{
		bookRepo->UpdateBook(title, newBook);
	}
	void rateBook(const std::string& title, const Rating& rating)
	{
		bookRepo->addRating(title, rating);
	}
};