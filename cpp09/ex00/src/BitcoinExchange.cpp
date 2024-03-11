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


BitcoinExchange::Database BitcoinExchange::loadDatabase(const std::string& databaseFile) const
{
	Database data;
	std::ifstream file(databaseFile.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		std::exit(1);
	}

	std::string line;
	int i = 0;
	while (std::getline(file, line))
	{
		if (line.find("date,exchange_rate") != std::string::npos)
			continue;

//- - -DEBUG- - -//
//		if (i < 10)
//			std::cout << "i: " << i << std::endl;
//		if (i < 10)
//			std::cout << "line: " << line << std::endl;
//- - -DEBUG- - -//

		std::istringstream ss(line);

//- - -DEBUG- - -//
//		if (i < 10)
//			std::cout << "ss: " << ss << std::endl;
//- - -DEBUG- - -//

		Record record;
		std::string date;
		if (std::getline(ss, date, ',') && std::getline(ss, line))
		{
			std::istringstream valueStream(line);
//- - -DEBUG- - -//
//			if (i < 10)
//				std::cout << "valueStream: " << valueStream << std::endl;
//- - -DEBUG- - -//
			if (!(valueStream >> record.value))
			{
				std::cerr << "Error: invalid data in the database => " << line << std::endl;
			}
			else
			{
				data[date] = record;
			}
		}
		else
		{
			//std::cerr << "Error: invalid data in the database => " << line << std::endl;
		}
		i++;
	}

	file.close();
	return data;
}

std::string	BitcoinExchange::findClosestDate(const Database& database, const std::string& targetDate) const
{
	for (Database::const_reverse_iterator it = database.rbegin(); it != database.rend(); ++it)
	{
		if (it->first <= targetDate)
		{
			return it->first;
		}
	}
	return "";
}

bool	BitcoinExchange::isValidDate(const std::string & date) const
{
	std::istringstream ss(date);
	std::string year, mounth, day;
	if (std::getline(ss, year, '-') && std::getline(ss, mounth, '-') && std::getline(ss, day, ' '))
	{
//		std::cout << year << "/" << mounth << "/" << day << std::endl;
//		std::cout << year.size() << "/" << mounth.size() << "/" << day.size() << std::endl;
		if (year.size() != 4 || mounth.size() != 2 || day.size() != 2)
			return false;
		if (!std::isdigit(mounth[1]) || !std::isdigit(day[1]))
			return false;
		int yy = std::atoi(year.c_str());
		int mm = std::atoi(mounth.c_str());
		int dd = std::atoi(day.c_str());
//		std::cout << yy << "-" << mm << "-" << dd << std::endl;
		if (yy < 1000 || yy > 3000 || mm < 1 || mm > 12 || dd < 1 || dd > 31)
			return false;
		if ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && dd == 31)
			return false;
		if (mm == 2 && ((!(yy % 4) && dd > 29) ||((yy % 4) && dd > 28)))
			return false;
		return true;
	}
	return false;

}

void	BitcoinExchange::processInputFile(const std::string& inputFileName) const
{
	std::ifstream inputFile(inputFileName.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: could not open input file " << inputFileName << std::endl;
		std::exit(1);
	}

	std::string line;
	while (std::getline(inputFile, line))
	{
		if (line.find("date | value") != std::string::npos)
			continue;
		if (line.empty() || line[0] == '#')
			continue;
		std::istringstream ss(line);
		std::string date, valueStr;
		if (std::getline(ss, date, '|') && std::getline(ss, valueStr))
		{
//- - -DEBUG- - -//
			std::cout << CYAN "date: " << date << std::endl;
			std::cout << "valueStr: " << valueStr << std::endl;
//- - -DEBUG- - -//

// Check the date is correct
			int ret = isValidDate(date);
			std::cout << "ret: " << ret << std::endl;
			if (!isValidDate(date))
			{
				std::cerr << "Error: bad input => " << line << std::endl;
				continue;
			}

			


			std::istringstream valueStream(valueStr);
			double value;
//- - -DEBUG- - -//
			std::cout << "value: " << value << RESET << std::endl;
//- - -DEBUG- - -//
			if (!(valueStream >> value))
			{
				std::cerr << "Error: not a positive number." << std::endl;
			}
			else
			{
				std::string closestDate = findClosestDate(database, date);

				if (!closestDate.empty())
				{
					Database::const_iterator it = database.find(closestDate);

					if (it != database.end())
					{
						double exchangeRate = value / it->second.value;
						std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << exchangeRate << std::endl;
					}
					else
					{
						std::cerr << "Error: No data found for closest date (" << closestDate << ")." << std::endl;
					}
				}
				else
				{
					//std::cerr << "Error: No valid date found in the database for " << date << "." << std::endl;
				}
			}
		}
		else
		{
			std::cerr << "Error: bad input => " << line << std::endl;
		}
	}

	inputFile.close();
}

