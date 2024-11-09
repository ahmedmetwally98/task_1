#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <limits>

extern int getIntInput(void);

class user
{
public:
    user() {}
    user(unsigned short age_, std::string name_);

    void user_setAge(const unsigned short age_);
    void user_setName(const std::string name_);
    unsigned short user_getAge(void) const;
    std::string_view user_getName(void) const;

    ~user() {};

private:
    unsigned short userAge;
    std::string userName;
};

class userManager
{
public:
    userManager() {}

    void userManager_addUser(void);
    void userManager_fetchUser(int id_);

    ~userManager() {}

private:
    std::vector<user> users;
};