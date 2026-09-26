#include "UI.h"
#include "../Models/Customer.h"
#include "../Models/Seller.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static void bookViewer(Book* book, StockManager& stockManager, UserManager& userManager, User* user)
{
	while (true)
	{
		cout << book->getTitle() << endl;
		cout << "1. View Details" << endl;
		cout << "2. Buy Book" << endl;
		cout << "3. Write a Review" << endl;
		cout << "4. Back" << endl;
		cout << "Enter your option: ";

		int option;
		cin >> option;

		if (option == 1)
		{
			cout << "Title:  " << book->getTitle() << endl;
			cout << "Author: " << book->getAuthor() << endl;
			cout << "Price:  " << book->getPrice() << endl;

			if (book->getReviewCount() == 0)
			{
				cout << "Rating: no ratings yet" << endl;
			}
			else
			{
				cout << "Rating: " << book->getAverageRating() << " from " << book->getReviewCount() << " review(s)" << endl;
			}
		}
		else if (option == 2)
		{
			vector<Book_Stock> stocks = stockManager.stocksFor(book->getBookId());

			if (stocks.empty())
			{
				cout << "No seller has this book in stock." << endl;
				continue;
			}

			cout << "Sellers with this book:" << endl;
			for (size_t i = 0; i < stocks.size(); i++)
			{
				Seller* seller = userManager.findSeller(stocks[i].getSellerId());

				cout << (i + 1) << ". ";
				if (seller == nullptr)
					cout << "Unknown shop";
				else
					cout << seller->getName() << " | " << seller->getAddress();

				cout << " | stock: " << stocks[i].getStock()
					<< " | price: " << book->getPrice() << endl;
			}

			cout << "Choose a seller: ";
			int pick;
			cin >> pick;

			if (pick < 1 || pick >(int)stocks.size())
			{
				cout << "That is not one of the sellers listed." << endl;
				continue;
			}

			cout << "How many copies? ";
			int quantity;
			cin >> quantity;

			if (stockManager.buyBook(stocks[pick - 1].getSellerId(), book->getBookId(), quantity))
				cout << "Bought " << quantity << " copy/copies for "
				<< book->totalPrice(quantity) << endl;
			else
				cout << "Could not buy that many from that seller." << endl;
		}
		else if (option == 3)
		{
			cout << "Your score (1-5): ";
			int score;
			cin >> score;

			if (!Rating::isValidScore(score))
			{
				cout << "The score has to be between 1 and 5." << endl;
			}
			else
			{
				cout << "Your comment: ";
				string comment;
				getline(cin >> ws, comment);

				book->addReview(Rating(score, comment, user->getId()));

				cout << "Thanks for your review!" << endl;
			}
		}
		else if (option == 4)
		{
			return;
		}
		else
		{
			cout << "Invalid option. Please try again." << endl;
		}
	}
}

static void customerPlatform(BookManager& bookManager, StockManager& stockManager, UserManager& userManager, User* user)
{
	while (true)
	{
		cout << "\n--- Customer: " << user->getName() << " ---\n";
		cout << "1. Search for a book\n";
		cout << "0. Log out\n";
		cout << "Enter your option: ";

		int option;
		cin >> option;

		if (option == 1)
		{
			cout << "Enter the book title: ";
			string title;
			getline(cin >> ws, title);

			Book* book = bookManager.findBook(title);
			if (book == nullptr)
				cout << "No book found with that title.\n";
			else
				bookViewer(book, stockManager, userManager, user);
		}
		else if (option == 0)
		{
			cout << "Logged out. Goodbye!\n";
			return;
		}
		else
		{
			cout << "Invalid option. Please try again.\n";
		}
	}
}

