/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:45:12 by nimai             #+#    #+#             */
/*   Updated: 2024/02/26 16:21:52 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <limits>

ScalarConverter::ScalarConverter( void ) 
: bitFlag(0), _isChar(0), _isInt(0), _isFloat(0), _isDouble(0), _type(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter( ScalarConverter const & src ) 
: bitFlag(src.bitFlag), _isChar(src._isChar), _isInt(src._isInt), _isFloat(src._isFloat), 
_isDouble(src._isDouble), _type(src._type)
{
	// std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter::ScalarConverter( std::string const & str ) 
: bitFlag(0), _isChar(0), _isInt(0), _isFloat(0), _isDouble(0), _type(0)
{
	// std::cout << "Constructor called (str: " << str << ")" << std::endl;
	this->_scalarConversion(str);
}

ScalarConverter::~ScalarConverter( void )
{
	// std::cout << "Default destructor called" << std::endl;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter & src)
{
	this->_isChar = src._isChar;
	this->_isInt = src._isInt;
	this->_isFloat = src._isFloat;
	this->_isDouble = src._isDouble;
	this->_type = src._type;
	this->bitFlag = src.bitFlag;
	// std::cout << "Copy constructor called" << std::endl;
	return (*this);
}

/**
 * @note main function
  */
void	ScalarConverter::_scalarConversion(std::string const & str)
{
	this->_typeCheck(str);//obtain orginal type
	switch (this->_type)//convert depends on the original type
	{
	case CHAR:
		_convertFromChar();
		break;
	case INT:
		_convertFromInt();
		break;
	case DOUBLE:
		_convertFromDouble();
		break;
	case FLOAT:
		_convertFromFloat();
		break;
	case OTHER:
		break;
	default:
		throw(ScalarConverter::NonConvertableException());//when it doesn't much any, throw exception
	}
}

void	ScalarConverter::_convertFromChar( void )
{
	this->_isInt = static_cast<int>(this->_isChar);
	this->_isDouble = static_cast<double>(this->_isChar);
	this->_isFloat = static_cast<float>(this->_isChar);
}

void	ScalarConverter::_convertFromInt( void )
{
	this->_isChar = static_cast<char>(this->_isInt);
	this->_isDouble = static_cast<double>(this->_isInt);
	this->_isFloat = static_cast<float>(this->_isInt);
	if (!std::isprint(this->_isChar))
		this->bitFlag = CHAR_UNPRI;
	if (this->_isInt < CHAR_MIN || this->_isInt > CHAR_MAX)
		this->bitFlag = CHAR_OVER;
}

void	ScalarConverter::_convertFromDouble( void )
{
	this->_isInt = static_cast<int>(this->_isDouble);
	this->_isChar = static_cast<char>(this->_isDouble);
	this->_isFloat = static_cast<float>(this->_isDouble);
	if (!std::isprint(this->_isChar))
		this->bitFlag = CHAR_UNPRI;
	if (this->_isDouble < CHAR_MIN || this->_isDouble > CHAR_MAX)
		this->bitFlag = CHAR_OVER;
	if (this->_isDouble < INT_MIN || this->_isDouble > INT_MAX)
		this->bitFlag = INT_OVER;
}
void	ScalarConverter::_convertFromFloat( void )
{
	this->_isInt = static_cast<int>(this->_isFloat);
	this->_isChar = static_cast<char>(this->_isFloat);
	this->_isDouble = static_cast<double>(this->_isFloat);
	if (!std::isprint(this->_isChar))
		this->bitFlag = CHAR_UNPRI;
	if (this->_isFloat < CHAR_MIN || this->_isFloat > CHAR_MAX)
		this->bitFlag = CHAR_OVER;
	if (this->_isFloat < INT_MIN || this->_isFloat > INT_MAX)
		this->bitFlag = INT_OVER;
}

bool	ScalarConverter::_checkInt( std::string const & str )
{
	long	value = 0;
	char	*ptr = NULL;

	value = std::strtol(str.c_str(), &ptr, 10);
	if (ptr == str.c_str() || *ptr)
		return (false);
	if (value < INT_MIN || value > INT_MAX)
	{
		bitFlag = INT_OVER;
		return (false);
	}
	this->_isInt = static_cast<int>(value);
	return (true);
}

bool	ScalarConverter::_checkFloat( std::string const & str )
{
	float	value = 0;
	char	*ptr = NULL;

	value = std::strtof(str.c_str(), &ptr);
	if (ptr == str.c_str() || *ptr != 'f')
		return (false);
	if (*ptr == 'f' && (ptr + 1 && *(ptr + 1) != '\0'))
		return (false);
	this->_isFloat = value;
	return (true);
}

bool	ScalarConverter::_checkDouble( std::string const & str )
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

bool	ScalarConverter::_checkChar( std::string const & str )
{
	if (str.length() == 1)
	{
		this->_type = CHAR;
		if (!std::isprint(str[0]))
		{
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
		this->bitFlag = INT_OVER | CHAR_OVER;
		this->_isFloat = std::numeric_limits<float>::infinity();
		this->_isDouble = std::numeric_limits<double>::infinity();
		this->_type = OTHER;
	}
	else if (str == "-inf" || str == "-inff")
	{
		this->bitFlag = INT_OVER | CHAR_OVER;
		this->_isFloat = (-1) * std::numeric_limits<float>::infinity();
		this->_isDouble = (-1) * std::numeric_limits<double>::infinity();
		this->_type = OTHER;
	}
	else if (str == "nan" || str == "nanf")
	{
		this->bitFlag = INT_OVER | CHAR_OVER;
		this->_isFloat = std::numeric_limits<float>::quiet_NaN();
		this->_isDouble = std::numeric_limits<double>::quiet_NaN();
		this->_type = OTHER;
	}
	else if (_checkInt(str))
		this->_type = INT;
	else if (_checkFloat(str))
		this->_type = FLOAT;	
	else if (_checkDouble(str))
		this->_type = DOUBLE;
	else if (_checkChar(str))
		this->_type = CHAR;
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

const char	*	ScalarConverter::NonConvertableException::what(void) const throw()
{
	return ("Input value is not a legitimate type. (char, int, float, nor double)");
}

/**
 * @note as result in the subject
  */
std::ostream &	operator << (std::ostream & os, ScalarConverter const & obj)
{
	os << std::setfill(' ') << std::setw(8) << "char: ";
	if (obj.bitFlag & CHAR_OVER)
		os << "Impossible";//error message
	else if (obj.bitFlag & CHAR_UNPRI)
		os << "Non displayable";//error message
	else
		os << "'" << obj.getChar() << "'";
	os << "\n" << std::setfill(' ') << std::setw(8) << "int: ";
	if (obj.bitFlag & INT_OVER)
		os << "Impossible";//error message
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
