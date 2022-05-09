#include "Database.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <utility>
#include <memory>

void Database::print_info(const std::string& username, const std::string& password) {
    std::cout << "Username: " << username;
    std::cout << "Password: " << password;
}


void Database::print_info_safety(const std::string& username) {
    std::vector <std::string> s;

    s.reserve(_password.size());
for (int i = 0; i < _password.size(); ++i) {
        s.emplace_back("*");
    }

    std::cout << "Username: " << username;
    for (auto&& now : s) {
        std::cout << now;
    }
    std::cout << "\n";
}


std::string Database::find_user(const std::string &username) {
    std::string path = "Database.txt";
    std::ifstream fin(path);
    if (!fin.is_open()) {
        std::cout << "Ошибка открытия файла!\n";
    } else {
        const auto user_ptr = std::make_unique<Database>();
        Database& db = *user_ptr;
        std::string str;
        std::string str2;
        std::string str3;
        while (std::getline(fin, str)) {
            if (str.empty()) {
                continue;
            }
            if (str == username) {
                str2 = str;
                continue;
            }
            if (!str2.empty()) {
                str3.append(str2);
                str3.push_back(' ');
                str3.append(str);
                return str3;
            }
        };
    }
    fin.close();
    return "Not found";
}


//
//void Database::log_in(const std::string &username, const std::string &password) {
//    std::string path = "Database.txt";
//    std::ifstream fin (path);
//    if (!fin.is_open()) { // Обработку ошибки лучше перенести в самое начало инициализации ofstream. Так ты избежишь лишних операций. См ссылку 1
//        std::cout << "Ошибка открытия файла!\n";
//    } else {
//        for () {
//            fin << "Username: " << now.get_username() << "\nPassword: " << now.get_password() << "\n";
//        }
//    }
//    fin.close();
//
//}
//
//void Database::delete_user(const std::string &username, const std::string &password) {
//
//}
