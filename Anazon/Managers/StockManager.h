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
	void buyBook(int seller_id, int book_id, int quantity)
	{
		for (int i = 0; i < stocks.size(); i++)
		{
			if (stocks[i].getSellerId() == seller_id && stocks[i].getBookId() == book_id)
			{
				if (stocks[i].getStock() >= quantity)
				{
					stocks[i] = Book_Stock(seller_id, book_id, stocks[i].getStock() - quantity);
					std::cout << "Purchase successful." << std::endl;
					return;
				}
				else
				{
					std::cout << "Not enough stock available." << std::endl;
					return;
				}
			}
		}
		std::cout << "Book not found in stock." << std::endl;
	}
	void addStock(int seller_id, int book_id, int quantity)
	{
		for (int i = 0; i < stocks.size(); i++)
		{
			if (stocks[i].getSellerId() == seller_id && stocks[i].getBookId() == book_id)
			{
				stocks[i] = Book_Stock(seller_id, book_id, stocks[i].getStock() + quantity);
				std::cout << "Stock updated." << std::endl;
				return;
			}
		}
		stocks.push_back(Book_Stock(seller_id, book_id, quantity));
		std::cout << "New stock added." << std::endl;
	}
};