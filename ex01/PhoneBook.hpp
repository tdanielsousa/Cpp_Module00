#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

/*
Add consts to make sure it only reads

objects are kinda like a struct in c, index and count can be inited in constructor
unlike c which need the creation of init functs

unlike c all inside the clas have acess implicitly to index and
 count dont need to pass (t_phonebook *pb)
*/
class PhoneBook
{
  private:
    Contact contacts_[8];
    int index_;
    int count_;

    std::string truncate_(std::string str) const;
    void printElement_(std::string str) const;

  public:
    PhoneBook();
    ~PhoneBook();

    void addContact();
    void searchContact() const;
};

#endif