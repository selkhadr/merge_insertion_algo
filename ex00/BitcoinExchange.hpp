#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP


# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <cstdlib>

class   BitcoinExchange
{
    std::map<unsigned int, double> map;
public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &obj);
    BitcoinExchange &operator=(const BitcoinExchange &obj);
    int     inputFile(void);
    int     format_test(std::string &line);
    int     only_digit(std::string &line);
    int     DateValueFormat(std::string &line);
    int     ConvertIntraFile_toMap(char *fileName);
};

#endif