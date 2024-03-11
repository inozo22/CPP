/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:01:25 by nimai             #+#    #+#             */
/*   Updated: 2024/03/11 14:00:40 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

template <typename T>
void	print(T * array, unsigned int len)
{
	for (unsigned int i = 0; i < len; i++)
	{
		std::cout << array[i];
		if ((i + 1 != len))
			std::cout << ", ";
		else
			std::cout << std::endl;
	}
}

int	main( void )
{
	std::cout << std::endl << CYAN ">>>>>>>>>> TEST with VECTOR <<<<<<<<<<" RESET << std::endl;
	{
		int arr[] = {1, 2, 3, 4, 5};
		//print array
		std::cout << "array: ";
		::print(arr, sizeof(arr) / sizeof(arr[0]));
		//print array
		std::vector<int>	container(arr, arr + sizeof(arr) / sizeof(arr[0]));
		try
		{
			int value = 1;
			std::vector<int>::const_iterator ret = easyfind(container, value);
			std::cout << "Element " BLUE << *ret << RESET " found at index: " GREEN << std::distance<std::vector<int>::const_iterator>(container.begin(), ret) << RESET << std::endl;
		}
		catch (const std::out_of_range& e)
		{
			std::cerr << e.what() << std::endl;
    	}
		try
		{
			int value = 8;
			std::vector<int>::const_iterator ret = easyfind(container, value);
			std::cout << "Element " BLUE << *ret << RESET " found at index: " GREEN << std::distance<std::vector<int>::const_iterator>(container.begin(), ret) << RESET << std::endl;
		}
		catch (const std::out_of_range& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << CYAN ">>>>>>>>>> TEST with VECTOR <<<<<<<<<<\n" RESET << std::endl;
	std::cout << std::endl << YELLOW ">>>>>>>>>> TEST with LIST <<<<<<<<<<" RESET << std::endl;
	{
		std::list<int>	container;
		for (int i = 0; i < 100; i++)
		{
			container.push_front(i);
		}
		std::list<int>::const_iterator ret;
		try
		{
			for (int value = 0; value < 150; value++)
			{
				ret = easyfind(container, value);
				std::cout << "Element " BLUE << *ret << RESET " found at index: " GREEN << std::distance<std::list<int>::const_iterator>(container.begin(), ret) << RESET << std::endl;
			}
		}
		catch (const std::out_of_range& e)
		{
			std::cerr << e.what() << std::endl;
    	}
		try
		{
			int value = 81;
			ret = easyfind(container, value);
			std::cout << "Element " BLUE << *ret << RESET " found at index: " GREEN << std::distance<std::list<int>::const_iterator>(container.begin(), ret) << RESET << std::endl;
		}
		catch (const std::out_of_range& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << YELLOW ">>>>>>>>>> TEST with LIST <<<<<<<<<<\n" RESET << std::endl;
	std::cout << std::endl << ROSE ">>>>>>>>>> TEST with DEQUE <<<<<<<<<<" RESET << std::endl;
	{
		std::deque<int>	container;
		for (int i = 0; i < 100; i++)
		{
			container.push_back(i + 2);
		}
		std::deque<int>::const_iterator ret;
		try
		{
			int value = 0;
			ret = easyfind(container, value);
			std::cout << "Element " BLUE << *ret << RESET " found at index: " GREEN << std::distance<std::deque<int>::const_iterator>(container.begin(), ret) << RESET << std::endl;
		}
		catch (const std::out_of_range& e)
		{
			std::cerr << e.what() << std::endl;
    	}
		try
		{
			int value = 11181;
			ret = easyfind(container, value);
			std::cout << "Element " BLUE << *ret << RESET " found at index: " GREEN << std::distance<std::deque<int>::const_iterator>(container.begin(), ret) << RESET << std::endl;
		}
		catch (const std::out_of_range& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << ROSE ">>>>>>>>>> TEST with DEQUE <<<<<<<<<<\n" RESET << std::endl;
	return 0;
}
