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
	Point	a( 1, 2 );
	Point	b( 5, 6 );
	Point	c( 8, 1 );
	Point	point( 5, 5 );
	
	if (bsp(a, b, c, point) == 0)
		std::cout << "It's out of the triangle!" << std::endl;
	else
		std::cout << "It's inside of the triangle!" << std::endl;
	return 0;
}
