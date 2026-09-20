#pragma once
class Book_Stock
{
private:
	int seller_id;
	int book_id;
	int stock;
public:
	Book_Stock(int seller_id, int book_id, int stock)
	{
		this->seller_id = seller_id;
		this->book_id = book_id;
		this->stock = stock;
	}
	int getSellerId()
	{
		return seller_id;
	}
	int getBookId()
	{
		return book_id;
	}
	int getStock()
	{
		return stock;
	}
};