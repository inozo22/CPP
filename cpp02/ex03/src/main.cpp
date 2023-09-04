/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/09/04 16:41:24 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point );


int	main(void)
{
	std::cout << GREEN << "=== TEST1 ===" << CLEAR << std::endl;
	Point	a( 1, 2 );
	Point	b( 5, 6 );
	Point	c( 8, 1 );
	Point	point( 5, 5 );
	
	if (bsp(a, b, c, point) == 0)
		std::cout << "It's out of the triangle!" << std::endl;
	else
		std::cout << BLUE << "It's inside of the triangle!" << CLEAR << std::endl;

	std::cout << GREEN << "=== TEST2 ===" << CLEAR << std::endl;
	Point	d( 1, 2 );
	Point	e( -2, 6 );
	Point	f( 8, 10 );
	Point	point2( 8, 10 );
	
	if (bsp(d, e, f, point2) == 0)
		std::cout << "It's out of the triangle!" << std::endl;
	else
		std::cout << BLUE << "It's inside of the triangle!" << CLEAR << std::endl;

	std::cout << GREEN << "=== TEST3 ===" << CLEAR << std::endl;
	Point	x( 1, 2 );
	Point	y( 5, 6 );
	Point	z( 8, 1 );
	Point	point3( -5, -5 );
	
	if (bsp(x, y, z, point3) == 0)
		std::cout << "It's out of the triangle!" << std::endl;
	else
		std::cout << BLUE << "It's inside of the triangle!" << CLEAR << std::endl;
	return 0;
}
