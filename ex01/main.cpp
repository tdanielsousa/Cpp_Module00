#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string input;

    std::cout << YELLOW << "***************************************************\n";
    std::cout << ">> Welcome to the Crappy 80s Phonebook Software  <<\n";
    std::cout << "***************************************************\n" << RESET;

    while (true)
    {
        std::cout << BLUE << "Enter an input (ADD, SEARCH or EXIT): " << RESET;
        std::getline(std::cin, input);

        if (std::cin.eof() == true)
        {
            std::cout << MAGENTA << "\n**** CTRL + D pressed, exiting... ****\n" << RESET;
            break;
        }

        if (input == "ADD")
        {
            phoneBook.addContact();
        }
        else if (input == "SEARCH")
        {
            phoneBook.searchContact();
        }
        else if (input == "EXIT")
        {
            std::cout << MAGENTA << "\n**** Exiting phonebook... ****\n" << RESET;
            break;
        }
    }

    return 0;
}