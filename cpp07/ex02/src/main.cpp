/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:00:34 by nimai             #+#    #+#             */
/*   Updated: 2023/12/05 09:01:07 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <cstdlib>

#define MAX_VAL 750

int	main( void )
{
	Array<int> numbers(MAX_VAL);
	int* mirrar = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirrar[i] = value;
	}
	//scope
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirrar[i] != numbers[i])
		{
			std::cerr << "Value diferent" << std::endl;
			return (1);
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch( const std::exception & e)
	{
		std::cerr << e.what() << "\n";
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch( const std::exception & e)
	{
		std::cerr << e.what() << "\n";
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete[] mirrar;



	return (0);
}
