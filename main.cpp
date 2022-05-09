#include <iostream>
#include "Users.h"
#include "Database.h"
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <cstring>
int main() {
    srand(time(NULL));


//    int n;
//    std::cin >> n;
//    std::string path = "Database.txt";
//    std::ofstream fout;
//    fout.open(path);
//    if (!fout.is_open()) { // ССЫЛКА 1
//        std::cout << "Ошибка открытия файла!\n";
//    }
//    std::vector<User> Users;
//    Users.reserve(n);
//    for (int i = 0; i < n; ++i) {
//        Users.emplace_back(User::create_random_user());
//    }
//    if (!fout.is_open()) {
//        std::cout << "Ошибка открытия файла!" << std::endl;
//    } else {
//        for (auto now: Users) {
//            fout <<  now.get_username() << std::endl << now.get_password() << std::endl
//                 << std::endl;
//        }
//    }
//    fout.close();






//    std::vector<User> users;
//    while (true) {
//        int value;
//        std::cout << "Enter value or -1 to exit: ";
//        std::cin >> value;
//        if (value == -1) { break; }
//        else if (value == 1) {
//            users.emplace_back(User::create_user());
//            std::cout << users.back().get_username() << " created\n";
//        } else if (value == 2) {
//            users.emplace_back(User::create_random_user());
//            std::cout << users.back().get_username() << " created\n";
//        } else {
//            std::cout << "Incorrect value: " << value << "\n";
//        }
//    }
//
//    std::cout << "Enter login " << std::endl;
//    std::string u;
//    std::cin >> u;
//    auto found = Database::find_user(u);
//    std::cout << "User found:\n" << "Username: " << found.get_username() << "\nPassword: " << found.get_password() << "\n";

//    std::string path = "Database.txt";
//    std::vector<User> users;
//    for (int i = 0; i < 1; ++i) {
//        users.emplace_back(User::create_user());
//    }
//    std::ofstream fout(path, std::ios::app);
//
//    if (!fout.is_open()) {
//        std::cout << "Ошибка открытия файла!" << std::endl;
//    } else {
//        for (auto now: users) {
//            fout  << now.get_username() << "\n" << now.get_password() << "\n";
//        }
//    }
//    fout << "\n";
//    fout.close();
//
//    std::cout << "Program exited successfuly\n";
//    return 0;


//std::string u;
//    std::cout << "Enter login: \n";
//    std::cin >> u;
//    std::cout << "Enter password: \n";
//    std::string p;
//    std::cin >> p;
//Database::delete_user(u, p);

    std::string u;
    std::cout << "Enter login: \n";
    std::cin >> u;
    std::cout << "Enter password: \n";
    std::string p;
    std::cin >> p;
    Database::log_in(u, p);
}