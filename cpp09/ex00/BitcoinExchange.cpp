#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout << "BitcoinExchange constructued" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    std::cout << "BitcoinExchange copied" << std::endl;
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    std::cout << "assignment operator called for BitcoinExchange" << std::endl;
    if (this != &copy)
        *this = copy;
    return(*this);
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "BitcoinExchange destroyed" << std::endl;
}
