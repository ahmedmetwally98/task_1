#include "user.hpp"

user::user(unsigned short age_, std::string name_) : userAge(age_), userName(name_)
{
}

void user::user_setAge(const unsigned short age_)
{
    this->userAge = age_;
}
void user::user_setName(const std::string name_)
{
    this->userName = name_;
}

unsigned short user::user_getAge(void) const
{
    return this->userAge;
}

std::string_view user::user_getName(void) const
{
    return std::string_view(this->userName);
}

/***************** userManager Class definition *******************/
void userManager::userManager_addUser(void)
{
    std::string l_name{""};
    int l_age{-1};
    std::cout << "Name: ";
    std::cin >> l_name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Age: ";
    l_age = getIntInput();
    if (l_age < 0)
    {
        std::cout << "Invalid user age!...Try again\n";
    }
    else
    {
        user newUser(static_cast<unsigned short>(l_age), l_name);
        users.push_back(newUser);
        std::cout << "\nUser record added successfully\n";
    }
}

void userManager::userManager_fetchUser(int id_)
{
    try
    {
        user fetchedUser = this->users.at(id_);
        std::cout << "User Name: " << fetchedUser.user_getName() << std::endl;
        std::cout << "User Age: " << fetchedUser.user_getAge() << std::endl;
    }
    catch (std::out_of_range &e)
    {
        std::cout << "\nAttempt to fetch invalid user ID\n";
    }
}
/************** Helper Functions **************/
int getIntInput(void)
{
    int inputInt{-1};
    std::cin >> inputInt;
    if (!std::cin.good())
    {
        // <! clear cin errors flag >
        std::cin.clear();
        // <! Clearing input buffer to ignore the newline character >
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return -1;
    }

    return inputInt;
}
