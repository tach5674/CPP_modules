#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

public:
    // Default constructor
    Contact();

    //Parameterized constructor
    Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);

    // Copy constructor
    Contact(const Contact &other);

    // Copy assignment operator
    Contact &operator=(const Contact &other);

    // Destructor
    ~Contact();

    void display() const;

    void preview(int index) const;
};

#endif