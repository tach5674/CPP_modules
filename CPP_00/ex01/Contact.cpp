#include "Contact.hpp"
#include <iomanip>

Contact::Contact()
    : first_name(""),
      last_name(""),
      nickname(""),
      phone_number(""),
      darkest_secret("") {}

Contact::Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
    : first_name(fn),
      last_name(ln),
      nickname(nn),
      phone_number(pn),
      darkest_secret(ds) {}

Contact::Contact(const Contact &other)
    : first_name(other.first_name),
      last_name(other.last_name),
      nickname(other.nickname),
      phone_number(other.phone_number),
      darkest_secret(other.darkest_secret) {}

Contact &Contact::operator=(const Contact &other)
{
    if (this != &other)
    {
        first_name = other.first_name;
        last_name = other.last_name;
        nickname = other.nickname;
        phone_number = other.phone_number;
        darkest_secret = other.darkest_secret;
    }
    return *this;
}

Contact::~Contact() {}

void Contact::display() const
{
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}

void Contact::preview(int index) const
{
    std::cout << "|" << std::setw(10) << index
              << "|" << std::setw(10) << first_name
              << "|" << std::setw(10) << last_name
              << "|" << std::setw(10) << nickname << "|" << std::endl;
}