/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:00:17 by nimai             #+#    #+#             */
/*   Updated: 2024/02/29 22:21:25 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

//===Color font code===/
# define BLACK   "\x1B[30m"
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define WHITE   "\x1B[37m"
# define ORANGE  "\x1B[38;2;255;128;0m"
# define ROSE    "\x1B[38;2;255;151;203m"
# define LBLUE   "\x1B[38;2;53;149;240m"
# define LGREEN  "\x1B[38;2;17;245;120m"
# define GRAY    "\x1B[38;2;176;174;174m"
# define RESET   "\x1b[0m"

template <typename T>
class	Array
{
	private:
			T *				_array;
			unsigned int	_size;

	public:
			Array( void ): _array(NULL), _size(0) {};
//			Array( unsigned int n ): _array(new T[n]), _size(n) {};
			Array( unsigned int n ): _array(new (std::nothrow) T[n]), _size(n) {};
			Array( Array const & src )
			{
	//			_array = new T[src._size];
				_array = new (std::nothrow) T[src._size];
				_size = src._size;
				for (unsigned int i = 0; i < this->_size; i++)
					this->_array[i] = src._array[i];
			}
			~Array( void ) {delete[] _array;};

			Array & operator=( const Array &src )
			{
				if (this == &src)
					return (*this);
				if (this->_size != src._size)
				{
					delete[] _array;
					this->_size = src._size;
	//				this->_array = new T[this->_size];
					this->_array = new (std::nothrow) T[this->_size];
				}
				for (unsigned int i = 0; i < this->_size; i++)
					this->_array[i] = src._array[i];
				return (*this);
			}

			T &	operator[](unsigned int i)
			{
				if (i >= this->_size)
					throw(OutRangeException());
				return (this->_array[i]);
			}

			class OutRangeException : public std::exception
			{
				public:
						virtual const char * what( void ) const throw()
						{
							return ("Index is out of range");
						}
			};
			unsigned int	size() const
			{
				return this->_size;
			};
};

template <typename T>
std::ostream & operator<<(std::ostream &os, Array<T> &obj)
{
	for (unsigned int i = 0; i < obj.size(); ++i)
	{
		os << obj[i];
		if ((i + 1) != obj.size())
			os << ", ";
	}
	return (os);
}

template <typename T>
void	print(T * array, unsigned int len)
{
	for (unsigned int i = 0; i < len; i++)
	{
		std::cout << array[i];
		if ((i + 1 != len))
			std::cout << ", ";
		else
			std::cout << std::endl;
	}
}

#endif
