/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:03:55 by nimai             #+#    #+#             */
/*   Updated: 2023/08/24 15:50:35 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int num ): _value(num << this->_bits)//there is a conflict230823
{
	std::cout << "Int constructor called" << std::endl;
	std::cout << "num: " << num << std::endl;
	std::cout << "value: " << this->_value << std::endl;
}

Fixed::Fixed( const float numf ): _value(roundf((float)numf * (1 << this->_bits)))
{
	std::cout << "Float constructor called" << std::endl;
	std::cout << "numf: " << numf << std::endl;
	std::cout << "value: " << this->_value << std::endl;
}

Fixed::~Fixed(void)
{	
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &src )
{
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(src);
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
	std::cout << "setRawBits member function called" << std::endl;
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
