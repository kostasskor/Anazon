#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "..\Models\Book.h"

using namespace std;

class BookManager
{
private:
	vector<Book> books;
public:
	void AddBook(Book book)
	{
		books.push_back(book);
	}
	void RemoveBook(string title)
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].getTitle() == title)
			{
				books.erase(books.begin() + i);
				cout << "Book removed." << endl;
				return;
			}
		}
		cout << "Book not found." << endl;
	}
	Book* findBook(string title)
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].getTitle() == title)
			{
				cout << "Book found: " << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
				return &books[i];
			}
		}
		cout << "Book not found." << endl;
		return nullptr;
	}
	void updateBook(string title, Book newBook)
	{
		Book* book = findBook(title);
		if (book == nullptr)
		{
			cout << "Book not found." << endl;
			return;
		}
		*book = newBook;
		cout << "Book updated." << endl;
	}
	void rateBook(string title, string review)
	{
		Book* book = findBook(title);
		if (book == nullptr)
		{
			cout << "Book not found." << endl;
			return;
		}
		vector<string> reviews = book->getReviews();
		reviews.push_back(review);
		book->setReviews(reviews);
		cout << "Review added." << endl;
	}
};