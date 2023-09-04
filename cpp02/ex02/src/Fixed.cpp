/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:03:55 by nimai             #+#    #+#             */
/*   Updated: 2023/09/04 12:54:24 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//constructor and destructor//constructor and destructor//
Fixed::Fixed( void ): _value(0)
{
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int num ): _value(num << this->_bits)
{
	// std::cout << "Int constructor called, value is " << this->_value << std::endl;
	// std::cout << "num is " << num << std::endl;
}

Fixed::Fixed( const float numf ): _value(roundf((float)numf * (1 << this->_bits)))
{
	// std::cout << "Float constructor called, value is " << this->_value << std::endl;
	// std::cout << "numf is " << numf << std::endl;
}

Fixed::~Fixed(void)
{	
//	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &src )
{
//	std::cout << "Copy constructor called" << std::endl;
	this->operator=(src);
}
//constructor and destructor//constructor and destructor//


/**
 * A static member function min that takes as parameters two references 
 * on fixed-point numbers, and returns a reference to the smallest one.
  */
Fixed &Fixed::min( Fixed &a, Fixed &b )
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

/**
 * A static member function min that takes as parameters two references 
 * to constant fixed-point numbers, and returns a reference to the smallest one.
  */
Fixed const &Fixed::min( const Fixed &a, const Fixed &b )
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

/**
 * A static member function max that takes as parameters two references on 
 * fixed-point numbers, and returns a reference to the greatest one.
  */
Fixed &Fixed::max( Fixed &a, Fixed &b )
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

/**
 * A static member function max that takes as parameters two references to 
 * constant fixed-point numbers, and returns a reference to the greatest one.
  */
Fixed const &Fixed::max( const Fixed &a, const Fixed &b )
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}


//The 6 comparison operators: >, <, >=, <=, == and !=

bool	Fixed::operator>(const Fixed &src) const
{
	return (this->_value > src._value);
}

bool	Fixed::operator<(const Fixed &src) const
{
	return (this->_value < src._value);
}

bool	Fixed::operator>=(const Fixed &src) const
{
	return (this->_value >= src._value);
}

bool	Fixed::operator<=(const Fixed &src) const
{
	return (this->_value <= src._value);
}

bool	Fixed::operator==(const Fixed &src) const
{
	return (this->_value == src._value);
}

bool	Fixed::operator!=(const Fixed &src) const
{
	return (this->_value != src._value);
}



//The 4 arithmetic operators: +, -, *, and /

Fixed	Fixed::operator+(const Fixed &src) const
{
	return (Fixed(this->toFloat() + src.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &src) const
{
	return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &src) const
{
	return (Fixed(this->toFloat() * src.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &src) const
{
	return (Fixed(this->toFloat() / src.toFloat()));
}

//The 4 increment/decrement (++i, i++, --i, i--) operators
Fixed	&Fixed::operator++( void )
{
//	std::cout << "++ with ref called" << std::endl;
	this->_value++;
	return (*this);
}

Fixed	&Fixed::operator--( void )
{
//	std::cout << "-- with ref called" << std::endl;
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
//	std::cout << "++ called" << std::endl;
	Fixed tmp( *this );
	operator++();
	return (tmp);
}

Fixed	Fixed::operator--( int )
{
//	std::cout << "-- called" << std::endl;
	Fixed tmp( *this );
	operator--();
	return (tmp);
}

Fixed &Fixed::operator=( const Fixed &src )
{
//	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &src)
 		return (*this);
	this->_value = src.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->_value / (1 << this->_bits));
}

int	Fixed::toInt( void ) const
{
	return (this->_value / (1 << this->_bits));
}

std::ostream& operator<<(std::ostream &out, Fixed const &src)
{
	out << src.toFloat();
	return out;
}
