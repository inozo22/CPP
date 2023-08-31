/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:08:19 by nimai             #+#    #+#             */
/*   Updated: 2023/08/30 12:45:11 by nimai            ###   ########.fr       */
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
# include <cmath>

class Fixed {

private:
	int	_value;
	static const int	_bits = 8;
public:

	Fixed( void );
	Fixed( const int num );
	Fixed( const float numf );
	~Fixed( void );
	Fixed( const Fixed &src );
	Fixed & operator = ( const Fixed &src );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int 	toInt( void )const;

};

//std::ostream& operator<<(std::ostream &out, Fixed const &src);

#endif
