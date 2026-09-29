#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "../Models/Book.h"
#include "../Models/Rating.h"
#include "IBookRepository.h"


class CsvBookRepository : public IBookRepository
{
private:
	const std::string bookFile = "books.csv";

	std::string serializeBook(const Book& book)
	{
		std::stringstream line;
		line << book.getTitle() << "," << book.getAuthor() << "," << book.getPrice() << "," << book.getBookId();

		const std::vector<Rating>& reviews = book.getReviews();
		for (int i = 0; i < reviews.size(); i++)
		{
			line << "," << reviews[i].getScore() << "," << reviews[i].getUserId() << "," << reviews[i].getComment();
		}
		return line.str();
	}
	Book deserializeBook(const std::string& line)
	{
		std::stringstream ss(line);
		std::string title, author, price, id;

		std::getline(ss, title, ',');
		std::getline(ss, author, ',');
		std::getline(ss, price, ',');
		std::getline(ss, id, ',');

		Book book(title, author, std::stod(price), std::stoi(id));

		std::string score, userId, comment;
		while (std::getline(ss, score, ','))
		{
			std::getline(ss, userId, ',');
			std::getline(ss, comment, ',');
			book.addReview(Rating(std::stoi(score), comment, std::stoi(userId)));
		}
		return book;
	}
public:
	void addBook(const Book& book) override
	{
		std::ofstream fs(bookFile, std::ios::app);
		fs << serializeBook(book) << "\n";
		fs.close();
	}
	bool removeByTitle(const std::string& title) override
	{
		if (!findBookByTitle(title)) return false;

		std::ifstream in(bookFile);
		std::stringstream ss;
		ss << in.rdbuf();
		in.close();

		std::string data = "\n" + ss.str();

		size_t start = data.find("\n" + title + ",");
		if (start == std::string::npos) return false;
		size_t end = data.find('\n', start + 1);

		data.erase(start, end - start);
		data.erase(0, 1);

		std::ofstream("books.csv") << data;
		return true;
	}
	Book* findBookByTitle(const std::string& title) override
	{
		std::ifstream fs(bookFile);
		std::string line;

		while (std::getline(fs, line))
		{
			Book book = deserializeBook(line);
			if (book.getTitle() == title)
			{
				fs.close();
				return new Book(book.getTitle(), book.getTitle(), book.getPrice(), book.getBookId());
			}
			fs.close();
			return nullptr;
		}
	}
	Book* findBookById(int id) override
	{
		std::ifstream fs(bookFile);
		std::string line;

		while (std::getline(fs, line))
		{
			Book book = deserializeBook(line);
			if (book.getBookId() == id)
			{
				fs.close();
				return new Book(book.getTitle(), book.getTitle(), book.getPrice(), book.getBookId());
			}
			fs.close();
			return nullptr;
		}
	}
	bool updateBook(const std::string& title, const Book& newBook) override
	{
		if (!removeByTitle(title)) return false;
		addBook(newBook);
		return true;
	}
	bool rateBook(const std::string& title, const Rating& rating) override
	{
		Book* book = findBookByTitle(title);
		if (!book) return false;

		book->addReview(rating);
		removeByTitle(title);
		addBook(*book);
		return true;
	}
};