/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:45:12 by nimai             #+#    #+#             */
/*   Updated: 2024/03/01 09:38:31 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <limits>
#include <sstream>

int ScalarConverter::bitFlag = 0;
int	ScalarConverter::type = 0;
int	ScalarConverter::retInt = 0;
char ScalarConverter::retChar = 0;
double ScalarConverter::retDouble = 0;
float ScalarConverter::retFloat = 0;

ScalarConverter::ScalarConverter( void ) 
{
	// std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter( ScalarConverter const & src ) 
{
	// std::cout << "Copy constructor called" << std::endl;
	if (this != &src)
		*this = src;
}

ScalarConverter::~ScalarConverter( void )
{
	// std::cout << "Default destructor called" << std::endl;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter & src)
{
	// std::cout << "AForm assignment operator overload called." << std::endl;
	(void)src;
	return (*this);
}

bool	ScalarConverter::checkInt( std::string const & str )
{
	long	value = 0;
	char	*ptr = NULL;

	value = std::strtol(str.c_str(), &ptr, 10);
	if (ptr == str.c_str() || *ptr)
		return (false);
	if (value < INT_MIN || value > INT_MAX)
	{
		ScalarConverter::bitFlag = INT_OVER;
		return (false);
	}
	ScalarConverter::retInt = static_cast<int>(value);
	return (true);
}

bool	ScalarConverter::checkFloat( std::string const & str )
{
	char	*ptr = NULL;
	float	value = 0;

	if (str == "-nanf")
		return (false);
	value = std::strtod(str.c_str(), &ptr);
	if (ptr == str.c_str() || *ptr != 'f')
		return (false);
	if (*ptr == 'f' && (ptr + 1 && *(ptr + 1) != '\0'))
		return (false);
	ScalarConverter::retFloat = value;
	return (true);
}

bool	ScalarConverter::checkDouble( std::string const & str )
{
	char	*ptr = NULL;
	double	value = 0;

	if (str.find('.') == std::string::npos)
		return (false);
	value = std::strtod(str.c_str(), &ptr);
	if (ptr == str.c_str() || *ptr)
		return (false);
	ScalarConverter::retDouble = value;
	return (true);
}

bool	ScalarConverter::checkChar( std::string const & str )
{
	if (str.length() == 1)
	{
		if (!std::isprint(str[0]))
			ScalarConverter::bitFlag = CHAR_UNPRI;
		ScalarConverter::retChar = str[0];
		return (true);
	}
	return (false);
}

/**
 * @note main function
  */
void	ScalarConverter::convert(std::string const & input)
{
// pseudo check
	if (input == "inf" || input == "+inf" || input == "inff" || input == "+inff")
	{
		ScalarConverter::bitFlag = INT_OVER | CHAR_OVER;
		ScalarConverter::retFloat = std::numeric_limits<float>::infinity();
		ScalarConverter::retDouble = std::numeric_limits<double>::infinity();
	}
	else if (input == "-inf" || input == "-inff")
	{
		ScalarConverter::bitFlag = INT_OVER | CHAR_OVER;
		ScalarConverter::retFloat = (-1) * std::numeric_limits<float>::infinity();
		ScalarConverter::retDouble  = (-1) * std::numeric_limits<double>::infinity();
	}
	else if (input == "nan" || input == "nanf")
	{
		ScalarConverter::bitFlag = INT_OVER | CHAR_OVER;
		ScalarConverter::retFloat = std::numeric_limits<float>::quiet_NaN();
		ScalarConverter::retDouble  = std::numeric_limits<double>::quiet_NaN();
	}
	if (ScalarConverter::bitFlag & CHAR_OVER)
	{
		printResult();
		return ;
	}

// string's type check
	if (ScalarConverter::checkInt(input))
		ScalarConverter::type = INT;
	else if (ScalarConverter::checkDouble(input))
		ScalarConverter::type = DOUBLE;
	else if (ScalarConverter::checkFloat(input))
		ScalarConverter::type = FLOAT;
 	else if (ScalarConverter::checkChar(input))
		ScalarConverter::type = CHAR;

// convert depends on the its type 
	switch (ScalarConverter::type)
	{
		case CHAR:
				convertFromChar();
				break;
		case INT:
				convertFromInt();
				break;
		case DOUBLE:
				convertFromDouble();
				break;
		case FLOAT:
				convertFromFloat();
				break;
		default:
				throw(ScalarConverter::NonConvertableException());
	}
// print converted result
	printResult();
}

