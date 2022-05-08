#include <iostream>
#include <string>
#include <vector>
#include "Users.h"
#include <fstream>



User::User(const std::string& username, const std::string& password) {
    _username = username;
    _password = password;
    std::cout << "User created" << std::endl;
}

User::~User() {
    std::cout << "User deleted" << std::endl;
}

void User::print_info() {

    std::vector <std::string> s;
    for (int i = 0; i < _password.size(); ++i) {
        s.emplace_back("*");
    }

    std::cout << "Username " << _username << std::endl << "Password ";
    for (auto&& now : s) {
        std::cout << now;
    }
    std::cout << std::endl;
}


User User::create_random_user() {;
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
//void User::save_random_user() {
//    int n;
//    std::cin >> n;
//    std::string path = "Database.txt";
//    std::ofstream fout;
//    fout.open(path);
//    if (!fout.is_open()) {
//        std::cout << "Ошибка открытия файла!\n";
//    }
//    std::vector <User> Users;
//    Users.reserve(n);
//    for (int i = 0; i < n; ++i) {
//        Users.emplace_back(User::create_random_user());
//    }
//    if (!fout.is_open()) { // Обработку ошибки лучше перенести в самое начало инициализации ofstream. Так ты избежишь лишних операций. См ссылку 1
//        std::cout << "Ошибка открытия файла!" << std::endl;
//    }
//    else {
//        for (auto now: Users) {
//            fout << "Username: " << now.get_username() << std::endl << "Password: " << now.get_password() << std::endl << std::endl;
//        }
//    }
//    fout.close();


