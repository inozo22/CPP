/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/12/20 14:10:55 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// int	main(void)
// {
// 	std::cout << GREEN ">>>>>>>>>> SUBJECT TEST <<<<<<<<<<" CLEAR << std::endl;
// 	Fixed		a;
// 	Fixed const	b( 10 );
// 	Fixed const	c( 42.42f );
// 	Fixed const	d( b );

// 	a = Fixed( 1234.4321f );

// 	std::cout << "a is " << a << std::endl;
// 	std::cout << "b is " << b << std::endl;
// 	std::cout << "c is " << c << std::endl;
// 	std::cout << "d is " << d << std::endl;
	
// 	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
// 	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
// 	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
// 	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

// 	return 0;
// }

int	main(void)
{
	std::cout << GREEN ">>>>>>>>>> MY TEST <<<<<<<<<<" CLEAR << std::endl;
	Fixed		a;
	Fixed const	b( 10 );
	Fixed const	c( 12789456.0f );
	Fixed const	d( b );

	std::cout << BLUE "pointer: " CLEAR<< std::endl; 
	std::cout << "a: " << &a << ": " << a << std::endl; 
	std::cout << "b: " << &b << ": " << b << std::endl; 
	std::cout << "c: " << &c << ": " << c << std::endl; 
	std::cout << "d: " << &d << ": " << d << std::endl; 

	a = Fixed( 789.4f );
	std::cout << "a: " << &a << std::endl; 

	// a = Fixed( 20.56f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << BLUE "pointer: " CLEAR<< std::endl; 
	std::cout << "a: " << &a << ": " << a << std::endl; 
	std::cout << "b: " << &b << ": " << b << std::endl; 
	std::cout << "c: " << &c << ": " << c << std::endl; 
	std::cout << "d: " << &d << ": " << d << std::endl; 
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl;

	return 0;
}
