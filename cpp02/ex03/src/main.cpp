/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/09/05 14:46:40 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point );

void	printResult(int bsp)
{
	if (bsp == 0)
		std::cout << RED << "It's out of the triangle!" << CLEAR <<  std::endl;
	else
		std::cout << BLUE << "It's inside of the triangle!" << CLEAR << std::endl;
}

int	main(void)
{
	std::cout << GREEN << "=== TEST1 ===" << CLEAR << std::endl;
	Point	a( 1, 2 );
	Point	b( 5, 6 );
	Point	c( 8, 1 );
	Point	point( 5, 5 );

	printResult(bsp(a, b, c, point));

	std::cout << GREEN << "=== TEST2 ===" << CLEAR << std::endl;
	Point	d( 1, 2 );
	Point	e( -2, 6 );
	Point	f( 8, 10 );
	Point	point2( 8, 10 );

	printResult(bsp(d, e, f, point2));

	std::cout << GREEN << "=== TEST3 ===" << CLEAR << std::endl;
	Point	x( 1, 2 );
	Point	y( 5, 6 );
	Point	z( 8, 1 );
	Point	point3( -5, -5 );

	printResult(bsp(x, y, z, point3));

	return 0;
}


// int	main(void)
// {
// 	std::cout << GREEN << "=== MORE TEST1 ===" << CLEAR << std::endl;
// 	Point	a( 7, 7 );
// 	Point	b( 11, 1 );
// 	Point	c( 2, 2 );
// 	Point	point( 7, 3 );
// 	printResult(bsp(a, b, c, point));

// 	std::cout << GREEN << "=== MORE TEST2 ===" << CLEAR << std::endl;
// 	Point	d( -7, -7 );
// 	Point	e( 11, 1 );
// 	Point	f( 2, 2 );
// 	Point	point2( 7, 3 );
// 	printResult(bsp(d, e, f, point2));

// 	std::cout << GREEN << "=== MORE TEST3 ===" << CLEAR << std::endl;
// 	Point	x( -7, -7 );
// 	Point	y( 11, 1 );
// 	Point	z( 2, 2 );
// 	Point	point3( 3, 3 );
// 	printResult(bsp(x, y, z, point3));
	
// 	std::cout << GREEN << "=== MORE TEST4 ===" << CLEAR << std::endl;
// 	Point	h( 7, 7 );
// 	Point	i( 11, 1 );
// 	Point	j( 2, 2 );
// 	Point	point4( 5, 4.5f );
// 	printResult(bsp(h, i, j, point4));

// 	std::cout << GREEN << "=== MORE TEST5 ===" << CLEAR << std::endl;
// 	Point	l( -7, 7 );
// 	Point	m( 7, 7 );
// 	Point	n( 7, 7 );
// 	Point	point5( 7, 7 );
// 	printResult(bsp(l, m, n, point5));
	
// 	return 0;
// }
