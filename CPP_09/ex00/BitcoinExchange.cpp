#include "BitcoinExchange.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <limits>

static std::string trim(const std::string &s)
{
    size_t start = 0;
    size_t end = s.size();

    while (start < end && std::isspace(static_cast<unsigned char>(s[start])))
        start++;

    while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1])))
        end--;

    return s.substr(start, end - start);
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : rates(other.rates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        this->rates = other.rates;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream data(filename.c_str());
    if (!data)
    {
        std::cerr << "Error: could not open file \"" << filename << "\"." << std::endl;
        return false;
    }
    std::string line;
    std::string date;
    std::string rate;

    getline(data, line);
    while (getline(data, line))
    {
        std::stringstream ss(line);
        if (!getline(ss, date, ',') || !getline(ss, rate))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            return false;
        }
        date = trim(date);
        if (!isValidDate(date))
            return false;

        rate = trim(rate);
        double val;
        ss.str(rate);
        ss.clear();
        if (!(ss >> val) || !ss.eof())
        {
            std::cerr << "Error: not a number." << std::endl;
            return false;
        }
        if (val < 0)
        {
            std::cerr << "Error: not a positive number.\n";
            return false;
        }
        this->rates[date] = std::atof(rate.c_str());
    }
    return true;
}

bool BitcoinExchange::isLeapYear(int year) const
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    return (year % 4 == 0);
}

int BitcoinExchange::daysInMonth(int year, int month) const
{
    static const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year))
        return 29;
    return days[month - 1];
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        std::cout << "Error: invalid date => " << date << std::endl;
        return false;
    }
    for (size_t i = 0; i < date.length(); i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
        {
            std::cout << "Error: invalid date => " << date << std::endl;
            return false;
        }
    }
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (month < 1 || month > 12)
    {
        std::cout << "Error: invalid month => " << date << std::endl;
        return false;
    }
    int maxDays = daysInMonth(year, month);
    if (day < 1 || day > maxDays)
    {
        std::cout << "Error: invalid day => " << date << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::isValidValue(const double value) const
{
    if (value < 0)
    {
        std::cerr << "Error: not a positive number.\n";
        return false;
    }
    if (value > 1000)
    {
        std::cerr << "Error: too large a number.\n";
        return false;
    }
    return true;
}

void BitcoinExchange::processInputFile(const std::string &filename) const
{
    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cerr << "Error: could not open file \"" << filename << "\"." << std::endl;
        return;
    }
    std::string line;
    std::string date;
    std::string value;

    getline(infile, line);
    while (getline(infile, line))
    {
        std::stringstream ss(line);
        if (!getline(ss, date, '|') || !getline(ss, value))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        date = trim(date);
        if (!isValidDate(date))
            continue;

        value = trim(value);
        double val;
        ss.str(value);
        ss.clear();
        if (!(ss >> val) || !ss.eof())
        {
            std::cerr << "Error: not a number." << std::endl;
            continue;
        }
        if (!isValidValue(val))
            continue;

        std::map<std::string, double>::const_iterator it = rates.lower_bound(date);
        if (it == rates.end())
            --it;
        else if (it->first != date)
        {
            if (it == rates.begin())
            {
                std::cerr << "Error: date is too early.\n";
                continue;
            }
            --it;
        }
        std::cout << date << " => " << val << " = " << val * it->second << std::endl;
    }
}

void BitcoinExchange::print() const
{
    std::map<std::string, double>::const_iterator it;
    for (it = rates.begin(); it != rates.end(); ++it)
    {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }
}