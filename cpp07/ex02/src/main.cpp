/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:00:34 by nimai             #+#    #+#             */
/*   Updated: 2024/03/01 13:45:46 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <cstdlib>

// #define MAX_VAL 750
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
///////print whole array
	std::cout << CYAN "print numbers:\n" RESET << numbers  << std::endl;
	std::cout << CYAN "print tmp(should be empty):\n" RESET << tmp << std::endl;
	std::cout << CYAN "print mirrar:\n" RESET; 
	::print(mirrar, MAX_VAL);
///////print whole array

//check if the copies works well
	std::cout << YELLOW "\ncheck if the copies works well:" RESET << std::endl; 
	tmp = numbers;
	Array<int> test(tmp);
	
///////print whole array
	std::cout << CYAN "print tmp (assignment overload operator):\n" RESET << tmp << std::endl; 
	std::cout << CYAN "print test (Copy constructor):\n" RESET << test << std::endl;
///////print whole array

//---check if the copies works well---//
//check if there is defference between mirrar and numbers
	std::cout << YELLOW "\ncheck if there is defference between mirrar and numbers:" RESET << std::endl; 
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirrar[i] != numbers[i])
		{
			std::cerr << "Value diferent" << std::endl;
			return (1);
		}
	}
	std::cout << GREEN "OK" RESET << std::endl;
	std::cout << YELLOW "check if there is defference between mirrar and tmp:" RESET << std::endl; 
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirrar[i] != tmp[i])
		{
			std::cerr << "Value diferent" << std::endl;
			return (1);
		}
	}
	std::cout << GREEN "OK" RESET << std::endl;
	std::cout << YELLOW "check if there is defference between mirrar and test:" RESET << std::endl; 
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirrar[i] != test[i])
		{
			std::cerr << "Value diferent" << std::endl;
			return (1);
		}
	}
	std::cout << GREEN "OK" RESET << std::endl;
//check if there is defference between mirrar and numbers

//try to access to index
	std::cout << YELLOW "Change index 2 value  to 100 in numbers:" RESET << std::endl;
	try
	{
		numbers[2] = 100;
	}
	catch( const std::exception & e)
	{
		std::cerr << e.what() << "\n";
	}
	std::cout << CYAN "print numbers[2]: " RESET << numbers[2] << std::endl;

///////print whole array
	std::cout << CYAN "print numbers:\n" RESET << numbers << std::endl;
///////print whole array

	std::cout << YELLOW "Change index -200 value in numbers:" RESET << std::endl;
	try
	{
		numbers[-200] = 0;
	}
	catch( const std::exception & e)
	{
		std::cerr << e.what() << "\n";
	}
	std::cout << YELLOW "Change index MAX_VAL value in numbers:"  RESET<< std::endl;
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch( const std::exception & e)
	{
		std::cerr << e.what() << "\n";
	}
//try to access to index

///////print whole array
	std::cout << CYAN "\nprint mirrar:\n" RESET; 
	::print(mirrar, MAX_VAL);
	std::cout << CYAN "print numbers:\n" RESET << numbers << std::endl;
	std::cout << CYAN "print tmp (assignment overload operator):\n" RESET << tmp  << std::endl;
	std::cout << CYAN "print test (Copy constructor):\n" RESET << test << std::endl;

	std::cout << YELLOW "Change all value in numbers:" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = std::rand();
	}
	std::cout << YELLOW "Change all value in tmp:" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		tmp[i] = std::rand();
	}
	std::cout << YELLOW "Change all value in test:" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		test[i] = std::rand();
	}
	std::cout << CYAN "print mirrar:(which shouldn't changed)\n" RESET; 
	::print(mirrar, MAX_VAL);
	std::cout << CYAN "print numbers:\n" RESET << numbers << std::endl;
	std::cout << CYAN "print tmp (assignment overload operator):\n" RESET << tmp  << std::endl;
	std::cout << CYAN "print test (Copy constructor):\n" RESET << test << std::endl;
///////print whole array

//check size() function
	std::cout << YELLOW "\ncheck size() funstion:" RESET << std::endl; 
	std::cout << "numbers size: " << numbers.size() << std::endl;
	std::cout << "tmp size: " << tmp.size() << std::endl;
	std::cout << "test size: " << test.size() << std::endl;

	delete[] mirrar;
	return (0);
}
