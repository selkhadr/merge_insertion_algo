#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>

int ConvertIntraFile_toMap(char *fileName, std::map<unsigned int, double> &map)
{
    unsigned int    date;
    unsigned int    tmp_date = 0;
    double          value;

    date = 0;
    (void)map;
    std::ifstream   IntraFile(fileName);
    if (!IntraFile.is_open())
    {
        std::cout << "Error opening the intra file." << std::endl;
        return (1);
    }
    std::string line;
    getline(IntraFile, line);
    while (getline(IntraFile, line))
    {
        date = 0;
        tmp_date = strtod( line.substr(0, 4).c_str(), nullptr );
        tmp_date *= 10000;
        date += tmp_date;

        tmp_date = strtod( line.substr(5, 7).c_str(), nullptr );
        tmp_date *= 100;
        date += tmp_date;

        tmp_date = strtod( line.substr(8, 10).c_str(), nullptr );
        date += tmp_date;

        value = strtod( line.substr(11, line.size()).c_str(), nullptr );
        std::cout << std::fixed << std::setprecision(10);
    
        map.insert(std::make_pair(date, value));
    }
    return  0;
}

int    DateValueFormat(std::string &line)
{
    if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
    {
        std::cout << "Error: bad input " << line << std::endl;
        return 1;
    }
    return 0;
}

int    only_digit(std::string &line)
{
    if(line[4] != '-' || line[7] != '-')
    {
        std::cout << "Error: bad input " << line << std::endl;
        return 1;
    }
    size_t i =0;
    while (i < 10)
    {
        if (i != 4 && i != 7 && !isdigit(line[i]))
        {
            std::cout << "Error: bad input " << line << std::endl;
            return 1;
        }
        i++;
    }
    i = 13;
    int dot_status = 0;
    while (i < line.size())
    {
        if (!isdigit(line[i]) && dot_status)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            return 1;
        }
        if (line[i] == '.')
            dot_status = 1;
        i++;
    }
    return 0;
}

int format_test(std::string &line, std::map<unsigned int, double> &map)
{
    if (DateValueFormat(line))
        return 1;
    if (only_digit(line))
        return 1;

    unsigned int    date;
    unsigned int    tmp_date = 0;
    double          value;
    date = 0;
    tmp_date = strtod( line.substr(0, 4).c_str(), nullptr );
    tmp_date *= 10000;
    date += tmp_date;

    tmp_date = strtod( line.substr(5, 7).c_str(), nullptr );
    tmp_date *= 100;
    date += tmp_date;

    tmp_date = strtod( line.substr(8, 10).c_str(), nullptr );
    date += tmp_date;

    value = strtod( line.substr(13, line.size()).c_str(), nullptr );
    std::cout << std::fixed << std::setprecision(2);
    if (value < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return 1;
    }
    if (value > INT_MAX)
    {
        std::cout << "Error: too large a number" << std::endl;
        return 1;
    }


    std::map<unsigned int, double>::iterator it = map.begin();
    std::map<unsigned int, double>::iterator ite = map.begin();
    it = ite;
    while (it != map.end())
    {
        if (it->first <= date && ite->first < it->first)
            ite = it;
        it++;
    }
    std::cout << line.substr(0, 10) << " => " << value << " = " << value * ite->second << std::endl;
    return 0;
}

int inputFile(std::map<unsigned int, double> &intraFile)
{
    std::ifstream file("file");
    if (!file.is_open())
    {
        std::cout << "Error opening the intra file." << std::endl;
        return (1);
    }
    std::string line;
    getline(file, line);
    while (getline(file, line))
    {
        format_test(line, intraFile);
    }
    return 0;
}

int main(int ac, char **av)
{
    std::map<unsigned int, double> intraFile;
    if (ac != 2)
    {
        std::cout << "enter a file name please" << std::endl;
        return 1;
    }
    if (ConvertIntraFile_toMap(av[1], intraFile))
        return 1;
    inputFile(intraFile);
}
