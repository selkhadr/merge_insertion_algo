#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(): map()
{
    
}

BitcoinExchange::~BitcoinExchange()
{
    
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
   *this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
    map = obj.map;
    return (*this);
}
