/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:02:27 by nimai             #+#    #+#             */
/*   Updated: 2023/12/13 15:35:05 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <algorithm>
# include <stack>
# include <stdexcept>

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

//# define MAX_N 750

/* template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
    typedef typename Container::iterator iterator;

    iterator begin() {
        return this->c.begin();
    }

    iterator end() {
        return this->c.end();
    }
};*/

template <typename T>
class MutantStack
{
	private:
		std::stack<T>	_stack;
	public:
/*		MutantStack( void );
		MutantStack( unsigned int N );
		MutantStack( MutantStack const &src );
		~MutantStack();

		MutantStack & operator=( const MutantStack & src );*/

//		typedef typename std::stack<T>::container_type container_type;
//		typedef typename std::stack<T>::value_type value_type;
//		typedef typename std::stack<T>::size_type size_type;

//Iterator for MutantStack
		class iterator
		{
			private:
					typename std::stack<T>::container_type::iterator it;
			public:
					iterator(typename std::stack<T>::container_type::iterator iter);
					iterator & operator++( void );
					iterator operator++( int );
					iterator & operator--( void );
					iterator operator--( int );
					bool	operator==(const iterator & src) const;
					bool	operator!=(const iterator & src) const;
					T & operator * ( void );
		};

//Functions to make MutantStack iterable
		iterator begin( void );
		iterator end( void );

//Other member functions to mimic std::stack
		bool	empty( void ) const;
		size_t	size( void ) const;
		void	push( const T& value );
		void 	pop( void );
		T & 	top( void );

//		void	addNumber( const int element );
//		int		shortestMutantStack( void );
//		int		longestMutantStack( void );

//		template <typename T>
//		void	addMultipulNumber(T begin, T end)
//		{
//			unsigned int	spaceLeft = _max - _numbers.size();
//			unsigned int	inputSize = std::distance(begin, end);
//			if (inputSize > spaceLeft)
//			{
//				throw std::overflow_error("Not enough space left.");
//			}
//			_numbers.insert(_numbers.end(), begin, end);
//		}
};

# include "MutantStack.tpp"
#endif
