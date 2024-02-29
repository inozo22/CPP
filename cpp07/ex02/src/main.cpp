/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:00:34 by nimai             #+#    #+#             */
/*   Updated: 2024/02/29 17:02:12 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <cstdlib>

//#define MAX_VAL 750
#define MAX_VAL 10

int	main( void )
{
	Array<int> numbers(MAX_VAL);
	int* mirrar = new int[MAX_VAL];
	Array<int> tmp;
	std::srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = std::rand();
		numbers[i] = value;
		mirrar[i] = value;
	}
	std::cout << CYAN "print numbers:\n" RESET << numbers  << std::endl;
	std::cout << CYAN "print tmp(should be empty):\n" RESET << tmp << std::endl;
	std::cout << CYAN "print mirrar:\n" RESET; 
	::print(mirrar, MAX_VAL);
//check if the copies works well
	/* Array<int>  */tmp = numbers;
	Array<int> test(tmp);
	std::cout << CYAN "print tmp (assignment overload operator):\n" RESET << tmp << std::endl; 
	std::cout << CYAN "print test (Copy constructor):\n" RESET << test << std::endl; 
//check if there is defference between mirrar and numbers
	std::cout << CYAN "check if there is defference between mirrar and numbers:" RESET << std::endl; 
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirrar[i] != numbers[i])
		{
			std::cerr << "Value diferent" << std::endl;
			return (1);
		}
	}
	std::cout << GREEN "OK" RESET << std::endl;
	std::cout << CYAN "Change index 2 value  to 100 in numbers:" RESET << std::endl;
	try
	{
		numbers[2] = 100;
	}
	catch( const std::exception & e)
	{
		std::cerr << e.what() << "\n";
	}
	std::cout << CYAN "print numbers:\n" RESET << numbers << std::endl;
	std::cout << CYAN "Change index -200 value in numbers:" RESET << std::endl;
	try
	{
		numbers[-200] = 0;
	}
	catch( const std::exception & e)
	{
		std::cerr << e.what() << "\n";
	}
	std::cout << CYAN "Change index MAX_VAL value in numbers:"  RESET<< std::endl;
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch( const std::exception & e)
	{
		std::cerr << e.what() << "\n";
	}
	std::cout << std::endl;
	std::cout << CYAN "print mirrar:\n" RESET; 
	::print(mirrar, MAX_VAL);
	std::cout << CYAN "print numbers:\n" RESET << numbers << std::endl;
	std::cout << CYAN "print tmp (assignment overload operator):\n" RESET << tmp  << std::endl;
	std::cout << CYAN "print test (Copy constructor):\n" RESET << test << std::endl;
	std::cout << CYAN "Change all value in numbers:" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = std::rand();
	}
	std::cout << CYAN "Change all value in tmp:" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		tmp[i] = std::rand();
	}
	std::cout << CYAN "Change all value in test:" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		test[i] = std::rand();
	}
	std::cout << std::endl << CYAN "print mirrar:(which shouldn't changed)\n" RESET; 
	::print(mirrar, MAX_VAL);
	std::cout << CYAN "print numbers:\n" RESET << numbers << std::endl;
	std::cout << CYAN "print tmp (assignment overload operator):\n" RESET << tmp  << std::endl;
	std::cout << CYAN "print test (Copy constructor):\n" RESET << test << std::endl;
	std::cout << "numbers size: " << numbers.size() << std::endl;
	std::cout << "tmp size: " << tmp.size() << std::endl;
	std::cout << "test size: " << test.size() << std::endl;

	delete[] mirrar;
	return (0);
}
