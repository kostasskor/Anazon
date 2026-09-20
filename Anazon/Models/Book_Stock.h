#pragma once
class Book_Stock
{
private:
	int sellerId;
	int bookId;
	int stock;
public:
	Book_Stock(int sellerId, int bookId, int stock)
	{
		this->sellerId = sellerId;
		this->bookId = bookId;
		this->stock = stock;
	}	
	int getSellerId() const
	{
		return sellerId;
	}
	int getBookId() const
	{
		return bookId;
	}
	int getStock() const
	{
		return stock;
	}
};