#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "Colors.hpp"
#include <string>
#include <iostream>
#include <iomanip>

/*
using _to signify private
changed to const, funcs only read dont change anything

Setters with & for only 1 copy vs 2
like pointer in c
*/
class Contact
{
  private:
    std::string firstName_;
    std::string lastName_;
    std::string nickname_;
    std::string phoneNumber_;
    std::string darkestSecret_;

    bool isOnlyLetters_(const std::string& str) const;
    bool isValidSecret_(const std::string& str) const;
    bool isOnlyDigits_(const std::string& str) const;

  public:
    Contact();
    ~Contact();

    bool setFirstName(const std::string& str);
    bool setLastName(const std::string& str);
    bool setNickname(const std::string& str);
    bool setPhoneNumber(const std::string& str);
    bool setDarkestSecret(const std::string& str);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
};

#endif