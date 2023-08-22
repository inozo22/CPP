/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:03:55 by nimai             #+#    #+#             */
/*   Updated: 2023/08/22 14:44:53 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void )
{
	
}

Fixed::~Fixed(void)
{	

}

Fixed::Fixed( const Fixed &fixed )
{
	std::cout << MSG_DEBUG << std::endl;
}

Fixed &Fixed::operator = ( const Fixed &fixed )
{
	std::cout << MSG_INFO << std::endl;
}

