#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index_(0), count_(0)
{
}
PhoneBook::~PhoneBook()
{
}

///////////////////////////////////////////////////////////////////////////////////////
//// helper funcs  ////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

std::string PhoneBook::truncate_(std::string str) const
{
    if (str.length() > 10)
    {
        return str.substr(0, 9) + ".";
    }
    return str;
}

void PhoneBook::printElement_(std::string str) const
{
    std::cout << MAGENTA << std::right << std::setw(10) << truncate_(str) << RESET;
    std::cout << YELLOW << "|" << RESET;
}

///////////////////////////////////////////////////////////////////////////////////////
//// ADD contact //////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void PhoneBook::addContact()
{
    Contact newContact;
    std::string input;

    std::cout << BLUE << "--- Adding a New Contact ---\n" << RESET;

    while (true)
    {
        std::cout << YELLOW << "First Name: " << RESET;
        if (!std::getline(std::cin, input))
            return;
        if (newContact.setFirstName(input) == true)
            break;
    }

    while (true)
    {
        std::cout << YELLOW << "Last Name: " << RESET;
        if (!std::getline(std::cin, input))
            return;
        if (newContact.setLastName(input) == true)
            break;
    }

    while (true)
    {
        std::cout << YELLOW << "Nickname: " << RESET;
        if (!std::getline(std::cin, input))
            return;
        if (newContact.setNickname(input) == true)
            break;
    }

    while (true)
    {
        std::cout << YELLOW << "Phone Number: " << RESET;
        if (!std::getline(std::cin, input))
            return;
        if (newContact.setPhoneNumber(input) == true)
            break;
    }

    while (true)
    {
        std::cout << YELLOW << "Darkest Secret: " << RESET;
        if (!std::getline(std::cin, input))
            return;
        if (newContact.setDarkestSecret(input) == true)
            break;
    }

    contacts_[index_] = newContact;
    index_ = (index_ + 1) % 8;
    if (count_ < 8)
        count_++;

    std::cout << BGREEN << "**** Contact successfully added! ****\n" << RESET;
}

///////////////////////////////////////////////////////////////////////////////////////
//// SEARCH contact   /////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void PhoneBook::searchContact() const
{
    if (count_ == 0)
    {
        std::cout << YELLOW << "*******************";
        std::cout << "\nPhonebook is empty!";
        std::cout << "\n*******************\n" << RESET;
        return;
    }

    std::cout << YELLOW << "---------------------------------------------\n";
    std::cout << "|" << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << "|\n";
    std::cout << "---------------------------------------------\n" << RESET;

    for (int i = 0; i < count_; i++)
    {
        std::cout << YELLOW << "|" << RESET;
        std::cout << MAGENTA << std::setw(10) << i << RESET;
        std::cout << YELLOW << "|" << RESET;
        printElement_(contacts_[i].getFirstName());
        printElement_(contacts_[i].getLastName());
        printElement_(contacts_[i].getNickname());
        std::cout << "\n";
    }

    std::cout << YELLOW << "---------------------------------------------\n" << RESET;

    std::string str;

    while (true)
    {
        std::cout << BLUE << "Enter the index of the contact to display: " << RESET;

        if (!std::getline(std::cin, str))
            return;

        if (str.length() == 1 && std::isdigit(str[0]))
        {
            int k = str[0] - '0';

            if (k < count_)
            {
                std::cout << YELLOW << "|----- Contact Details -----|\n";

                std::cout << YELLOW << std::left << std::setw(16) << "First Name:" << MAGENTA
                          << contacts_[k].getFirstName() << "\n";
                std::cout << YELLOW << std::left << std::setw(16) << "Last Name:" << MAGENTA
                          << contacts_[k].getLastName() << "\n";

                std::cout << YELLOW << std::left << std::setw(16) << "Nickname:" << MAGENTA
                          << contacts_[k].getNickname() << "\n";

                std::cout << YELLOW << std::left << std::setw(16) << "Phone Number:" << MAGENTA
                          << contacts_[k].getPhoneNumber() << "\n";

                std::cout << YELLOW << std::left << std::setw(16)
                          << "Darkest Secret:" << MAGENTA << contacts_[k].getDarkestSecret()
                          << "\n";

                std::cout << YELLOW << "|---------------------------|\n" << RESET;
                break;
            }
        }

        std::cout << BRED << "Error: Invalid index.\n" << RESET;
    }
}
