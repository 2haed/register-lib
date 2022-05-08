#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

#pragma once

class User {
public:
    User() = default;
    User(const std::string& username, const std::string& password);
    ~User();
public:
    void print_info();
    static User create_random_user();
    static User create_user();
    void log_in(const std::string &username, const std::string &password);
    void delete_user(const std::string &username, const std::string &password);
    std::string get_username() {return _username;};
    std::string get_password() {return _password;};
private:
    std::string _username;

    std::string _password;
};