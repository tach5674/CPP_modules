#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
private:
    std::map<std::string, double> rates;

    bool isLeapYear(int year) const;
    int daysInMonth(int year, int month) const;
    bool isValidDate(const std::string &date) const;
    bool isValidValue(const double value) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    bool loadDatabase(const std::string &filename);
    void print() const;
    void processInputFile(const std::string &filename) const;
};