static void shopPlatform(User* user)
{
	while (true)
	{
		cout << "\n--- Shop: " << user->getName() << " ---\n";
		cout << "1. Add a book to your shop\n";
		cout << "2. Remove a book from your shop\n";
		cout << "3. Update a book in your shop\n";
		cout << "4. View orders\n";
		cout << "0. Log out\n";
		cout << "Enter your option: ";

		int option;
		cin >> option;

		if (option == 1)
		{
			cout << "Adding Book to your Shop...\n";       // TODO
		}
		else if (option == 2)
		{
			cout << "Removing Book from your Shop...\n";   // TODO
		}
		else if (option == 3)
		{
			cout << "Updating Book from your Shop...\n";   // TODO
		}
		else if (option == 4)
		{
			cout << "Viewing Orders...\n";                 // TODO
		}
		else if (option == 0)
		{
			cout << "Logged out. Goodbye!\n";
			return;
		}
		else
		{
			cout << "Invalid option. Please try again.\n";
		}
	}
}

static User* loginPanel(UserManager& userManager)
{
	string email, password;

	cout << "Enter your email: ";
	cin >> email;
	cout << "Enter your password: ";
	cin >> password;

	User* user = userManager.Login(email, password);
	if (user == nullptr)
	{
		cout << "Login unsuccessful. Please try again.\n";
		return nullptr;
	}

	cout << "Welcome back, " << user->getName() << "!\n";
	return user;
}

static User* customerRegisterPanel(UserManager& userManager)
{
	string username, password, email;

	cout << "Enter your desired username: ";
	cin >> username;
	cout << "Enter your desired password: ";
	cin >> password;
	cout << "Enter your email: ";
	cin >> email;

	User* user = new Customer(username, email, password);

	if (!userManager.Register(user))
	{
		cout << "Registration failed. That email already exists.\n";
		return nullptr;
	}

	cout << "Registration successful!\n";
	return user;
}

static User* sellerRegisterPanel(UserManager& userManager)
{
	string shopName, password, email, address;

	cout << "Enter your shop name: ";
	getline(cin >> ws, shopName);
	cout << "Enter your desired password: ";
	cin >> password;
	cout << "Enter your email: ";
	cin >> email;
	cout << "Enter your street address: ";
	getline(cin >> ws, address);

	User* user = new Seller(shopName, email, password, address);

	if (!userManager.Register(user))
	{
		cout << "Registration failed. That email already exists.\n";
		return nullptr;
	}

	cout << "Registration successful!\n";
	return user;
}

static void authFlow(UserManager& userManager, BookManager& bookManager, StockManager& stockManager, bool isCustomer)
{
	cout << "\n--- " << (isCustomer ? "Customer" : "Seller") << " ---\n";
	cout << "1. Log in\n";
	cout << "2. Register\n";
	cout << "0. Back\n";
	cout << "Enter your option: ";

	int option;
	cin >> option;
	User* user = nullptr;

	if (option == 1)
	{
		user = loginPanel(userManager);
	}
	else if (option == 2)
	{
		if (isCustomer)
			user = customerRegisterPanel(userManager);
		else
			user = sellerRegisterPanel(userManager);
	}
	else if (option == 0)
	{
		return;
	}
	else
	{
		cout << "Invalid option. Please try again.\n";
		return;
	}

	if (user == nullptr)
		return;

	if (isCustomer)
		customerPlatform(bookManager, stockManager, userManager, user);
	else
		shopPlatform(user);
}

void showMenu(UserManager& userManager, BookManager& bookManager, StockManager& stockManager)
{
	while (true)
	{
		cout << "\n--- Welcome to Anazon! ---\n";
		cout << "1. I am a Customer\n";
		cout << "2. I am a Seller\n";
		cout << "0. Exit\n";
		cout << "Enter your option: ";

		int option;
		cin >> option;

		if (option == 1)
		{
			authFlow(userManager, bookManager, stockManager, true);
		}
		else if (option == 2)
		{
			authFlow(userManager, bookManager, stockManager, false);
		}
		else if (option == 0)
		{
			cout << "Exiting Anazon. Goodbye!\n";
			return;
		}
		else
		{
			cout << "Invalid option. Please try again.\n";
		}
	}
}