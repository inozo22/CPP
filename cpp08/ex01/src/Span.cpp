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
#include <iostream>
#include <stdexcept>
#include <limits>

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


void	Span::addNumber( const int element )
{
	if (this->_numbers.size() >= this->_max)
		throw std::out_of_range("Maximum number of elements reached");
	this->_numbers.push_back(element);
}

int		Span::shortestSpan( void )
{
	if (this->_numbers.size() <= 1)
		throw std::logic_error("There is no enough elements");
	std::sort(this->_numbers.begin(), this->_numbers.end());
	int ret = std::numeric_limits<int>::max();
	for (size_t i = 1; i < this->_numbers.size(); ++i)
	{
		int span = this->_numbers[i] - this->_numbers[i - 1];
		ret = std::min(ret, span);
	}
	return ret;
}

int		Span::longestSpan( void )
{
	if (this->_numbers.size() <= 1)
		throw std::logic_error("There is no enough elements");
	std::sort(this->_numbers.begin(), this->_numbers.end());
	return this->_numbers[_numbers.size() - 1] - this->_numbers[0];
}

