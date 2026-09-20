#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Models/Book_Stock.h"

using namespace std;

class StockManager
{
private:
	vector<Book_Stock> stocks;
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
					cout << "Purchase successful." << endl;
					return;
				}
				else
				{
					cout << "Not enough stock available." << endl;
					return;
				}
			}
		}
		cout << "Book not found in stock." << endl;
	}
};