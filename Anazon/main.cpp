#include <iostream>
#include <string>
#include "Views/UI.h"
#include "Managers/UserManager.h"
#include "Managers/BookManager.h"
#include "Managers/StockManager.h"

using namespace std;

int main()
{
	StockManager sM;
	UserManager uM;
	BookManager bM;

	showMenu(uM, bM, sM);
	return 0;
}