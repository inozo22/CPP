/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:24:24 by nimai             #+#    #+#             */
/*   Updated: 2023/11/30 17:16:46 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "colors.h"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Base * generate( void )
{
	int	rnb = std::rand() % 3;
	switch (rnb)
	{
		case 0:
			std::cout << "Generated: \"A\"";
			return (new A);
		case 1:
			std::cout << "Generated: \"B\"";
			return (new B);
		case 2:
			std::cout << "Generated: \"C\"";
			return (new C);
	}
	return (NULL);
}

void	identify( Base * ptr )
{
	std::cout << "Pointer identifying: This is ";
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
	std::cout << "Reference identifying: This is ";
	try
	{
		(void)(dynamic_cast<A &>(ptr));
		std::cout << GREEN "A" RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		(void)(dynamic_cast<B &>(ptr));
		std::cout << GREEN "B" RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		(void)(dynamic_cast<C &>(ptr));
		std::cout << GREEN "C" RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main( void )
{
	Base * ptr;
	std::srand( std::time(NULL) );
	
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
		
		ptr = generate();
		std::cout << ", ";
		identify(ptr);
		std::cout << ", ";
		identify(*ptr);
		delete (ptr);
		std::cout << std::endl;
	}
	return (0);
}

