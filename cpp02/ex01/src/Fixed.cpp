/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:03:55 by nimai             #+#    #+#             */
/*   Updated: 2023/12/20 13:18:29 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed( void ): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int num ): _value(num << this->_bits)//there is a conflict230823
{
	// std::cout << "num: " << num << " _value: " << this->_value << std::endl;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float numf ): _value(roundf((float)numf * (1 << this->_bits)))
{
	std::cout << "numf: " << numf << " _value roundf: " << this->_value << std::endl;
	std::cout << "numf: " << numf << " _value without roundf: " << (float)numf * (1 << this->_bits) << std::endl;

	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{	
	std::cout << "Destructor called" << std::endl;
	// std::cout << "_value: " << this->_value << std::endl;
}

Fixed::Fixed( const Fixed &src )
{
	std::cout << "Copy constructor called" << std::endl;
	// std::cout << "src._value: " << src._value << std::endl;
	this->operator = (src);
}

Fixed &Fixed::operator = ( const Fixed &src )
{
	std::cout << "Copy assignment operator called" << std::endl;
	// std::cout << "src._value: " << src._value << std::endl;
	if (this != &src)
		this->_value = src.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat( void ) const
{
//	return 0;
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