void	ScalarConverter::printResult( void )
{
	std::cout << std::setfill(' ') << std::setw(8) << "char: ";
	if (ScalarConverter::bitFlag & CHAR_OVER)
		std::cout << "Impossible";
	else if (ScalarConverter::bitFlag & CHAR_UNPRI)
		std::cout << "Non displayable";
	else
		std::cout << "'" << ScalarConverter::retChar << "'";
	std::cout << "\n" << std::setfill(' ') << std::setw(8) << "int: ";
	if (ScalarConverter::bitFlag & INT_OVER)
		std::cout << "Impossible";
	else
		std::cout << ScalarConverter::retInt;
	std::cout << "\n" << std::setfill(' ') << std::setw(8) << "float: ";
	std::cout << std::fixed << std::setprecision(1) << ScalarConverter::retFloat << "f";
	std::cout << "\n" << std::setfill(' ') << std::setw(8) << "Double: ";
	std::cout << std::fixed << std::setprecision(1) << ScalarConverter::retDouble << std::endl;
}

void	ScalarConverter::convertFromChar( void )
{
	ScalarConverter::retInt = static_cast<int>(ScalarConverter::retChar);
	ScalarConverter::retDouble = static_cast<double>(ScalarConverter::retChar);
	ScalarConverter::retFloat = static_cast<float>(ScalarConverter::retChar);
}

void	ScalarConverter::convertFromInt( void )
{
	ScalarConverter::retChar = static_cast<char>(ScalarConverter::retInt);
	ScalarConverter::retDouble = static_cast<double>(ScalarConverter::retInt);
	ScalarConverter::retFloat = static_cast<float>(ScalarConverter::retInt);
	if (!std::isprint(ScalarConverter::retChar))
		ScalarConverter::bitFlag = CHAR_UNPRI;
	if (ScalarConverter::retInt < CHAR_MIN || ScalarConverter::retInt > CHAR_MAX)
		ScalarConverter::bitFlag = CHAR_OVER;
}

void	ScalarConverter::convertFromDouble( void )
{
	ScalarConverter::retInt = static_cast<int>(ScalarConverter::retDouble);
	ScalarConverter::retChar = static_cast<char>(ScalarConverter::retDouble);
	ScalarConverter::retFloat = static_cast<float>(ScalarConverter::retDouble);
	if (!std::isprint(ScalarConverter::retChar))
		ScalarConverter::bitFlag = CHAR_UNPRI;
	if (ScalarConverter::retDouble < CHAR_MIN || ScalarConverter::retDouble > CHAR_MAX)
		ScalarConverter::bitFlag = CHAR_OVER;
	if (ScalarConverter::retDouble < INT_MIN || ScalarConverter::retDouble > INT_MAX)
		ScalarConverter::bitFlag = INT_OVER;
}

void	ScalarConverter::convertFromFloat( void )
{
	ScalarConverter::retInt = static_cast<int>(ScalarConverter::retFloat);
	ScalarConverter::retChar = static_cast<char>(ScalarConverter::retFloat);
	ScalarConverter::retDouble = static_cast<double>(ScalarConverter::retFloat);
	if (!std::isprint(ScalarConverter::retChar))
		ScalarConverter::bitFlag = CHAR_UNPRI;
	if (ScalarConverter::retFloat < CHAR_MIN || ScalarConverter::retFloat > CHAR_MAX)
		ScalarConverter::bitFlag = CHAR_OVER;
	if (ScalarConverter::retFloat < INT_MIN || ScalarConverter::retFloat > INT_MAX)
		ScalarConverter::bitFlag = INT_OVER;
}

const char	*	ScalarConverter::NonConvertableException::what(void) const throw()
{
	return ("Input value is not a legitimate type. (char, int, float, nor double)");
}

