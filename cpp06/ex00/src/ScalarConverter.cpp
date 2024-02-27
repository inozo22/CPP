/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:45:12 by nimai             #+#    #+#             */
/*   Updated: 2024/02/27 11:50:51 by nimai            ###   ########.fr       */
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
//	char	charResult = 0;
//	int		intResult = 0;
	double	doubleResult = 0;
	float	floatResult = 0;
//	ScalarConverter::bitFlag = 0;

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

	ScalarConverter::convertToChar(input);
	ScalarConverter::convertToInt(input);
	ScalarConverter::convertToFloat(input);
	ScalarConverter::convertToDouble(input);
	// Convert to char
	/* std::cout << std::setfill(' ') << std::setw(8) << "Char: ";
	try 
	{
		charResult = convertToChar(input);
        std::cout << charResult << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
    }

	// Convert to int
	try
	{
		intResult = ScalarConverter::convertToInt(input);
		std::cout << "Int: " << intResult << std::endl;
    }
	catch (const std::exception & e)
	{
		std::cerr << "Int: " << e.what() << std::endl;
	}
	
	// Convert to float
	try
	{
		floatResult = ScalarConverter::convertToDouble(input);
		std::cout << "Float: " << floatResult << std::endl;
    }
	catch (const std::exception & e)
	{
		std::cerr << "Float: " << e.what() << std::endl;
    }

	// Convert to double
	try
	{
		doubleResult = ScalarConverter::convertToFloat(input);
		std::cout << "Double: " << doubleResult << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << "Double: " << e.what() << std::endl;
	} */






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
	//		std::cout << "Non Displable" << std::endl;
			throw ScalarConverter::NonDisplableException();
	}
	catch(const std::exception & e)
	{
		if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
			std::cout << "'" << static_cast<char>(input[0]) << "'" << std::endl;
		else
			std::cerr << "impossible" << std::endl;
			//throw ScalarConverter::ImpossibleConvertException();
	//		std::cout << "impossible\n";
	}
/* 	if (input.size() == 1)
	{
		if (ScalarConverter::bitFlag & CHAR_UNPRI)
			throw ScalarConverter::NonDisplableException();
		char charResult = input[0];
			return charResult;
	}
	else
		throw ScalarConverter::ImpossibleConvertException(); */
}

void	ScalarConverter::convertToInt( std::string const & input )
{
	std::cout << std::setfill(' ') << std::setw(8) << "Int: ";
	if (ScalarConverter::bitFlag & INT_OVER)
		std::cerr << "impossible" << std::endl;
	else if (ScalarConverter::bitFlag & IS_CHAR)
	{
		std::cout << static_cast<int>(input[0]) << std::endl;
	}
	else
	{
		std::cout << static_cast<int>(std::atoi(input.c_str())) << std::endl;
	}

/* 	this->_isChar = static_cast<char>(this->_isInt);
	this->_isDouble = static_cast<double>(this->_isInt);
	this->_isFloat = static_cast<float>(this->_isInt);
	if (!std::isprint(this->_isChar))
		this->bitFlag = CHAR_UNPRI;
	if (this->_isInt < CHAR_MIN || this->_isInt > CHAR_MAX)
		this->bitFlag = CHAR_OVER; */

//	return(0);

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
	{
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(std::atof(input.c_str())) << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << RED "" << e.what() << RESET << std::endl;
	}

/* 	this->_isInt = static_cast<int>(this->_isDouble);
	this->_isChar = static_cast<char>(this->_isDouble);
	this->_isFloat = static_cast<float>(this->_isDouble);
	if (!std::isprint(this->_isChar))
		this->bitFlag = CHAR_UNPRI;
	if (this->_isDouble < CHAR_MIN || this->_isDouble > CHAR_MAX)
		this->bitFlag = CHAR_OVER;
	if (this->_isDouble < INT_MIN || this->_isDouble > INT_MAX)
		this->bitFlag = INT_OVER; */
//	return(0);

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
	{
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(std::atof(input.c_str())) << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << RED "" << e.what() << RESET << std::endl;
	}

//	return(0);

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

/* #include "ScalarConverter.hpp"

// Static method for converting string representation to different scalar types
void ScalarConverter::convert(const std::string& input) {
    // Convert to char
    try {
        char charResult = convertToChar(input);
        std::cout << "Char: " << charResult << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error converting to char: " << e.what() << std::endl;
    }

    // Convert to int
    try {
        int intResult = std::stoi(input);
        std::cout << "Int: " << intResult << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error converting to int: " << e.what() << std::endl;
    }

    // Convert to float
    try {
        float floatResult = std::stof(input);
        std::cout << "Float: " << floatResult << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error converting to float: " << e.what() << std::endl;
    }

    // Convert to double
    try {
        double doubleResult = std::stod(input);
        std::cout << "Double: " << doubleResult << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error converting to double: " << e.what() << std::endl;
    }
}

// Helper function to convert string to char
char ScalarConverter::convertToChar(const std::string& input) {
    if (input.size() == 1) {
        char charResult = input[0];
        if (isprint(charResult)) {
            return charResult;
        } else {
            throw std::invalid_argument("Non-displayable character cannot be converted to char.");
        }
    } else {
        throw std::invalid_argument("Input is not a valid char literal.");
    }
}
 */