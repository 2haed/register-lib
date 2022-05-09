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


User Database::find_user(const std::string &username) {
    std::string path = "Database.txt";
    std::ifstream fin(path);
    if (!fin.is_open()) {
        std::cout << "Ошибка открытия файла!\n";
    } else {
        std::string str;
        std::string str2;
        std::string str3;
        while (std::getline(fin, str)) {
            if (str.empty()) {
                continue;
            }
            if (str == "Username: " or str == "Password: "){
                continue;
            }
            if (str == username) {
                str2 = str;
                continue;
            }
            if (!str2.empty()) {
                return {str2, str};
            }
        };
    }
    fin.close();
    return {username, "not found"};
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
void Database::delete_user(const std::string &username, const std::string &password) {
    std::string path = "Database.txt";
    std::vector<std::string> vec;
    std::ifstream fin(path);
    if (!fin.is_open()) {
        std::cout << "Ошибка открытия файла!\n";
    } else {
        std::string str;
        std::string str2;
        while (std::getline(fin, str)) {
            if (str.empty()) {
                continue;
            }
            vec.emplace_back(str);
        }
    }
    fin.close();
    std::ofstream fout(path);
        if (!fout.is_open()) {
            std::cout << "Ошибка открытия файла!\n";
        } else {
            for (const auto& now : vec){
                    if (now == username) {
                        vec.erase(std::remove(vec.begin(), vec.end(), now), vec.end());
                    }
                    if( now == password) {
                        vec.erase(std::remove(vec.begin(), vec.end(), now), vec.end());
                    }
                }
            }
        for (int i = 0; i < vec.size(); i++){
            fout << vec[i] << "\n";
            if ((i+1)%2 == 0) {
                fout << "\n";
            }
        }
    fout.close();
}

