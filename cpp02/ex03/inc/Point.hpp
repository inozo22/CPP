/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:08:19 by nimai             #+#    #+#             */
/*   Updated: 2023/09/04 15:58:19 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_HPP__
# define __POINT_HPP__

# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define RED "\033[1;31m"
# define CYAN "\033[1;36m"
# define GREEN "\033[1;32m"
# define CLEAR "\033[0m"
# define UTEST "TEST"
# define LTEST "test"

# include <iostream>
# include <cmath>
# include "Fixed.hpp"

class Point 
{

private:
	const Fixed	_x;
	const Fixed	_y;
	//anything else useful
public:

	Point( void );
	Point( const float x, const float y );
	~Point( void );
	Point( const Point &src );
	Point &operator=( const Point &src );

	Fixed	getX( void ) const;
	Fixed	getY( void ) const;
	//anything else useful
};

#endif
