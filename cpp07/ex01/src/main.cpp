/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:45:49 by nimai             #+#    #+#             */
/*   Updated: 2024/02/29 09:30:47 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
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
/* 	std::cout << GREEN << std::setfill('=') << std::setw(25) << ">>> ITER TEST" << RESET << std::endl;
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
	} */
	{		
		std::cout << CYAN << std::setfill('=') << std::setw(25) << ">>> Int array test" << RESET << std::endl << std::endl;
		int		intArray[] = {0, 1, 2, 55, 3, 4, 5, 6, 7, 8};
		size_t	len = sizeof(intArray) / sizeof(int);
	
		std::cout << "\tOriginal Int array: ";
		::iter(intArray, len, ::printElement);
		::iter(intArray, len, ::sumFive<int>);
		std::cout << std::endl;
	
		std::cout << "\tAfter iter sumFive: ";
		::iter(intArray, len, ::printElement);
		std::cout << std::endl << std::endl;
	}
	{		
		std::cout << CYAN << std::setfill('=') << std::setw(25) << ">>> Double array test" << RESET << std::endl << std::endl;
		double	doubleArray[] = {0.01, 1.20, 2.3, 55.4, 3.5, 4.670, 5.8, 6.9, 7.090, 8.0};
		size_t	len = sizeof(doubleArray) / sizeof(double);

		std::cout << "\tOriginal Double array: ";
		::iter(doubleArray, len, ::printElement);
		::iter(doubleArray, len, ::sumFive<double>);

//		::iter(doubleArray, len, ::doubleRound);
		std::cout << std::endl;	
		std::cout << "\tAfter iter sumFive: ";
		::iter(doubleArray, len, ::printElement);
		std::cout << std::endl << std::endl;
	}
	{		
		std::cout << CYAN << std::setfill('=') << std::setw(25) << ">>> Char array test" << RESET << std::endl << std::endl;
		char	charArray[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
		size_t	len = sizeof(charArray) / sizeof(char);
	
		std::cout << "\tOriginal Char array: ";
		::iter(charArray, len, ::printElement);
		::iter(charArray, len, ::charUpper);
		std::cout << std::endl;
	
		std::cout << "\tAfter iter charUpper: ";
		::iter(charArray, len, ::printElement);
		std::cout << std::endl << std::endl;
	}
	{		
		std::cout << CYAN << std::setfill('=') << std::setw(25) << ">>> String array test" << RESET << std::endl << std::endl;
		std::string	stringArray[] = {"Hello", "Hola", "Kaixo", "Konnichiwa", "Ciao", "Bonjour", "Privyet", "Hallo", "Oi", "Hoi"};
		size_t	len = sizeof(stringArray) / sizeof(std::string);

		std::cout << "\tOriginal String array: ";
		::iter(stringArray, len, ::printElement);
		::iter(stringArray, len, ::strAddWan);
		std::cout << std::endl;
	
		std::cout << "\tAfter iter strAddWan: ";
		::iter(stringArray, len, ::printElement);
		std::cout << std::endl << std::endl;
	}

	
	return (0);
}
