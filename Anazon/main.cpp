#include <iostream>
#include <string>

using namespace std;

void welcome();
void customerPlatform();
void shopPlatform();
void bookViewer();

void bookViewer()
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

void shopPlatform()
{
	while(true)
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

		if(option == 1)
		{
			cout << "Adding Book to your Shop..." << endl;
		}
		else if(option == 2)
		{
			cout << "Removing Book from your Shop..." << endl;
		}
		else if(option == 3)
		{
			cout << "Updating Book from your Shop..." << endl;
		}
		else if(option == 4)
		{
			cout << "Viewing Orders..." << endl;
		}
		else if(option == 5)
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

void customerPlatform()
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
			cin >> bookName;

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

void customerRegister()
{
	string username, password, email, address;
	cout << "Please enter your desired username: ";
	cin >> username;
	cout << "Please enter your desired password: ";
	cin >> password;
	cout << "Please enter your email: ";
	cin >> email;
	cout << "Please enter your Street Address: ";
	cin >> address;

	//Customer c;
	//c.register(username, password, email, address);
	cout << "Registration successful! Redirecting to Customer Platform" << endl;
	customerPlatform();
}

bool customerLogin()
{
	string username, password;
	cout << "Please enter your username: ";
	cin >> username;
	cout << "Please enter your password: ";
	cin >> password;

	//Customer c;
	//int res = c.login(username, password);
	int res = 0;
	if (res == 0)
	{
		cout << "Login Unsuccessful. Please try again." << endl;
		return false;
	}
	return true;

}

void sellerRegister()
{
	string shopName, password, email, address;
	cout << "Please enter your Shop Name: ";
	cin >> shopName;
	cout << "Please enter your desired password: ";
	cin >> password;
	cout << "Please enter your email: ";
	cin >> email;
	cout << "Please enter your Street Address: ";
	cin >> address;

	//Shop s;
	//s.register(shopName, password, email, address);
	cout << "Registration successful! Redirecting to Shop Platform" << endl;
	shopPlatform();
}

bool sellerLogin()
{
	string username, password;
	cout << "Please enter your username: ";
	cin >> username;
	cout << "Please enter your password: ";
	cin >> password;

	//Shop s;
	//s.login(username, password);
	//int res = s.login(username, password);
	int res = 0;
	if (res == 0)
	{
		cout << "Login Unsuccessful. Please try again." << endl;
		return false;
	}
	return true;
}

void welcome()
{
	while (true)
	{
		int option;
		cout << "Welcome to Anazon!" << endl;
		cout << "Pick an option:" << endl;
		cout << "1. Customer" << endl;
		cout << "2. Seller/Shop" << endl;
		cout << "3. Exit" << endl;
		cout << "Enter your option: ";
		cin >> option;

		if (option == 1)
		{
			cout << "You selected Customer." << endl;
			cout << "Please Log in or Register to continue." << endl;
			cout << "1. Log in" << endl;
			cout << "2. Register" << endl;
			cout << "Enter your option: ";
			cin >> option;

			if (option == 1)
			{
				if (customerLogin())
				{
					customerPlatform();
				}
				else
				{
					cout << "Login Unsuccessful. Redirecting to Welcome Screen." << endl;
					continue;
				}
			}
			if (option == 2)
			{
				customerRegister();
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
				if (sellerLogin())
				{
					shopPlatform();
				}
				else
				{
					cout << "Login Unsuccessful. Redirecting to Welcome Screen." << endl;
					continue;
				}
			}
			if (option == 2)
			{
				sellerRegister();
			}
		}
		else if (option == 3)
		{
			cout << "Exiting Anazon. Goodbye!" << endl;
			exit(0);
		}
		else
		{
			cout << "Invalid option. Please try again." << endl;
		}
	}
}

int main()
{
	welcome();
	return 0;
}