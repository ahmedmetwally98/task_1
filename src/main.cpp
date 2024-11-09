#include "user.hpp"
#include <map>

/********************* Global Varialbles *********************/
const std::map<int, std::string> menu = {
    {1, "Add Record"},
    {2, "Fetch Record"},
    {3, "Quit"}};

/******************** Function Definition **********************/
void app_printMenu(void)
{
    std::cout << "\nPlease select an option:\n";
    for (auto mapIter : menu)
    {
        std::cout << mapIter.first
                  << ": "
                  << mapIter.second << std::endl;
    }
    std::cout << "\nEnter option: ";
}

/********************* App Class Definition *********************/
class App
{
public:
    App() {}

    void runApp(void)
    {
        while (true)
        {
            app_printMenu();
            int choice{-1};
            choice = getIntInput();

            // <! check choice >
            if ((choice >= 1 && choice <= 3))
            {

                if (choice == 3)
                {
                    std::cout << "Exiting gracefully...\n";
                    break;
                }

                switch (choice)
                {
                case 1:
                {
                    // <! add new user >
                    std::cout << "\nAdd user. Please enter user name and age:\n";
                    appUsers.userManager_addUser();
                    break;
                }
                case 2:
                {
                    // <! fetch existing user data >
                    std::cout << "\nPlease enter user ID:\nUser ID: ";
                    int id = getIntInput();
                    if (id < 0)
                    {
                        std::cout << "Invalid user ID!...try again\n";
                    }
                    else
                    {
                        appUsers.userManager_fetchUser(id);
                    }
                    break;
                }
                default:
                {
                    std::cout << "\nInvalid choise number...Try again\n";
                    break;
                }
                }
            }
            else
            {
                std::cout << "\nInvalid choice!.. Try again\n";
            }
        }
    }

    ~App() {}

private:
    userManager appUsers;
};

int main(void)
{
    void *rawMemory = ::operator new(sizeof(App));
    // Construct the object in the allocated memory
    App *task1App_ptr = new (rawMemory) App();

    task1App_ptr->runApp();

    ::operator delete(rawMemory);

    return 0;
}