/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:01:18 by nimai             #+#    #+#             */
/*   Updated: 2024/03/11 08:06:41 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <limits>
#include <list>
#include <iterator>

void	test1( void )
{
	MutantStack<std::string> mstack;
	mstack.push("Hello!!! ");
	mstack.push("Hello! ");
	mstack.push("here ");
	std::cout << "Print the last one: " << mstack.top() << std::endl;
//	mstack.pop();
//	std::cout << mstack.size() << std::endl;
	mstack.push("I ");
	mstack.push("am. \n");
	mstack.push("How are you?");
	//[...]
	MutantStack<std::string>::iterator it = mstack.begin();
	MutantStack<std::string>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it;
		++it;
	}
	std::cout << std::endl;
	std::stack<std::string> s(mstack);
}

void	subject_test( void )
{
	std::cout << CYAN "- - - - - - - - Subject test start - - - - - - -" RESET << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "Print the last one: " << mstack.top() << std::endl;
		std::cout << "Delete it" << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << CYAN "- - - - - - - - Create another container to compare - - - - - - -" RESET << std::endl;
	{
		std::list<int> intList;
		intList.push_back(5);
		intList.push_back(17);
		std::cout << "Print the last one: " << intList.back() << std::endl;
		std::cout << "Delete it" << std::endl;
		intList.pop_back();
		std::cout << intList.size() << std::endl;
		intList.push_back(3);
		intList.push_back(5);
		intList.push_back(737);
		//[...]
		intList.push_back(0);
		std::list<int>::iterator it = intList.begin();
		std::list<int>::iterator ite = intList.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
}

int	main( int ac, char **av )//main in subject
{
	if (ac == 2)
	{
		std::string arg = av[1];
		if (arg == "test1")
			test1();
	}
	else
		subject_test();
	return (0);
}
