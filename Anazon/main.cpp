#include <iostream>
#include <string>
#include "Views/UI.h"
#include "Managers/UserManager.h"
#include "Managers/BookManager.h"

using namespace std;

int main()
{
	UserManager uM;
	BookManager bM;

	showMenu(uM, bM);
	return 0;
}