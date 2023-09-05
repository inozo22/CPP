/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:16:31 by nimai             #+#    #+#             */
/*   Updated: 2023/09/05 14:47:46 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Fixed	getArea( Point const point, Point const a, Point const b, Point const c )
{
	(void)point;
	Fixed const ret ( (Fixed)(0.5f * (-(b.getY().toFloat()) * c.getX().toFloat() + a.getY().toFloat() * (-(b.getX().toFloat()) + c.getX().toFloat()) + a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) + b.getX().toFloat() * c.getY().toFloat())));
	std::cout << "area ret: " << ret << std::endl;
	return (ret);
}

Fixed	getS( Fixed area, Point const point, Point const a, Point const c )
{
	Fixed	ret ( (Fixed) 1.00f /( Fixed (2) * area) * (a.getY() * c.getX() - a.getX() * c.getY() + (c.getY() - \
	a.getY()) * point.getX() + (a.getX() - c.getX()) * point.getY()));
	std::cout << "s ret: " << ret << std::endl;
	return (ret);
}

Fixed	getT( Fixed area, Point const point, Point const a, Point const b )
{
	Fixed	ret( (Fixed) 1.00f /( Fixed (2) * area) * (a.getX() * b.getY() - a.getY() * b.getX() + (a.getY() - \
	b.getY()) * point.getX() + (b.getX() - a.getX()) * point.getY()));
	std::cout << "t ret: " << ret << std::endl;
	return (ret);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	Fixed area = getArea( point, a, b, c );
	Fixed s = getS( area, point, a, c );
	Fixed t = getT( area, point, a, b );
	Fixed temp = ( Fixed(1) - s - t);

//	std::cout << "area: " << area << "	s: " << s << "	t: " << t << std::endl;

	if (((Fixed (0) < s ) && ( s < Fixed(1))) && ((Fixed(0) < t ) && ( t < Fixed(1))) && ((Fixed(0) < temp ) && (temp < Fixed(1))))
		return (true);
	return (false);
}
