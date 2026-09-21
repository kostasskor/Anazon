#pragma once
#include "../Models/User.h"
#include "../Managers/UserManager.h"
#include "../Managers/BookManager.h"

void showMenu(UserManager& userManager, BookManager& bookManager);
void customerPlatform(BookManager& bookManager, User* user);
void shopPlatform(BookManager& bookManager, User* user);
void bookViewer(BookManager& bookManager);
void customerRegisterPanel(UserManager& userManager, BookManager& bookManager);
void sellerRegisterPanel(UserManager& userManager, BookManager& bookManager);
User* loginPanel(UserManager& userManager);