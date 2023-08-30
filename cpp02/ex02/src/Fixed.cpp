/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:03:55 by nimai             #+#    #+#             */
/*   Updated: 2023/08/30 17:53:31 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//constructor and destructor//constructor and destructor//
Fixed::Fixed( void ): _value(0)
{
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int num ): _value(num << this->_bits)//there is a conflict230823
{
//	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float numf ): _value(roundf((float)numf * (1 << this->_bits)))
{
//	std::cout << "Float constructor called" << std::endl;
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

//The 4 arithmetic operators: +, -, *, and /

//The 4 increment/decrement (++i, i++, --i, i--) operators
Fixed	&Fixed::operator++( void )
{
	this->_value++;
	return (*this);
}

Fixed	&Fixed::operator--( void )
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed tmp( *this );
	operator++();
	return (tmp);
}

Fixed	Fixed::operator--( int )
{
	Fixed tmp( *this );
	operator--();
	return (tmp);
}

Fixed &Fixed::operator = ( const Fixed &src )
{
	std::cout << "Copy assignment operator called" << std::endl;
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
