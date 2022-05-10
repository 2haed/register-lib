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


void Database::log_in(const std::string &username, const std::string &password) {
    std::string path = "Database.txt";
    std::ifstream fin (path);
    if (!fin.is_open()) {
        std::cout << "Ошибка открытия файла!\n";
    } else {
        std::string str;
        std::string str2;
        while (std::getline(fin, str)) {
            if (str.empty()) {
                continue;
            }
            if (str == username) {
                str2 = str;
                continue;
            }
            if (str == password and str2 == username) {
                std::cout << "Successfully logged in\n" << "Welcome, " << username << "\n";
                break;
            }
        }if (str2.empty()) {std::cout << "Incorrect username or password\n";}
    }
    fin.close();
}


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
    int n;
    n = vec.size();
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
        if (vec.size() < n) {
            std::cout << "User was deleted Successfully\n";
        }
    fout.close();
}

void Database::clear_database(const std::string &username, const std::string &password) {
    std::string path = "Database.txt";
    std::vector<std::string> vec;
    std::ofstream fout(path);
    if (username == "admin" and password == "admin") {
        if (!fout.is_open()) {
            std::cout << "Ошибка открытия файла!\n";
        }
        else {
            for (auto now : vec) {}
        }
        std::cout << '\n';
        fout.close();
    }
    else {
        std::cout << "Incorrect username or password\n";
    }
}