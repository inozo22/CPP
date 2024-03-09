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

//--- Orthodox Canonical Form ---//
template <typename T>
MutantStack<T>::MutantStack( void ) : std::stack<T>()
{

}

template <typename T>
MutantStack<T>::MutantStack( MutantStack<T> const &src ) : std::stack<T>(src)
{

}

template <typename T>
MutantStack<T>::~MutantStack( void )
{

}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=( const MutantStack<T> & src )
{
	if (this != &src)
	{
		MutantStack<T> tmp(src);
		std::swap(*this, tmp);
	}
	return *this;
}
//--- Orthodox Canonical Form ---//

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin( void )
{
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end( void )
{
    return this->c.end();
}

#endif // MUTANTSTACK_TPP
