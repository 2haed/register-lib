#include <iostream>
#include <string>
#include <vector>
#include "Users.h"


User::User(const std::string& username, const std::string& password) {
    _username = username;
    _password = password;
//    std::cout << "User created" << std::endl;
}

User::~User() {
//    std::cout << "User deleted" << std::endl;
}

User User::create_random_user() {
    std::string username;
    std::string password;
    for (int i = 0; i < rand() % 16 + 1; ++i) {
        username.push_back(rand()%26+0x61);
    }
    for (int i = 0; i < rand() % 16 + 1; ++i) {
        password.push_back(rand()%26+0x61);
    }
    return {username, password};
}

User User::create_user() {
    std::string username;
    std::string password;
    std::cin >> username;
    std::cin >> password;
    return {username, password};
}




