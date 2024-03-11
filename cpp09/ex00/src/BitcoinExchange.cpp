#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>

//--- Orthodox Canonical Form ---//
BitcoinExchange::BitcoinExchange( void )
{
	// std::cout << "Default constructor called" << std::endl;
}
BitcoinExchange::BitcoinExchange( BitcoinExchange const & src)
{
	// std::cout << Copyt constructor called" << std::endl;
    if (this != &src)
	*this = src;
}
BitcoinExchange::~BitcoinExchange( void )
{
	// std::cout << "Destructor called" << std::endl;
}
BitcoinExchange & BitcoinExchange::operator=( const BitcoinExchange & src )
{
    // std::cout << "Assignment operator overload called." << std::endl;
	if (this != &src)
	{
        BitcoinExchange tmp(src);
        std::swap(*this, tmp);
	}
	return (*this);
}
//--- Orthodox Canonical Form ---//

// Constructor with parametor
BitcoinExchange::BitcoinExchange(const std::string& databaseFile) : database(loadDatabase(databaseFile))
{

}

BitcoinExchange::Database BitcoinExchange::loadDatabase(const std::string& databaseFile) const {
    Database data;
    std::ifstream file(databaseFile.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        std::exit(1);
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.find("date | value") != std::string::npos)
            continue;

        std::istringstream ss(line);
        Record record;
        std::string date;
        if (std::getline(ss, date, '|') && std::getline(ss, line)) {
            try {
                record.value = std::stod(line);
                data[date] = record;
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error: invalid data in the database => " << line << std::endl;
            } catch (const std::out_of_range& e) {
                std::cerr << "Error: too large a number." << std::endl;
            }
        } else {
            std::cerr << "Error: invalid data in the database => " << line << std::endl;
        }
    }

    file.close();
    return data;
}

std::string BitcoinExchange::findClosestDate(const Database& database, const std::string& targetDate) const {
    for (Database::const_reverse_iterator it = database.rbegin(); it != database.rend(); ++it) {
        if (it->first <= targetDate) {
            return it->first;
        }
    }
    return "";
}

void BitcoinExchange::processInputFile(const std::string& inputFileName) const {
    std::ifstream inputFile(inputFileName.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open input file " << inputFileName << std::endl;
        std::exit(1);
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.empty() || line[0] == '#')
            continue;

        std::istringstream ss(line);
        std::string date, valueStr;
        if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
            try {
                double value = std::stod(valueStr);
                std::string closestDate = findClosestDate(database, date);

                if (!closestDate.empty()) {
                    Database::const_iterator it = database.find(closestDate);

                    if (it != database.end()) {
                        double exchangeRate = value / it->second.value;
                        std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << exchangeRate << std::endl;
                    } else {
                        std::cerr << "Error: No data found for closest date (" << closestDate << ")." << std::endl;
                    }
                } else {
                    std::cerr << "Error: No valid date found in the database for " << date << "." << std::endl;
                }
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error: not a positive number." << std::endl;
            } catch (const std::out_of_range& e) {
                std::cerr << "Error: too large a number." << std::endl;
            }
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }

    inputFile.close();
}

