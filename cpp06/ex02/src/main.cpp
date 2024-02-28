/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:24:24 by nimai             #+#    #+#             */
/*   Updated: 2024/02/28 15:42:57 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "colors.h"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Dammy.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Base * generate( void )
{
	int	rnb = std::rand() % 3;
	switch (rnb)
	{
		case 0:
			std::cout << "Generated: \"A\"" << std::endl;
			return (new A);
		case 1:
			std::cout << "Generated: \"B\""<< std::endl;
			return (new B);
		case 2:
			std::cout << "Generated: \"C\""<< std::endl;
			return (new C);
	}
	std::cout <<  "Generated: \"Nothing\""<< std::endl;
	return (NULL);
}

void	identify( Base * ptr )
{
	std::cout << "Pointer identifying: ";
	if (dynamic_cast<A *>(ptr))
		std::cout << GREEN "A" RESET << std::endl;
	else if (dynamic_cast<B *>(ptr))
		std::cout << GREEN "B" RESET << std::endl;
	else if (dynamic_cast<C *>(ptr))
		std::cout << GREEN "C" RESET << std::endl;
	else
		std::cout <<RED "UNKNOWN" RESET << std::endl;
}

void	identify( Base & ptr )
{
	std::cout << "Reference identifying: ";
	try
	{
		dynamic_cast<A &>(ptr);
		std::cout << GREEN "A" RESET;
	}
	catch(const std::exception& e)
	{
		//std::cerr << e.what() << '\n';
	}
	try
	{
		dynamic_cast<B &>(ptr);
		std::cout << GREEN "B" RESET;
	}
	catch(const std::exception& e)
	{
		//std::cerr << e.what() << '\n';
	}
	try
	{
		dynamic_cast<C &>(ptr);
		std::cout << GREEN "C" RESET;
	}
	catch(const std::exception& e)
	{
		//std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}

int	main( void )
{
	std::srand( std::time(0) );

	for (int i = 1; i < 11; i++)
	{
		if (i == 1)
			std::cout << i << "st Test\n"; 
		else if (i == 2)
			std::cout << i << "nd Test\n";
		else if (i == 3)
			std::cout << i << "rd Test\n";
		else
			std::cout << i << "th Test\n";
		
		Base * ptr = generate();
		Base & ref = *ptr;

		identify(ptr);
		identify(ref);
		delete (ptr);
		std::cout << std::endl;
	}
	return (0);
}

