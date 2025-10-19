#include <iostream>
#include <string>
#include <map>

// A simple registation/login based on c++.

std::map<std::string, std::string> database;


bool login() {
    std::cout << "Enter login: ";
    std::string userLogin;
    std::cin >> userLogin;

    if (database.find(userLogin) != database.end()) {
        std::cout << "Enter password for " << userLogin << ": ";
        std::string password;
        std::cin >> password;

        if (database[userLogin] == password) {
            std::cout << "Hello " << userLogin << "!" << std::endl;
            return true;
        }
        else {
            std::cout << "Wrong password!" << std::endl;
            return false;
        }
    }
    else {
        std::cout << "User not found!" << std::endl;
        return false;
    }
}


void registration() {
    std::cout << "Enter new login: ";
    std::string userLogin;
    std::cin >> userLogin;

    if (database.find(userLogin) != database.end()) {
        std::cout << "This login is already taken!" << std::endl;
        return;
    }

    std::cout << "Enter new password: ";
    std::string password;
    std::cin >> password;

    database[userLogin] = password;
    std::cout << "You successfully registered in program!" << std::endl;
}

void mainMenu() {
    std::cout << "Welcome in plaza.com!" << std::endl;
    std::cout << "To continue sign up new account or sign in in existing account!" << std::endl;
    std::cout << "1 - log in account" << std::endl;
    std::cout << "2 - sign up new account" << std::endl;
    std::cout << "3 - exit" << std::endl;

    int variant;
    std::cin >> variant;

    switch (variant) {
    case 1:
        std::cout << "Login detected" << std::endl;
        login();
        break;
    case 2:
        std::cout << "Registration detected" << std::endl;
        registration();
        break;
    case 3:
        std::cout << "Goodbye!" << std::endl;
        return;
    default:
        std::cout << "Wrong command!" << std::endl;
        break;
    }

    mainMenu();
}


int main() {
    mainMenu();
    return 0;
}
