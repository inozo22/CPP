/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:03:30 by nimai             #+#    #+#             */
/*   Updated: 2023/12/13 14:16:30 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP
#include <iostream>

template <typename T>
MutantStack<T>::iterator::iterator(typename std::stack<T>::container_type::iterator iter): it(iter)
{

}

template <typename T>
typename MutantStack<T>::iterator & MutantStack<T>::iterator::operator++( void )
{
	++it;
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator++( int )
{
	iterator temp = *this;
	++it;
	return temp;
}

template <typename T>
typename MutantStack<T>::iterator & MutantStack<T>::iterator::operator--( void )
{
	--it;
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator--( int )
{
	iterator temp = *this;
	--it;
	return temp;
}


template <typename T>
bool	MutantStack<T>::iterator::operator==(const iterator & src) const
{
	return it == src.it;
}

template <typename T>
bool	MutantStack<T>::iterator::operator!=(const iterator & src) const
{
	return it != src.it;
}

template <typename T>
T & MutantStack<T>::iterator::operator * ( void )
{
	return *it;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin( void )
{
	return iterator(this->_stack.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end( void )
{
	return iterator(this->_stack.end());
}

template <typename T>
bool	MutantStack<T>::empty( void ) const
{
	return this->_stack.empty();
}

template <typename T>
size_t	MutantStack<T>::size( void ) const
{
	return this->_stack.size();
}

template <typename T>
void	MutantStack<T>::push( const T & value )
{
	return this->_stack.push(value);
}

template <typename T>
void	MutantStack<T>::pop( void )
{
	return this->_stack.pop();
}

template <typename T>
T &	MutantStack<T>::top( void )
{
	return this->_stack.top();
}

#endif // MUTANTSTACK_TPP

/*
//--- Orthodox Canonical Form ---//
MutantStack::MutantStack( void ) 
{
	// std::cout << "Default constructor called" << std::endl;
}

MutantStack::MutantStack( unsigned int N ): _max(N) 
{
	// std::cout << "Constructor called" << std::endl;
}

MutantStack::MutantStack( MutantStack const & src ) 
{
	// std::cout << "Copy constructor called" << std::endl;
	if (this != &src)
		*this = src;
}

MutantStack::~MutantStack( void )
{
	// std::cout << "Destructor called" << std::endl;
}

MutantStack & MutantStack::operator=(const MutantStack & src)
{
	// std::cout << "AForm assignment operator overload called." << std::endl;
	this->_max = src._max;
    // to copy the vector, is it enough???
	this->_numbers = src._numbers;
	return (*this);
}
//--- Orthodox Canonical Form ---//


void	MutantStack::addNumber( const int element )
{
	if (this->_numbers.size() >= this->_max)
		throw std::out_of_range("Maximum number of elements reached");
	this->_numbers.push_back(element);
}

int		MutantStack::shortestMutantStack( void )
{
	if (this->_numbers.size() <= 1)
		throw std::logic_error("There is no enough elements");
	std::sort(this->_numbers.begin(), this->_numbers.end());
	int ret = std::numeric_limits<int>::max();
	for (size_t i = 1; i < this->_numbers.size(); ++i)
	{
		int MutantStack = this->_numbers[i] - this->_numbers[i - 1];
		ret = std::min(ret, MutantStack);
	}
	return ret;
}

int		MutantStack::longestMutantStack( void )
{
	if (this->_numbers.size() <= 1)
		throw std::logic_error("There is no enough elements");
	std::sort(this->_numbers.begin(), this->_numbers.end());
	return this->_numbers[_numbers.size() - 1] - this->_numbers[0];
}
*/
