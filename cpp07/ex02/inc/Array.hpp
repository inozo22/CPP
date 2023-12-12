/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:00:17 by nimai             #+#    #+#             */
/*   Updated: 2023/12/05 09:01:39 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class	Array
{
	private:
			T *				_array;
			unsigned int	_size;

	public:
			Array( void )
			{
				_array = NULL;
				_size = 0;
			}
			Array( unsigned int num )
			{
				_array = new T[num];
				_size = num;
			}
			Array( Array const & src )
			{
				_array = new T[src._size];
				_size = src._size;
				for (unsigned int i = 0; i < this->_size; i++)
					this->_array[i] = src._array[i];
			}
			~Array( void )
			{
				delete[] _array;
			}

			Array & operator=( const Array &src )
			{
				if (this = &src)
					return (*this);
				if (this->_size != src._size)
				{
					delete[] _array;
					this->_size = src._size;
					this->_array = new T[this->_size];
				}
				for (unsigned int i = 0; i < this->_size; i++)
					this->_array[i] = src._array[i];
				return (*this);
			}

			T &	operator[](unsigned int i)
			{
				if (i >= this->_size)
					throw(Exception());
				return (this->_array[i]);
			}

			class Exception : public std::exception
			{
				public:
						virtual const char * what( void ) const throw()
						{
							return ("I got exception");
						}
			};

			unsigned int	getSize( void ) const
			{
				return (this->_size);
			}
};

template <typename T>
std::ostream & operator<<(std::ostream &os, Array<T> &obj)
{
	for (unsigned int i = 0; i < obj.getSize(); ++i)
	{
		os << obj[i];
	}
	return (os);
}


#endif
