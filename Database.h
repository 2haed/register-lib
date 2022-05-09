#include <iostream>
#include <string>
#include <cstdlib>
#include "Users.h"
#include <fstream>
#include <vector>
#include <memory>

#pragma once

class Database {
public:
    Database() = default;
    ~Database() = default;
public:
    static void print_info(const std::string& username, const std::string& password);
    void print_info_safety (const std::string& username);
    static User find_user(const std::string &username);
    void log_in(const std::string &username, const std::string &password);
    static void delete_user(const std::string &username, const std::string &password);
    std::string get_username() {return _username;};
    std::string get_password() {return _password;};
private:
    std::string _username;
    std::string _password;


};