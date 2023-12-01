/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:45:49 by nimai             #+#    #+#             */
/*   Updated: 2023/12/01 15:29:46 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iomanip>
#include <iostream>
#include <cmath>
#include <string>

void	intSumFive( int & num )
{
	num += 5;
}

void	doubleRound( double & num )
{
	num = ::round(num);
}

void	charUpper( char & c )
{
	c = std::toupper(c);
}

void	strAddWan( std::string & str )
{
	str += "_WAN!";
}

int	main( void )
{
	std::cout << GREEN << std::setfill('=') << std::setw(25) << ">>> ITER TEST" << RESET << std::endl;
	{		
		//if you want to check how works with empty array, the pedantic should be desabled
		std::cout << CYAN << std::setfill('=') << std::setw(25) << ">>> Empty arrays" << RESET << std::endl << std::endl;
		int		intArray[ ] = {};
		char	charArray[] = {};
		double	doubleArray[] = {};
		float	floatArray[] = {};
		size_t	len = 0;
	
		std::cout << "\tEmpty int: ";
		::print<int>(intArray, len);
		std::cout << std::endl;
		std::cout << "\tEmpty char: ";
		::print<char>(charArray, len);
		std::cout << std::endl;
		std::cout << "\tEmpty double: ";
		::print<double>(doubleArray, len);
		std::cout << std::endl;
		std::cout << "\tEmpty float: ";
		::print<float>(floatArray, len);
		std::cout << std::endl << std::endl;
	}
	{		
		std::cout << CYAN << std::setfill('=') << std::setw(25) << ">>> Int array test" << RESET << std::endl << std::endl;
		int		intArray[] = {0, 1, 2, 55, 3, 4, 5, 6, 7, 8};
		size_t	len = 10;
	
		std::cout << "\tInt: Original ";
		::print<int>(intArray, len);

		::iter(intArray, len, ::intSumFive);

		std::cout << std::endl;
		std::cout << "\tInt: After iter ";
		::print<int>(intArray, len);
		std::cout << std::endl << std::endl;
	}
	// {		
	// 	std::cout << CYAN << std::setfill('=') << std::setw(25) << ">>> Float array test" << RESET << std::endl << std::endl;
	// 	float	floatArray[] = {0.1f, 1.2f, 2.3f, 55.4f, 3.5f, 4.60f, 5.7f, 6.8f, 7.0f, 8.0f};
	// 	size_t	len = 10;

	// 	std::cout << "\tFloat: Original ";
	// 	::print<float>(floatArray, len);
	

	// 	::iter(floatArray, len, ::intSumFive);

	// 	std::cout << "\tFloat: After iter ";
	// 	::print<float>(floatArray, len);
	// 	std::cout << std::endl << std::endl;
	// }
	{		
		std::cout << CYAN << std::setfill('=') << std::setw(25) << ">>> Double array test" << RESET << std::endl << std::endl;
		double	doubleArray[] = {0.01, 1.20, 2.3, 55.4, 3.5, 4.670, 5.8, 6.9, 7.090, 8.0};
		size_t	len = 10;

		std::cout << "\tDouble: Original";
		::print<double>(doubleArray, len);


		::iter(doubleArray, len, ::doubleRound);
		std::cout << std::endl;	
		std::cout << "\tDouble: After iter ";
		::print<double>(doubleArray, len);
		std::cout << std::endl << std::endl;
	}
	{		
		std::cout << CYAN << std::setfill('=') << std::setw(25) << ">>> Char array test" << RESET << std::endl << std::endl;
		char	charArray[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
		size_t	len = 10;
	
		std::cout << "\tChar: Original";
		::print<char>(charArray, len);
	
		::iter(charArray, len, ::charUpper);

		std::cout << std::endl;
		std::cout << "\tChar: After iter ";
		::print<char>(charArray, len);
		std::cout << std::endl << std::endl;
	}
	{		
		std::cout << CYAN << std::setfill('=') << std::setw(25) << ">>> String array test" << RESET << std::endl << std::endl;
		std::string	stringArray[] = {"Hello", "Hola", "Kaixo", "Konnichiwa", "Ciao", "Bonjour", "Privyet", "Hallo", "Oi", "Hoi"};
		size_t	len = 10;

		std::cout << "\tString: Original";
		::print<std::string>(stringArray, len);

		::iter(stringArray, len, ::strAddWan);

		std::cout << std::endl;
		std::cout << "\tString: After iter ";
		::print<std::string>(stringArray, len);
		std::cout << std::endl << std::endl;
	}

	
	return (0);
}



	// int a = 2;
	// int b = 3;

	// ::swap( a, b );
	// std::cout << "a = " << a << ", b = " << b << std::endl;
	// std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	// std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	// std::string c = "chaine1";
	// std::string d = "chaine2";
	// ::swap( c, d );
	// std::cout << "c = " << c << ", d = " << d << std::endl;
	// std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	// std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	// return 0;
