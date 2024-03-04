/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:01:25 by nimai             #+#    #+#             */
/*   Updated: 2023/12/13 14:01:33 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <iostream>

template<typename T>
void	searcher(std::string type, T & container, int num)
{
//	int	ret = 0;
	std::cout << WHITE "---function searcher: searching for " << num << RESET << std::endl;
	std::cout << "Container type: " << type << "	";
	for (typename T::iterator iter = container.begin(); iter != container.end(); iter++)
	{ 
		if (*iter == num)
		{
			std::cout << GREEN << "[" << *iter << "]" << RESET;
		}
	}
	std::cout << std::endl;
}



int	main( void )
{
	{
		std::cout << std::endl << CYAN ">>>>>>>>>> TEST with VECTOR <<<<<<<<<<" RESET << std::endl;
		std::vector<int>	container;
	
		std::cout << "Vector container: ";
		for (std::vector<int>::iterator iter = container.begin(); iter != container.end(); ++iter)
			std::cout << "[" << *iter << "]";
		std::cout << std::endl;
		for (int i = 0; i <= 20; i++)
			::searcher("Vector", container, i);
		std::cout << std::endl;

		for (int i = -4; i < 10; i++)
			container.push_back(i * 2);

		std::cout << "Vector container2: ";
		for (std::vector<int>::iterator iter = container.begin(); iter != container.end(); ++iter)
			std::cout << GREEN << "[" << *iter << "]" << RESET;

		std::cout << std::endl;
		for (int i = 0; i <= 20; i++)
			::searcher("Vector", container, i);
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << CYAN ">>>>>>>>>> TEST with LIST <<<<<<<<<<" RESET << std::endl;
		std::list<int>	container;
	
		std::cout << "List container: ";
		for (std::list<int>::iterator iter = container.begin(); iter != container.end(); ++iter)
			std::cout << "[" << *iter << "]";
		std::cout << std::endl;
		for (int i = 0; i <= 20; i++)
			::searcher("List", container, i);

		std::cout << std::endl;

		for (int i = -4; i < 10; i++)
			container.push_back(i * 2);

		std::cout << "List container2: ";
		for (std::list<int>::iterator iter = container.begin(); iter != container.end(); ++iter)
			std::cout << GREEN << "[" << *iter << "]" << RESET;
		std::cout << std::endl;
		for (int i = 0; i <= 20; i++)
			::searcher("List", container, i);
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << CYAN ">>>>>>>>>> TEST with DEQUE <<<<<<<<<<" RESET << std::endl;
		std::deque<int>	container;
	
		std::cout << "Deque container: ";
		for (std::deque<int>::iterator iter = container.begin(); iter != container.end(); ++iter)
			std::cout << "[" << *iter << "]";
		std::cout << std::endl;
		for (int i = 0; i <= 20; i++)
			::searcher("Deque", container, i);

		std::cout << std::endl;

		for (int i = -4; i < 10; i++)
			container.push_back(i * 2);

		std::cout << "Deque container2: ";
		for (std::deque<int>::iterator iter = container.begin(); iter != container.end(); ++iter)
			std::cout << GREEN << "[" << *iter << "]" << RESET;
		std::cout << std::endl;
		for (int i = 0; i <= 20; i++)
			::searcher("Deque", container, i);
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << CYAN ">>>>>>>>>> TEST with FORWARD_LIST <<<<<<<<<<" RESET << std::endl;
		std::forward_list<int>	container;
	
		std::cout << "Forward_list container: ";
		for (std::forward_list<int>::iterator iter = container.begin(); iter != container.end(); ++iter)
			std::cout << "[" << *iter << "]";
		std::cout << std::endl;
		for (int i = 0; i <= 20; i++)
			::searcher("Forward_list", container, i);

		std::cout << std::endl;

		for (int i = -4; i < 10; i++)
			container.push_front(i * 2);

		std::cout << "Forward_list container2: ";
		for (std::forward_list<int>::iterator iter = container.begin(); iter != container.end(); ++iter)
			std::cout << GREEN << "[" << *iter << "]" << RESET;
		std::cout << std::endl;
		for (int i = 0; i <= 20; i++)
			::searcher("Forward_list", container, i);
		std::cout << std::endl;
	}

	return (0);
}