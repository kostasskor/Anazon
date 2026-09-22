#pragma once
#include "../Models/User.h"
#include "../Managers/UserManager.h"
#include "../Managers/BookManager.h"
#include "../Managers/StockManager.h"

static void bookViewer(Book* book, StockManager& stockManager, UserManager& userManager, User* user);
static void customerPlatform(BookManager& bookManager, StockManager& stockManager, UserManager& userManager, User* user);
static void shopPlatform(User* user);
static User* loginPanel(UserManager& userManager);
static User* customerRegisterPanel(UserManager& userManager);
static User* sellerRegisterPanel(UserManager& userManager);
static void authFlow(UserManager& userManager, BookManager& bookManager, StockManager& stockManager, bool isCustomer);
void showMenu(UserManager& userManager, BookManager& bookManager, StockManager& stockManager);