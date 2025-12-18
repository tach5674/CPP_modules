#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: wrong number of arguments.\n"
                     "Usage: ./btc input.csv\n";
        return 1;
    }
    BitcoinExchange exchanger = BitcoinExchange();
    if (!exchanger.loadDatabase("data.csv"))
    {
        std::cerr << "Unable to initialize the database.\n";
        return 1;
    }
    exchanger.processInputFile(argv[1]);
    return 0;
}