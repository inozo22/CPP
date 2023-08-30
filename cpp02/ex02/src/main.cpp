/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/08/30 17:54:05 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed		a;
//	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "aaa" << std::endl;
	std::cout << "bbb" << std::endl;
//	std::cout << a.getRawBits() << std::endl;
	// a.setRawBits(47);
	// std::cout << a.getRawBits() << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
//	std::cout << --a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;

	// std::cout << b << std::endl;

	// std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}


//main official
// int	main(void)
// {
// 	Fixed		a;
// 	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;

// 	std::cout << b << std::endl;

// 	std::cout << Fixed::max( a, b ) << std::endl;

// 	return 0;
// }
