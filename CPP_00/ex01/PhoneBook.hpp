#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int contact_count;

public:
    // Default constructor
    PhoneBook();

    // Copy constructor
    PhoneBook(const PhoneBook &other);

    // Copy assignment operator
    PhoneBook &operator=(const PhoneBook &other);

    // Destructor
    ~PhoneBook();

    void add_contact(const Contact &newContact);
    
    void display_contacts() const;

    void display(int index) const;
};

#endif