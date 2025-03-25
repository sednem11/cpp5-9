#pragma once

#include <iostream>
#include <map>


class BitcoinExchange
{
    private:
        std::map<std::string, float> Data;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);

        BitcoinExchange &operator=(const BitcoinExchange &copy);
        ~BitcoinExchange();
        void    Add_Date(std::string Data);
};
