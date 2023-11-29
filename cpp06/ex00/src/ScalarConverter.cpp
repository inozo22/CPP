/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:45:12 by nimai             #+#    #+#             */
/*   Updated: 2023/11/24 16:41:26 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <climits>

ScalarConverter::ScalarConverter( void ) 
: _isChar(0), _isInt(0), _isFloat(0), _isDouble(0), _type(0), _error(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter( ScalarConverter const & src ) 
: _isChar(src._isChar), _isInt(src._isInt), _isFloat(src._isFloat), 
_isDouble(src._isDouble), _type(src._type), _error(src._error)
{
	std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter::ScalarConverter( std::string const & str ) 
: _isChar(0), _isInt(0), _isFloat(0), _isDouble(0), _type(0), _error(0)
{
	std::cout << "Constructor called (str: " << str << ")" << std::endl;

}

ScalarConverter::~ScalarConverter( void )
{
	std::cout << "Default destructor called" << std::endl;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter & src)
{
	this->_isChar = src._isChar;
	this->_isInt = src._isInt;
	this->_isFloat = src._isFloat;
	this->_isDouble = src._isDouble;
	this->_type = src._type;
	this->_error = src._error;
	std::cout << "Copy constructor called" << std::endl;
	return (*this);
}

bool	ScalarConverter::_checkInt(str::string const & str)
{
	long	value = 0;
	char	*ptr = NULL;

	value = std::strtol(str.c_str(), &ptr, 10);
	if (ptr == str.c_str() || *ptr)
	{
		return (false);
	}
	if (value < INT_MIN || value > INT_MAX)
	{
		return (false);
	}
	this->_isInt = static_cast<int>(value);
	return (true);
}

void	ScalarConverter::typeCheck( std::string const & str )
{
	if (str == "inf" || str == "+inf" || str == "inff" || str == "+inff")
	{
		//error counter
		
	}
	else if (str == "-inf" || str == "-inff")
	{
		//error counter
		
	}
	else if (str == "nan" || str == "nanf")
	{
		//error counter
		
	}
	if (_checkInt(str))
		this->type = INT;
	if (_checkFloat(str))
		this->type = FLOAT;	
	if (_checkDouble(str))
		this->type = DOUBLE;
	if (_checkChar(str))
		this->type = CHAR;
	//Int
/* 	{
		long	value = 0;
		char	*ptr = NULL;

		value = std::strtol(str.c_str(), &ptr, 10);

		if (ptr == str.c_str() || *ptr)
		{
			;
		}
		if (value < INT_MIN || value > INT_MAX)
		{
			;
		}
		this->_isInt = static_cast<int>(value);
		return (true);

	} */
	if (str.length() == 1)
	{
		if (!std::isprint(str[0]))
		{
			//error counter

		}
		this->_isChar = str[0];
	}
}





char	ScalarConverter::getChar( void ) const
{
	return (this->_isChar);
}

int	ScalarConverter::getInt( void ) const
{
	return (this->_isInt);
}

float	ScalarConverter::getFloat( void ) const
{
	return (this->_isFloat);
}

double	ScalarConverter::getDouble( void ) const
{
	return (this->_isDouble);
}

int	ScalarConverter::getType( void ) const
{
	return (this->_type);
}

const char	*	ScalarConverter::NonDisplayableException::what(void) const throw()
{
	return ("Non displayable");
}


/**
 * @note as result in the subject
  */
std::ostream &	operator << (std::ostream & os, ScalarConverter const & obj)
{
	(void) obj;
	os << std::setfill(' ') << std::setw(8) << "char: " << "char\n" 
	<< std::setfill(' ') << std::setw(8) << "int: " << "int\n" 
	<< std::setfill(' ') << std::setw(8) << "float: " << "float\n" 
	<< std::setfill(' ') << std::setw(8) << "double: " << "double";
	return (os);
}
