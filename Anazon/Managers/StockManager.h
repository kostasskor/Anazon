#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Models/Book_Stock.h"

class StockManager
{
private:
	std::vector<Book_Stock> stocks;
public:
	bool buyBook(int seller_id, int book_id, int quantity)
	{
		if (quantity < 1) return false;

		for (int i = 0; i < stocks.size(); i++)
		{
			if (stocks[i].getSellerId() == seller_id && stocks[i].getBookId() == book_id)
			{
				if (stocks[i].getStock() < quantity) return false;
				stocks[i] = Book_Stock(seller_id, book_id, stocks[i].getStock() - quantity);
				return true;
			}
		}
		return false;
	}
	std::vector<Book_Stock> stocksFor(int book_id) const
	{
		std::vector<Book_Stock> found;
		for (int i = 0; i < stocks.size(); i++)
		{
			if (stocks[i].getBookId() == book_id)
				found.push_back(stocks[i]);
		}
		return found;
	}
	void addStock(int seller_id, int book_id, int quantity)
	{
		for (int i = 0; i < stocks.size(); i++)
		{
			if (stocks[i].getSellerId() == seller_id && stocks[i].getBookId() == book_id)
			{
				stocks[i] = Book_Stock(seller_id, book_id, stocks[i].getStock() + quantity);
				return;
			}
		}
		stocks.push_back(Book_Stock(seller_id, book_id, quantity));
	}
};