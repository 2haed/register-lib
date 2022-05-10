#include <iostream>
#include "Users.h"
#include "Database.h"
#include <vector>
#include <string>




enum funcitons {create_user = 1, login, create_random_user, find_user, delete_user, clear_database};

int main() {
    srand(time(NULL));
    while (true) {
        int value;
        std::cout <<  create_user << ". Register\n";
        std::cout << login << ". Login into user\n";
        std::cout << create_random_user << ". Create random user\n";
        std::cout << find_user << ". Find existed user in Database\n";
        std::cout << delete_user << ". Delete user from Database\n";
        std::cout << clear_database << ". Clear database\n";

        std::cout << "Enter value or -1 to exit:\n";
        std::cin >> value;
        if (value == -1) { std::cout << "Exit\n"; break; }
        else if (value == 1) {

            std::cout << "Enter login and password:\n";
            std::string path = "Database.txt";//      CREATE_USER
            std::vector<User> created_users;
            created_users.reserve(1);
            for (int i = 0; i < 1; ++i) {
                created_users.emplace_back(User::create_user());
            }
            std::ofstream fout(path, std::ios::app);
            if (!fout.is_open()) {
                std::cout << "Ошибка открытия файла!" << std::endl;
            } else {
                for (auto now: created_users) {
                    fout << now.get_username() << "\n" << now.get_password() << "\n";
                }
            }
            fout << "\n";
            fout.close();
            std::cout << "\nUser was created Successfully\n\n";


        }else if (value == 2) {
                std::string u;//              LOGIN
                std::cout << "Enter login: \n";
                std::cin >> u;
                std::cout << "Enter password: \n";
                std::string p;
                std::cin >> p;
                Database::log_in(u, p);
                std::cout << "\n";
        } else if (value == 3) {

            std::cout <<"Enter quantity:\n";
            int n;//                      CREATE_RANDOM_USER
            std::cin >> n;
            std::string path = "Database.txt";
            std::ofstream fout;
            fout.open(path, std::ios::app);
            if (!fout.is_open()) {
                std::cout << "Ошибка открытия файла!\n";
            }
            std::vector<User> Users;
            Users.reserve(n);
            for (int i = 0; i < n; ++i) {
                Users.emplace_back(User::create_random_user());
            }
            if (!fout.is_open()) {
                std::cout << "Ошибка открытия файла!" << std::endl;
            } else {
                for (auto now: Users) {
                    fout << now.get_username() << std::endl << now.get_password() << std::endl
                         << std::endl;
                }
            }
            fout.close();
            std::cout << n << " Users were created Successfully\n\n";


        } else if (value == 4) {
            std::string u;
            std::string p;
            std::cout << "Enter username:\n";
            std::cin >> u;
            std::cout << "Enter password:\n";
            std::cin >> p;
            if (u == "admin" and p == "admin") {
                std::cout << "Enter login " << std::endl;//       FIND_USER
                std::string u1;
                std::cin >> u1;
                auto found = Database::find_user(u1);
                std::cout << "User found:\n" << "Username: " << found.get_username() << "\nPassword: "
                          << found.get_password() << "\n\n";
            }
            else {
                std::cout << "Not enough permission\n\n";
            }

        } else if (value == 5) {
            std::string u;
            std::string p;
            std::cout << "Enter username:\n";
            std::cin >> u;
            std::cout << "Enter password:\n";
            std::cin >> p;
            if (u == "admin" and p == "admin") {
                std::string u1;
                std::string p1;
                std::cout << "Enter username and password\n";
                std::cin >> u1;
                std::cin >> p1;
                Database::delete_user(u1, p1);
                std::cout << "\n";
            }
        } else if (value == 6) {
            std::string u;//              CLEAR_DATABASE
            std::cout << "Enter login: \n";
            std::cin >> u;
            std::cout << "Enter password: \n";
            std::string p;
            std::cin >> p;
            Database::clear_database(u,p);
            std::cout << "\n";
        }
        else {
            std::cout << "Incorrect value!";
            break;
        }
    }
}