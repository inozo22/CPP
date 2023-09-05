/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:03:55 by nimai             #+#    #+#             */
/*   Updated: 2023/09/05 15:12:49 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//constructor and destructor//constructor and destructor//
ClapTrap::ClapTrap( void ):
{
//	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( const int num ): _value(num << this->_bits)
{
	// std::cout << "Int constructor called, value is " << this->_value << std::endl;
	// std::cout << "num is " << num << std::endl;
}

ClapTrap::ClapTrap( const float numf ): _value(roundf((float)numf * (1 << this->_bits)))
{
	// std::cout << "Float constructor called, value is " << this->_value << std::endl;
	// std::cout << "numf is " << numf << std::endl;
}

ClapTrap::~ClapTrap(void)
{	
//	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &src )
{
//	std::cout << "Copy constructor called" << std::endl;
	this->operator=(src);
}
//constructor and destructor//constructor and destructor//


/**
 * A static member function min that takes as parameters two references 
 * on ClapTrap-point numbers, and returns a reference to the smallest one.
  */
ClapTrap &ClapTrap::min( ClapTrap &a, ClapTrap &b )
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

/**
 * A static member function min that takes as parameters two references 
 * to constant ClapTrap-point numbers, and returns a reference to the smallest one.
  */
ClapTrap const &ClapTrap::min( const ClapTrap &a, const ClapTrap &b )
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

/**
 * A static member function max that takes as parameters two references on 
 * ClapTrap-point numbers, and returns a reference to the greatest one.
  */
ClapTrap &ClapTrap::max( ClapTrap &a, ClapTrap &b )
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

/**
 * A static member function max that takes as parameters two references to 
 * constant ClapTrap-point numbers, and returns a reference to the greatest one.
  */
ClapTrap const &ClapTrap::max( const ClapTrap &a, const ClapTrap &b )
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}


//The 6 comparison operators: >, <, >=, <=, == and !=

bool	ClapTrap::operator>(const ClapTrap &src) const
{
	return (this->_value > src._value);
}

bool	ClapTrap::operator<(const ClapTrap &src) const
{
	return (this->_value < src._value);
}

bool	ClapTrap::operator>=(const ClapTrap &src) const
{
	return (this->_value >= src._value);
}

bool	ClapTrap::operator<=(const ClapTrap &src) const
{
	return (this->_value <= src._value);
}

bool	ClapTrap::operator==(const ClapTrap &src) const
{
	return (this->_value == src._value);
}

bool	ClapTrap::operator!=(const ClapTrap &src) const
{
	return (this->_value != src._value);
}



//The 4 arithmetic operators: +, -, *, and /

ClapTrap	ClapTrap::operator+(const ClapTrap &src) const
{
	return (ClapTrap(this->toFloat() + src.toFloat()));
}

ClapTrap	ClapTrap::operator-(const ClapTrap &src) const
{
	return (ClapTrap(this->toFloat() - src.toFloat()));
}

ClapTrap	ClapTrap::operator*(const ClapTrap &src) const
{
	return (ClapTrap(this->toFloat() * src.toFloat()));
}

ClapTrap	ClapTrap::operator/(const ClapTrap &src) const
{
	return (ClapTrap(this->toFloat() / src.toFloat()));
}

//The 4 increment/decrement (++i, i++, --i, i--) operators
ClapTrap	&ClapTrap::operator++( void )
{
//	std::cout << "++ with ref called" << std::endl;
	this->_value++;
	return (*this);
}

ClapTrap	&ClapTrap::operator--( void )
{
//	std::cout << "-- with ref called" << std::endl;
	this->_value--;
	return (*this);
}

ClapTrap	ClapTrap::operator++( int )
{
//	std::cout << "++ called" << std::endl;
	ClapTrap tmp( *this );
	operator++();
	return (tmp);
}

ClapTrap	ClapTrap::operator--( int )
{
//	std::cout << "-- called" << std::endl;
	ClapTrap tmp( *this );
	operator--();
	return (tmp);
}

ClapTrap &ClapTrap::operator=( const ClapTrap &src )
{
//	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &src)
 		return (*this);
	this->_value = src.getRawBits();
	return (*this);
}

int	ClapTrap::getRawBits( void ) const
{
	return (this->_value);
}

void	ClapTrap::setRawBits( int const raw )
{
	this->_value = raw;
}

float	ClapTrap::toFloat( void ) const
{
	return ((float)this->_value / (1 << this->_bits));
}

int	ClapTrap::toInt( void ) const
{
	return (this->_value / (1 << this->_bits));
}

std::ostream& operator<<(std::ostream &out, ClapTrap const &src)
{
	out << src.toFloat();
	return out;
}
