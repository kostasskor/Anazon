#include <iostream>
#include <string>
#include "Views/UI.h"
#include "Managers/UserManager.h"
#include "Managers/BookManager.h"
#include "Managers/StockManager.h"
#include "Repositories/CsvBookRepository.h"


using namespace std;

int main()
{
	CsvBookRepository bookRepo;
	Book book("harry potter", "Jk", 15.67, 01);
	//bookRepo.addBook(book);

	bookRepo.updateBook("harry potter", book);
	return 0;








	//StockManager sM;
	//UserManager uM;
	//BookManager bM(&bookRepo);

	//showMenu(uM, bM, sM);
	//return 0;
}