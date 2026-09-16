#include <iostream>

using namespace std;

void welcome()
{
	int option;
	cout << "Welcome to Anazon!" << endl;
	cout << "Pick an option:" << endl;
	cout << "1. Customer" << endl;
	cout << "2. Seller/Shop" << endl;
	cout << "3. Exit" << endl;
	cin >> option;
}


int main()
{
	welcome();
	return 0;
}