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
: _isChar(0), _isInt(0), _isFloat(0), _isDouble(0), _type(0), _bitFlag(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter( ScalarConverter const & src ) 
: _isChar(src._isChar), _isInt(src._isInt), _isFloat(src._isFloat), 
_isDouble(src._isDouble), _type(src._type), _bitFlag(src._bitFlag)
{
	std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter::ScalarConverter( std::string const & str ) 
: _isChar(0), _isInt(0), _isFloat(0), _isDouble(0), _type(0), _bitFlag(0)
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
	this->_bitFlag = src._bitFlag;
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
		_bitFlag = CHAR_OVER;
		return (false);
	}
	this->_isInt = static_cast<int>(value);
	return (true);
}

bool	ScalarConverter::_checkFloat(str::string const & str)
{
	float	value = 0;
	char	*ptr = NULL;

	value = std::strtof(str.c_str(), &ptr, 10);
	if (ptr == str.c_str() || *ptr != 'f')
	{
		return (false);
	}
	if (*ptr == 'f' && ptr + 1 && !*(ptr + 1))
	{
		return (false);
	}
	this->_isFloat = value;
	return (true);
}

bool	ScalarConverter::_checkDouble(str::string const & str)
{
	double	value = 0;
	char	*ptr = NULL;

	if (str.find('.') == std::string::npos)
		return (false);
	value = std::strtod(str.c_str(), &ptr);
	if (ptr == str.c_str() || *ptr)
		return (false);
	this->_isDouble = value;
	return (true);
}

bool	ScalarConverter::_checkChar(str::string const & str)
{
	if (str.length() == 1)
	{
		if (!std::isprint(str[0]))
		{
			//error counter
			bitFlag = CHAR_UNPRI;
		}
		this->_isChar = str[0];
		return (true);
	}
	else
		return (false);
}

void	ScalarConverter::_typeCheck( std::string const & str )
{
	if (str == "inf" || str == "+inf" || str == "inff" || str == "+inff")
	{
		bitFlag = INT_OVER | CHAR_OVER;
		_isFloat = std::numeric_limits<float>::infinity();
		_isDouble = std::numeric_limits<double>::infinity();
		_type = OTHER;
	}
	else if (str == "-inf" || str == "-inff")
	{
		bitFlag = INT_OVER | CHAR_OVER;
		_isFloat = (-1) * std::numeric_limits<float>::infinity();
		_isDouble = (-1) * std::numeric_limits<double>::infinity();
		_type = OTHER;
	}
	else if (str == "nan" || str == "nanf")
	{
		bitFlag = INT_OVER | CHAR_OVER;
		_isFloat = std::numeric_limits<float>::quiet_NaN();
		_isDouble = std::numeric_limits<double>::quiet_NaN();
		_type = OTHER;
	}
	else if (_checkInt(str))
		this->type = INT;
	else if (_checkFloat(str))
		this->type = FLOAT;	
	else if (_checkDouble(str))
		this->type = DOUBLE;
	else if (_checkChar(str))
		this->type = CHAR;
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
	return ("Input value is not a legitimate type type. (char, int, float, nor double)");
}


/**
 * @note as result in the subject
  */
std::ostream &	operator << (std::ostream & os, ScalarConverter const & obj)
{
	os << std::setfill(' ') << std::setw(8) << "char: ";
	if (obj._bitFlag & CHAR_OVER)
		os << "Char overflow";//error message
	else if (obj._bitFlag & CHAR_UNPRI)
		os << "Char is not printable";//error message
	else
		os << obj.getChar();
	os << "\n" << std::setfill(' ') << std::setw(8) << "int: ";
	if (obj._bitFlag & INT_OVER)
		os << "Int overflow" << std::endl;//error message
	else
		os << obj.getInt();
	os << "\n" << std::setfill(' ') << std::setw(8) << "float: ";
	if (obj.getFloat() == static_cast<int>(obj.getFloat()))
		os << std::fixed << std::setprecision(1) << obj.getFloat() << "f";
	else
		os << obj.getFloat() << "f";
	os << "\n" << std::setfill(' ') << std::setw(8) << "double: "
	<<	obj.getDouble();
	return (os);
}
