/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:01:25 by nimai             #+#    #+#             */
/*   Updated: 2024/03/04 14:35:51 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int	main( void )
{
	std::cout << std::endl << CYAN ">>>>>>>>>> TEST with VECTOR <<<<<<<<<<" RESET << std::endl;
	{
		int arr[] = {1, 2, 3, 4, 5};
		std::vector<int>	container(arr, arr + sizeof(arr) / sizeof(arr[0]));
		std::vector<int>::const_iterator ret;

		try
		{
			std::vector<int>::const_iterator ret1 = easyfind(container, 3);
			std::cout << "Value found at index: " << *ret1 << std::endl;
		}
		catch (const std::out_of_range& e)
		{
			std::cerr << e.what() << std::endl;
    	}
		try
		{
			std::vector<int>::const_iterator ret2 = easyfind(container, 8);
			std::cout << "Value found at index: " << *ret2 << std::endl;
		}
		catch (const std::out_of_range& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}

