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
	void addBook(const Book& book)
	{
		bookRepo->addBook(book);
	}
	void removeBook(const std::string& title)
	{
		bookRepo->removeByTitle(title);
	}
	Book* findBook(const std::string& title)
	{
		return bookRepo->findBookByTitle(title);
	}
	bool updateBook(const std::string& title, const Book& newBook)
	{
		return bookRepo->updateBook(title, newBook);
	}
	void rateBook(const std::string& title, const Rating& rating)
	{
		bookRepo->rateBook(title, rating);
	}
};