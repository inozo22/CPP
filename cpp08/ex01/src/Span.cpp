/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:03:30 by nimai             #+#    #+#             */
/*   Updated: 2023/12/13 14:16:30 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//--- Orthodox Canonical Form ---//
Span::Span( void ) 
{
	// std::cout << "Default constructor called" << std::endl;
}

Span::Span( unsigned int N ): _max(N) 
{
	// std::cout << "Constructor called" << std::endl;
}

Span::Span( Span const & src ) 
{
	// std::cout << "Copy constructor called" << std::endl;
	if (this != &src)
		*this = src;
}

Span::~Span( void )
{
	// std::cout << "Destructor called" << std::endl;
}

Span & Span::operator=(const Span & src)
{
	// std::cout << "AForm assignment operator overload called." << std::endl;
	this->_max = src._max;
    // to copy the vector, is it enough???
	this->_numbers = src._numbers;
	return (*this);
}
//--- Orthodox Canonical Form ---//


void	Span::addNumber( unsigned int Element )
{

}
int		Span::shortestSpan( void )
{

}
int		Span::longestSpan( void )
{

}

