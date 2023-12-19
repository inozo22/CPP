/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:08:19 by nimai             #+#    #+#             */
/*   Updated: 2023/12/19 13:51:42 by nimai            ###   ########.fr       */
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

class Fixed
{
	private:
			int	_value;
			static const int	_bits = 8;
	public:
			Fixed( void );
			~Fixed( void );
			Fixed( const Fixed &fixed );
			Fixed & operator = ( const Fixed &fixed );

			int		getRawBits( void ) const;
			void	setRawBits( int const raw );

};

#endif
