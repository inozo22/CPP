/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:03:55 by nimai             #+#    #+#             */
/*   Updated: 2023/09/04 16:01:26 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//constructor and destructor//constructor and destructor//
Point::Point( void ): _x(0), _y(0)
{
//	std::cout << "Default constructor called" << std::endl;
}

Point::Point( const float x, const float y ): _x(x), _y(y)
{
	// std::cout << "Int constructor called, value is " << this->_value << std::endl;
	// std::cout << "num is " << num << std::endl;
}

// Point::Point( const float numf ): _value(roundf((float)numf * (1 << this->_bits)))
// {
// 	// std::cout << "Float constructor called, value is " << this->_value << std::endl;
// 	// std::cout << "numf is " << numf << std::endl;
// }

Point::~Point(void)
{	
//	std::cout << "Destructor called" << std::endl;
}

Point::Point( const Point &src ): _x(src._x), _y(src._y)
{
//	std::cout << "Copy constructor called" << std::endl;
	// this->_x = src._x;
	// this->_y = src._y;
}
//constructor and destructor//constructor and destructor//




Point &Point::operator=( const Point &src )
{
//	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &src)
 		return (*this);
	(Fixed)this->_x = src.getX();
	(Fixed)this->_y = src.getY();
	return (*this);
}

Fixed	Point::getX( void ) const
{
	return (this->_x);
}

Fixed	Point::getY( void ) const
{
	return (this->_y);
}

