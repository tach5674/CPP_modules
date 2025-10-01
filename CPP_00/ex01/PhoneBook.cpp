#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contact_count(0) {}

PhoneBook::PhoneBook(const PhoneBook &other) : contact_count(other.contact_count)
{
    for (int i = 0; i < contact_count; ++i)
    {
        contacts[i] = other.contacts[i];
    }
}

PhoneBook &PhoneBook::operator=(const PhoneBook &other)
{
    if (this != &other)
    {
        contact_count = other.contact_count;
        for (int i = 0; i < contact_count; ++i)
        {
            contacts[i] = other.contacts[i];
        }
    }
    return *this;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::add_contact(const Contact &newContact)
{
    contacts[contact_count % 8] = newContact;
    contact_count++;
}

void PhoneBook::display(int index) const
{
    if (index < 0 || index >= 8 || index >= contact_count % 8)
    {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    contacts[index].display();
}

void PhoneBook::display_contacts() const
{
    for (int i = 0; i < (contact_count < 8 ? contact_count : 8); ++i)
    {
        contacts[i].preview(i);
    }
}