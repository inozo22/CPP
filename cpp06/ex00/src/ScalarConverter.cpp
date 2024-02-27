/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:45:12 by nimai             #+#    #+#             */
/*   Updated: 2024/02/27 12:01:44 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <limits>

int ScalarConverter::bitFlag = 0;

ScalarConverter::ScalarConverter( void ) 
{
	// std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter( ScalarConverter const & src ) 
{
	// std::cout << "Copy constructor called" << std::endl;
	(void)src;
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
	ScalarConverter::bitFlag = HAS_TYPE;
	return (true);
}

bool	ScalarConverter::checkFloat( std::string const & str )
{
	char	*ptr = NULL;

	std::strtof(str.c_str(), &ptr);
	if (ptr == str.c_str() || *ptr != 'f')
		return (false);
	if (*ptr == 'f' && (ptr + 1 && *(ptr + 1) != '\0'))
		return (false);
	ScalarConverter::bitFlag = HAS_TYPE;
	return (true);
}

bool	ScalarConverter::checkDouble( std::string const & str )
{
	char	*ptr = NULL;

	if (str.find('.') == std::string::npos)
		return (false);
	std::strtod(str.c_str(), &ptr);
	if (ptr == str.c_str() || *ptr)
		return (false);
	ScalarConverter::bitFlag = HAS_TYPE;
	return (true);
}

bool	ScalarConverter::checkChar( std::string const & str )
{
	if (str.length() == 1)
	{
		if (!std::isprint(str[0]))
			ScalarConverter::bitFlag = CHAR_UNPRI;
		if (!(ScalarConverter::bitFlag & HAS_TYPE))
			ScalarConverter::bitFlag = IS_CHAR;
		return (true);
	}
	else if (ScalarConverter::bitFlag & HAS_TYPE)
	{
		return (true);
	}
	return (false);
}

/**
 * @note main function
  */
void	ScalarConverter::convert(std::string const & input)
{
	double	doubleResult = 0;
	float	floatResult = 0;

// pseudo check
	if (input == "inf" || input == "+inf" || input == "inff" || input == "+inff")
	{
		ScalarConverter::bitFlag = INT_OVER | CHAR_OVER;
		floatResult = std::numeric_limits<float>::infinity();
		doubleResult = std::numeric_limits<double>::infinity();
	}
	else if (input == "-inf" || input == "-inff")
	{
		ScalarConverter::bitFlag = INT_OVER | CHAR_OVER;
		floatResult = (-1) * std::numeric_limits<float>::infinity();
		doubleResult = (-1) * std::numeric_limits<double>::infinity();
	}
	else if (input == "nan" || input == "nanf")
	{
		ScalarConverter::bitFlag = INT_OVER | CHAR_OVER;
		floatResult = std::numeric_limits<float>::quiet_NaN();
		doubleResult = std::numeric_limits<double>::quiet_NaN();
	}
	if (ScalarConverter::bitFlag & CHAR_OVER)
	{
		std::cout << std::setfill(' ') << std::setw(8) << "Char: " << "Impossible\n";
		std::cout << std::setfill(' ') << std::setw(8) << "Int: " << "Impossible\n";
		std::cout << std::setfill(' ') << std::setw(8) << "Float: " << floatResult << "f\n";
		std::cout << std::setfill(' ') << std::setw(8) << "Double: " << doubleResult << std::endl;
		return ;
	}

// string check (it's not a char ni number)
	ScalarConverter::checkInt(input);
	ScalarConverter::checkDouble(input);
	ScalarConverter::checkFloat(input);
	if (!ScalarConverter::checkChar(input))
	{
		throw ScalarConverter::NonConvertableException();
	}

// convert and print
	ScalarConverter::convertToChar(input);
	ScalarConverter::convertToInt(input);
	ScalarConverter::convertToFloat(input);
	ScalarConverter::convertToDouble(input);
}

void	ScalarConverter::convertToChar( std::string const & input )
{
	std::cout << std::setfill(' ') << std::setw(8) << "Char: ";
	try
	{
		if (ScalarConverter::bitFlag & CHAR_UNPRI)
			throw ScalarConverter::NonDisplableException();
		if (std::isprint(static_cast<char>(std::atoi(input.c_str()))))
			std::cout << "'" << static_cast<char>(std::atoi(input.c_str())) << "'" << std::endl;
		else
			throw ScalarConverter::NonDisplableException();
	}
	catch(const std::exception & e)
	{
		if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
			std::cout << "'" << static_cast<char>(input[0]) << "'" << std::endl;
		else
			std::cerr << "impossible" << std::endl;
	}
}

void	ScalarConverter::convertToInt( std::string const & input )
{
	std::cout << std::setfill(' ') << std::setw(8) << "Int: ";
	if (ScalarConverter::bitFlag & INT_OVER)
		std::cerr << "impossible" << std::endl;
	else if (ScalarConverter::bitFlag & IS_CHAR)
		std::cout << static_cast<int>(input[0]) << std::endl;
	else
	{
		try
			std::cout << static_cast<int>(std::atoi(input.c_str())) << std::endl;
		catch (const std::exception & e)
			std::cout << RED "" << e.what() << RESET << std::endl;	
	}
}

void	ScalarConverter::convertToDouble( std::string const & input )
{
	std::cout << std::setfill(' ') << std::setw(8) << "Double: ";
	if (ScalarConverter::bitFlag & IS_CHAR)
	{
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(input[0]) << std::endl;
		return ;
	}
	try
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(std::atof(input.c_str())) << std::endl;
	catch (const std::exception & e)
		std::cout << RED "" << e.what() << RESET << std::endl;
}

void	ScalarConverter::convertToFloat( std::string const & input )
{
	std::cout << std::setfill(' ') << std::setw(8) << "Float: ";
	if (ScalarConverter::bitFlag & IS_CHAR)
	{
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(input[0]) << "f" << std::endl;
		return ;
	}
	try
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(std::atof(input.c_str())) << std::endl;
	catch (const std::exception & e)
		std::cout << RED "" << e.what() << RESET << std::endl;
}

const char	*	ScalarConverter::NonConvertableException::what(void) const throw()
{
	return ("Input value is not a legitimate type. (char, int, float, nor double)");
}

const char	*	ScalarConverter::ImpossibleConvertException::what(void) const throw()
{
	return ("Impossible");
}

const char	*	ScalarConverter::NonDisplableException::what(void) const throw()
{
	return ("Not displayable");
}
