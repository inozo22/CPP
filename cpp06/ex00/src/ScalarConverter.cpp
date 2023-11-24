/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:45:12 by nimai             #+#    #+#             */
/*   Updated: 2023/11/24 15:39:32 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>

ScalarConverter::ScalarConverter( void ) 
: _isChar(0), _isInt(0), _isFloat(0), _isDouble(0), _type(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter( ScalarConverter const & src ) 
: _isChar(src._isChar), _isInt(src._isInt), _isFloat(src._isFloat), 
_isDouble(src._isDouble), _type(src._type)
{
    std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter::ScalarConverter( std::string const & str ) 
: _isChar(0), _isInt(0), _isFloat(0), _isDouble(0), _type(0)
{
    std::cout << "Constructor called (str: " << str << " )" << std::endl;

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
    std::cout << "Copy constructor called" << std::endl;
    return (*this);
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
