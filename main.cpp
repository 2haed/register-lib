#include <iostream>
#include "Users.h"
#include <vector>
#include <string>
#include <fstream>
#include <map>

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
//    if (!fout.is_open()) { // Обработку ошибки лучше перенести в самое начало инициализации ofstream. Так ты избежишь лишних операций. См ссылку 1
//        std::cout << "Ошибка открытия файла!" << std::endl;
//    } else {
//        for (auto now: Users) {
//            fout << "Username: " << now.get_username() << std::endl << "Password: " << now.get_password() << std::endl
//                 << std::endl;
//        }
//    }
//    fout.close();
    std::string path = "Database.txt";
    std::vector<User> users;
    for (int i = 0; i < 1; ++i) {
        users.emplace_back(User::create_user());
    }
    std::ofstream fout;
    fout.open(path);
    if (!fout.is_open()) { // Обработку ошибки лучше перенести в самое начало инициализации ofstream. Так ты избежишь лишних операций. См ссылку 1
        std::cout << "Ошибка открытия файла!" << std::endl;
    } else {
        for (auto now: users) {
            fout << "Username: " << now.get_username() << "\nPassword: " << now.get_password() << "\n\n";
        }
    }
    fout.close();

    std::cout << "Program exited successfuly\n";
    return 0;

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
}