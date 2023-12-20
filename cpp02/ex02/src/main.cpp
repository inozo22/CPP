/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/12/20 10:05:08 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <iomanip>

int	main(void)
{
	std::cout << GREEN "\n>>>>>>>>>> MY TEST <<<<<<<<<<\n" CLEAR << std::endl;

	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	// Fixed const	b( Fixed( 2.02f ) );
	// Fixed const	c( Fixed( 2 ) );

	std::cout << std::right << std::setw(13) << "a: " << a << std::endl;
	std::cout << std::right << std::setw(13) << "++a: " << ++a << std::endl;
	std::cout << std::right << std::setw(13) << "a: " << a << std::endl;
	std::cout << std::right << std::setw(13) << "a++: " << a++ << std::endl;
	std::cout << std::right << std::setw(13) << "a: " << a << std::endl;
	std::cout << std::right << std::setw(13) << "--a: " << --a << std::endl;
	std::cout << std::right << std::setw(13) << "a: " << a << std::endl;
	std::cout << std::right << std::setw(13) << "a--: " << a-- << std::endl;
	std::cout << std::right << std::setw(13) << "a: " << a << std::endl;
	std::cout << std::right << std::setw(13) << "b: " << b << std::endl;
	std::cout << std::right << std::setw(13) << "a+b: " << a + b << std::endl;
	std::cout << std::right << std::setw(13) << "a+b+b: " << a + b + b << std::endl;
	std::cout << std::right << std::setw(13) << "a+b+b-b: " << a + b + b - b << std::endl;
	std::cout << std::right << std::setw(13) << "a+b+b-b/b: " << a + b + b - b / b << std::endl;
	std::cout << std::right << std::setw(13) << "a+b+b-b/b*a: " << a + b + b - b / b * a << std::endl;
	a++;
	a = a + b;
	std::cout << std::right << std::setw(13) << "a: " << a << std::endl;
	std::cout << std::right << std::setw(13) << "b: " << b << std::endl;

	if (a > 5)
		std::cout << std::right << std::setw(11) << "> works" << std::endl;
	else
		std::cout << std::right << std::setw(11) << "fail" << std::endl;
	if (b < a)
		std::cout << std::right << std::setw(11) << "< works" << std::endl;
	else
		std::cout << std::right << std::setw(11) << "fail" << std::endl;

	a = b;
	std::cout << std::right << std::setw(13) << "a: " << a << std::endl;
	std::cout << std::right << std::setw(13) << "b: " << b << std::endl;

	if (a >= b)
		std::cout << std::right << std::setw(11) << ">= works" << std::endl;
	else
		std::cout << std::right << std::setw(11) << "fail" << std::endl;
	if (a <= b)
		std::cout << std::right << std::setw(11) << "<= works" << std::endl;
	else
		std::cout << std::right << std::setw(11) << "fail" << std::endl;

	if (a == b)
		std::cout << std::right << std::setw(11) << "== works" << std::endl;
	else
		std::cout << std::right << std::setw(11) << "fail" << std::endl;

	if (a != b)
		std::cout << std::right << std::setw(11) << "fail" << std::endl;
	else
		std::cout << std::right << std::setw(11) << "!= works" << std::endl;
	return 0;
}


//main official(in subject)
// int	main(void)
// {
// 	std::cout << GREEN "\n>>>>>>>>>> SUBJECT TEST <<<<<<<<<<\n" CLEAR << std::endl;

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
