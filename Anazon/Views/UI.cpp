#include <iostream>
#include <string>
#include "UI.h"
#include "../Models/Customer.h"
#include "../Models/Seller.h"

using namespace std;

void bookViewer(BookManager& bookManager)
{
	while (true)
	{
		cout << "1. View Book Details" << endl;
		cout << "2. View Book Reviews" << endl;
		cout << "3. View Book Ratings" << endl;
		cout << "4. Buy Book" << endl;
		cout << "5. Add a Review" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your option: ";

		int option;
		cin >> option;

		if (option == 1)
		{
			cout << "Viewing Book Details..." << endl;
		}
		else if (option == 2)
		{
			cout << "Viewing Book Reviews..." << endl;
		}
		else if (option == 3)
		{
			cout << "Viewing Book Ratings..." << endl;
		}
		else if (option == 4)
		{
			cout << "Buying Book..." << endl;
		}
		else if (option == 5)
		{
			cout << "Adding a Review..." << endl;
		}
		else if (option == 6)
		{
			cout << "Exiting Book Viewer..." << endl;
			return;
		}
		else
		{
			cout << "Invalid option. Please try again." << endl;
		}
	}
}

void shopPlatform(BookManager& bookManager, User* user)
{
	while (true)
	{
		cout << "Welcome to the Shop Platform!" << endl;
		cout << "1. Add Book tp your Shop" << endl;
		cout << "2. Remove Book from your Shop" << endl;
		cout << "3. Update Book from your Shop" << endl;
		cout << "4. View Orders" << endl;
		cout << "5. Exit" << endl;

		cout << "Enter your option: ";
		int option;
		cin >> option;

		if (option == 1)
		{
			cout << "Adding Book to your Shop..." << endl;
		}
		else if (option == 2)
		{
			cout << "Removing Book from your Shop..." << endl;
		}
		else if (option == 3)
		{
			cout << "Updating Book from your Shop..." << endl;
		}
		else if (option == 4)
		{
			cout << "Viewing Orders..." << endl;
		}
		else if (option == 5)
		{
			cout << "Exiting Shop Platform..." << endl;
			return;
		}
		else
		{
			cout << "Invalid option. Please try again." << endl;
		}
	}
}

void customerPlatform(BookManager& bookManager, User* user)
{
	while (true)
	{
		cout << "Welcome to the Customer Platform!" << endl;
		cout << "1. Search for a Book" << endl;
		cout << "2. Exit" << endl;
		cout << "Enter your option: ";
		int option;
		cin >> option;

		if (option == 1)
		{
			cout << "Enter Book Name: ";
			string bookName;
			getline(cin >> ws, bookName);

			//Book b;
			//if(b.bookExists(bookName)) 
			// {
			//	   bookViewer(bookName);
			// }
			// else
			// {
			//	   cout << "Book not found. Please try again." << endl;
			//	   customerPlatform();
			// }

		}
		else if (option == 2)
		{
			cout << "Exiting Customer Platform, Goodbye!" << endl;
			return;
		}
		else
		{
			cout << "Invalid option. Please try again." << endl;

		}
	}
}

void customerRegisterPanel(UserManager& userManager, BookManager& bookManager)
{
	int customerId = 1; // This should be generated or retrieved from a database in a real application
	string username, password, email;
	cout << "Please enter your desired username: ";
	cin >> username;
	cout << "Please enter your desired password: ";
	cin >> password;
	cout << "Please enter your email: ";
	cin >> email;

	User* newUser = new Customer(username, email, password, customerId);
	bool ok = userManager.Register(newUser);
	if (ok)
	{
		cout << "Registration successful! Redirecting to Customer Platform" << endl;
		customerPlatform(bookManager, newUser);
	}
	else
	{
		cout << "Registration failed. Email already exists. Please try again." << endl;
	}
}

void sellerRegisterPanel(UserManager& userManager, BookManager& bookManager)
{
	string shopName, password, email, address;
	cout << "Please enter your Shop Name: ";
	getline(cin >> ws, shopName);
	cout << "Please enter your desired password: ";
	cin >> password;
	cout << "Please enter your email: ";
	cin >> email;
	cout << "Please enter your Street Address: ";
	getline(cin >> ws, address);
	int sellerId = 1; // This should be generated or retrieved from a database in a real application

	User* newUser = new Seller(shopName, email, password, address, sellerId);
	bool ok = userManager.Register(newUser);
	if (ok)
	{
		cout << "Registration successful! Redirecting to Shop Platform" << endl;
		shopPlatform(bookManager, newUser);
	}
	else
	{
		cout << "Registration failed. Email already exists. Please try again." << endl;
	}
}

User* loginPanel(UserManager& userManager)
{
	string email, password;
	cout << "Please enter your email: ";
	cin >> email;
	cout << "Please enter your password: ";
	cin >> password;

	User* user = userManager.Login(email, password);
	if (user == nullptr)
	{
		cout << "Login Unsuccessful. Please try again." << endl;
		return nullptr;
	}
	return user;
}

void showMenu(UserManager& userManager, BookManager& bookManager)
{
	while (true)
	{
		int option;
		cout << "Welcome to Anazon!" << endl;
		cout << "1. I am a Customer" << endl;
		cout << "2. I am a Seller" << endl;
		cout << "3. Exit" << endl;
		cout << "Enter your option: ";
		cin >> option;

		if (option == 1)
		{
			cout << "Hello dear Customer!" << endl;
			cout << "Please Log in or Register to continue." << endl;
			cout << "1. Log in" << endl;
			cout << "2. Register" << endl;
			cout << "Enter your option: ";
			cin >> option;

			if (option == 1)
			{
				User* user = loginPanel(userManager);
				if (user != nullptr)
				{
					customerPlatform(bookManager, user);
				}
				else
				{
					cout << "Login Unsuccessful. Redirecting to Welcome Screen." << endl;
					continue;
				}
			}
			if (option == 2)
			{
				customerRegisterPanel(userManager, bookManager);
			}
		}
		else if (option == 2)
		{
			cout << "You selected Seller/Shop." << endl;
			cout << "Please Log in or Register to continue." << endl;
			cout << "1. Log in" << endl;
			cout << "2. Register" << endl;
			cout << "Enter your option: ";
			cin >> option;

			if (option == 1)
			{
				User* user = loginPanel(userManager);
				if (user != nullptr)
				{
					shopPlatform(bookManager, user);
				}
				else
				{
					cout << "Login Unsuccessful. Redirecting to Welcome Screen." << endl;
					continue;
				}
			}
			if (option == 2)
			{
				sellerRegisterPanel(userManager, bookManager);
			}
		}
		else if (option == 3)
		{
			cout << "Exiting Anazon. Goodbye!" << endl;
			return;
		}
		else
		{
			cout << "Invalid option. Please try again." << endl;
		}
	}
}