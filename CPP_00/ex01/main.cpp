#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <limits>

int main()
{
    std::string input;
    std::string first_name, last_name, nickname, phone_number, darkest_secret;
    PhoneBook phone_book;
    int index;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, input))
            break;
        if (input == "ADD")
        {
            std::getline(std::cin, first_name);
            std::getline(std::cin, last_name);
            std::getline(std::cin, nickname);
            std::getline(std::cin, phone_number);
            std::getline(std::cin, darkest_secret);
            if (first_name.empty() ||
                last_name.empty() ||
                nickname.empty() ||
                phone_number.empty() ||
                darkest_secret.empty())
            {
                std::cout << "All fields are required!" << std::endl;
                continue;
            }
            Contact newContact(first_name,
                               last_name,
                               nickname,
                               phone_number,
                               darkest_secret);
            phone_book.add_contact(newContact);
        }
        else if (input == "SEARCH")
        {
            if (!(phone_book.display_contacts()))
                continue;
            std::cout << "Enter index to view details: ";
            while (!(std::cin >> index))
            {
                if (std::cin.eof())
                    return 0;
                std::cin.clear();                                                   // Clear error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                std::cout << "Invalid input! Please enter a number." << std::endl
                          << "Enter index to view details: ";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            phone_book.display(index);
        }
        else if (input == "EXIT")
            break;
    }
    return 0;
}