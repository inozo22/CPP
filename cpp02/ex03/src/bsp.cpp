/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:16:31 by nimai             #+#    #+#             */
/*   Updated: 2023/09/04 16:40:42 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

//double Area = 0.5 *(-p1y*p2x + p0y*(-p1x + p2x) + p0x*(p1y - p2y) + p1x*p2y);

/* Fixed	getArea( Point const point, Point const a, Point const b, Point const c )
{
	(void)point;
	Fixed	ret;
	ret._value = 0.5 * (-(b.getY()) * c.getX() + a.getY() * (-(b.getX()) + c.getX()) + \
	a.getX() * (b.getY() - c.getY()) + b.getX() * c.getY());
	return (ret);
} */
Fixed	getArea( Point const point, Point const a, Point const b, Point const c )
{
	(void)point;
	Fixed const ret ( (Fixed)(0.5f * (-(b.getY().toFloat()) * c.getX().toFloat() + a.getY().toFloat() * (-(b.getX().toFloat()) + c.getX().toFloat()) + a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) + b.getX().toFloat() * c.getY().toFloat())));
	std::cout << "area ret: " << ret << std::endl;
	return (ret);
}

//double s = 1/(2*Area)*(p0y*p2x - p0x*p2y + (p2y - p0y)*px + (p0x - p2x)*py);

/* Fixed	getS( Point area, Point const point, Point const a, Point const c )
{
	Fixed	ret;
	ret._value = 1/( 2 * area._x()) * (a.getY().toFloat() * c.getX().toFloat() - a.getX().toFloat() * c.getY().toFloat() + (c.getY().toFloat() - \
	a.getY().toFloat()) * point.getX().toFloat() + (a.getX().toFloat() - c.getX().toFloat() * point.getY().toFloat()));
	return (ret);
} */
Fixed	getS( Fixed area, Point const point, Point const a, Point const c )
{
	Fixed	ret ( (Fixed) 1.00f /( Fixed (2) * area) * (a.getY()/* .toFloat() */ * c.getX()/* .toFloat() */ - a.getX()/* .toFloat() */ * c.getY()/* .toFloat() */ + (c.getY()/* .toFloat() */ - \
	a.getY()/* .toFloat() */) * point.getX()/* .toFloat() */ + (a.getX()/* .toFloat() */ - c.getX()/* .toFloat() */ * point.getY()/* .toFloat() */)));
	std::cout << "s ret: " << ret << std::endl;
	return (ret);
}

//double t = 1/(2*Area)*(p0x*p1y - p0y*p1x + (p0y - p1y)*px + (p1x - p0x)*py);

/* Fixed	getT( Point area, Point const point, Point const a, Point const b )
{
	Fixed	ret;
	ret._value = 1/( 2 * area.toFloat()) * (a.getX().toFloat() * b.getY().toFloat() - a.getY().toFloat() * b.getX().toFloat() + (a.getY().toFloat() - b.getY().toFloat()) * point.getX().toFloat() + (b.getX().toFloat() - a.getX().toFloat()) * point.getY().toFloat());
	return (ret);
} */
Fixed	getT( Fixed area, Point const point, Point const a, Point const b )
{
	Fixed	ret( (Fixed) 1.00f /( Fixed (2) * area) * (a.getX()/* .toFloat() */ * b.getY()/* .toFloat() */ - a.getY()/* .toFloat() */ * b.getX()/* .toFloat() */ + (a.getY()/* .toFloat() */ - b.getY()/* .toFloat() */) * point.getX()/* .toFloat() */ + (b.getX()/* .toFloat() */ - a.getX()/* .toFloat() */) * point.getY()/* .toFloat() */));
	std::cout << "t ret: " << ret << std::endl;
	return (ret);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
//	Point area = getArea( point, a, b, c );
	Fixed area = getArea( point, a, b, c );
	Fixed s = getS( area, point, a, c );
	Fixed t = getT( area, point, a, b );
	Fixed temp = ( Fixed(1) - s - t);

	std::cout << "area: " << area << "	s: " << s << "	t: " << t << std::endl;

	if (((Fixed (0) < s ) && ( s < Fixed(1))) && ((Fixed(0) < t ) && ( t < Fixed(1))) && ((Fixed(0) < temp ) && (temp < Fixed(1))))
		return (true);
	return (false);
}



// float sign (fPoint p1, fPoint p2, fPoint p3)
// {
//     return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
// }
 
// bool PointInTriangle (fPoint pt, fPoint v1, fPoint v2, fPoint v3)
// {
//     bool b1, b2, b3;
 
//     b1 = sign(pt, v1, v2) < 0.0f;
//     b2 = sign(pt, v2, v3) < 0.0f;
//     b3 = sign(pt, v3, v1) < 0.0f;
 
//     return ((b1 == b2) && (b2 == b3));
// }

//(p0x, p0y),(p1x, p1y),(p2x, p2y)の三角形
//(px, py)が判定したい点
// double Area = 0.5 *(-p1y*p2x + p0y*(-p1x + p2x) + p0x*(p1y - p2y) + p1x*p2y);
// double s = 1/(2*Area)*(p0y*p2x - p0x*p2y + (p2y - p0y)*px + (p0x - p2x)*py);
// double t = 1/(2*Area)*(p0x*p1y - p0y*p1x + (p0y - p1y)*px + (p1x - p0x)*py);
 
// if((0 < s < 1) && (0 < t < 1)&&(0<1-s-t<1)){
//     return 1; //Inside Triangle
// }else{
//     return 0;
// }
