/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:08:19 by nimai             #+#    #+#             */
/*   Updated: 2023/12/20 09:43:36 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define RED "\033[1;31m"
# define CYAN "\033[1;36m"
# define GREEN "\033[1;32m"
# define CLEAR "\033[0m"
# define UTEST "TEST"
# define LTEST "test"

# include <iostream>

class Fixed
{

	private:
			int	_value;
			static const int	_bits = 8;
	public:
			Fixed( void );
			Fixed( const int num );
			Fixed( const float numf );
			~Fixed( void );
			Fixed( const Fixed &src );
			Fixed &operator=( const Fixed &src );

			int		getRawBits( void ) const;
			void	setRawBits( int const raw );
			float	toFloat( void ) const;
			int 	toInt( void )const;

//The 6 comparison operators: >, <, >=, <=, == and !=
			bool	operator>(const Fixed &src) const;
			bool	operator<(const Fixed &src) const;
			bool	operator>=(const Fixed &src) const;
			bool	operator<=(const Fixed &src) const;
			bool	operator==(const Fixed &src) const;
			bool	operator!=(const Fixed &src) const;

//The 4 arithmetic operators: +, -, *, and /
			Fixed	operator+(const Fixed &src) const;
			Fixed	operator-(const Fixed &src) const;
			Fixed	operator*(const Fixed &src) const;
			Fixed	operator/(const Fixed &src) const;

//The 4 increment/decrement (++i, i++, --i, i--) operators
			Fixed	&operator++( void );
			Fixed	&operator--( void );
			Fixed	operator++( int );
			Fixed	operator--( int );

//overloaded member functions
			static Fixed& min( Fixed &a, Fixed &b );
			static const Fixed& min( const Fixed &a, const Fixed &b );
			static Fixed& max( Fixed &a, Fixed &b );
			static const Fixed& max( const Fixed &a, const Fixed &b );
};

std::ostream& operator<<(std::ostream &out, Fixed const &src);

#endif
