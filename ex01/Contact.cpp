#include "Contact.hpp"

/*
Constructor:
-runs automatically when created, same as creating init functions for eveything in c.

Destructor~ :
-runs automatically when destroyed frees stuff do avoid mem leaks.
*/
Contact::Contact()
{
}
Contact::~Contact()
{
}

/*
Getters and setters:
since they are private (only contact can mess with them)
this lets PhoneBook main read/write data

setter:
can add rules to prevent bad stuff from being written

same as c (const std::string* const str)
helpers with _ to again signify private stuff
*/
bool Contact::setFirstName(const std::string& str)
{
    if (isOnlyLetters_(str) == false)
    {
        std::cout
            << RED
            << "Error: First name must contain only letters and spaces and cannot be empty!\n"
            << RESET;
        return false;
    }
    firstName_ = str;
    return true;
}

bool Contact::setLastName(const std::string& str)
{
    if (isOnlyLetters_(str) == false)
    {
        std::cout
            << RED
            << "Error: Last name must contain only letters and spaces, and not be empty!\n"
            << RESET;
        return false;
    }
    lastName_ = str;
    return true;
}

bool Contact::setNickname(const std::string& str)
{
    if (isValidSecret_(str) == false)
    {
        std::cout << RED
                  << "Error: Nickname must contain only letters, numbers, and spaces (and "
                     "cannot be empty)!\n"
                  << RESET;
        return false;
    }
    nickname_ = str;
    return true;
}
bool Contact::setPhoneNumber(const std::string& str)
{
    if (isOnlyDigits_(str) == false)
    {
        std::cout
            << RED
            << "Error: Phone number must contain digits only (0-9) and cannot be empty!\n"
            << RESET;
        return false;
    }
    phoneNumber_ = str;
    return true;
}

bool Contact::setDarkestSecret(const std::string& str)
{
    if (isValidSecret_(str) == false)
    {
        std::cout << RED
                  << "Error: Secret must contain only letters, numbers, and spaces (and "
                     "cannot be empty)!\n"
                  << RESET;
        return false;
    }
    darkestSecret_ = str;
    return true;
}

/*
getters:
dont need to add rules set already does that, just reads
*/
std::string Contact::getFirstName() const
{
    return firstName_;
}
std::string Contact::getLastName() const
{
    return lastName_;
}
std::string Contact::getNickname() const
{
    return nickname_;
}
std::string Contact::getPhoneNumber() const
{
    return phoneNumber_;
}
std::string Contact::getDarkestSecret() const
{
    return darkestSecret_;
}

////////////////////////////////////////////////
////////////////////////////////////////////////

bool Contact::isOnlyLetters_(const std::string& str) const
{
    if (str.empty() == true)
        return false;

    bool hasLetter = false;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (std::isalnum(str[i]))
        {
            hasLetter = true;
        }
        else if (str[i] != ' ')
        {
            return false;
        }
    }

    return hasLetter;
}

bool Contact::isValidSecret_(const std::string& str) const
{
    if (str.empty() == true)
        return false;

    bool hasAlnum = false;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (std::isalnum(str[i]))
        {
            hasAlnum = true;
        }
        else if (str[i] != ' ')
        {
            return false;
        }
    }

    return hasAlnum;
}

bool Contact::isOnlyDigits_(const std::string& str) const
{
    if (str.empty() == true)
        return false;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}
