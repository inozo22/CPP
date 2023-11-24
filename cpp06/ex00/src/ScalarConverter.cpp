/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:45:12 by nimai             #+#    #+#             */
/*   Updated: 2023/11/24 17:25:40 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>

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
	//int check
	{
		
		this->_type = INT;
	}
	
	//float check
	{
		this->_type = FLOAT;
	}
	//double check
	{
		this->_type = DOUBLE;
	}
	//char check
	if (str.length() == 1)
	{
		this->_type = CHAR;
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
