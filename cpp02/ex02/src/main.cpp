/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/09/04 16:42:47 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	// Fixed const	b( Fixed( 2.02f ) );
	// Fixed const	c( Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << a + b << std::endl;
	std::cout << a + b + b << std::endl;
	std::cout << a + b + b - b << std::endl;
	std::cout << a + b + b - b / b << std::endl;
	std::cout << a + b + b - b / b * a << std::endl;
	a++;
	a = a + b;

	if (a > 5)
		std::cout << "> works" << std::endl;
	else
		std::cout << "fail" << std::endl;
	if (b < a)
		std::cout << "< works" << std::endl;
	else
		std::cout << "fail" << std::endl;

	a = b;

	if (a >= b)
		std::cout << ">= works" << std::endl;
	else
		std::cout << "fail" << std::endl;
	if (a <= b)
		std::cout << "<= works" << std::endl;
	else
		std::cout << "fail" << std::endl;

	if (a == b)
		std::cout << "== works" << std::endl;
	else
		std::cout << "fail" << std::endl;

	if (a != b)
		std::cout << "fail" << std::endl;
	else
		std::cout << "!= works" << std::endl;
	return 0;
}


//main official(in subject)
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
