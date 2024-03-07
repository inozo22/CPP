/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:01:18 by nimai             #+#    #+#             */
/*   Updated: 2024/03/07 11:56:22 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <limits>

/* void	test1( void )
{
	std::cout << std::endl << CYAN ">>>>>>>>>> TEST1 CALLED <<<<<<<<<<" RESET << std::endl;
	std::cout << "input 5(1, 5, 6, 7, 222) numbers" << std::endl;
	MutantStack sp = MutantStack(5);
	int inputNumbers[] = {1, 5, 6, 7, 222};
	int	*begin = inputNumbers;
	int *end = inputNumbers + sizeof(inputNumbers) / sizeof(inputNumbers[0]);

	sp.addMultipulNumber(begin, end);
	std::cout << sp.shortestMutantStack() << std::endl;
	std::cout << sp.longestMutantStack() << std::endl;
}

void	test2( void )
{
	std::cout << std::endl << CYAN ">>>>>>>>>> TEST2 CALLED <<<<<<<<<<" RESET << std::endl;
	std::cout << "input 10005(from 0 * 5 to 10005 * 5) numbers" << std::endl;
	MutantStack sp = MutantStack(10005);
	int inputNumbers[10005];
	for (int i = 0; i < 10005; i++)
	{
		inputNumbers[i] = i * 5;
	}
	std::cout << std::endl;
	int	*begin = inputNumbers;
	int *end = inputNumbers + sizeof(inputNumbers) / sizeof(inputNumbers[0]);
	sp.addMultipulNumber(begin, end);
	std::cout << sp.shortestMutantStack() << std::endl;
	std::cout << sp.longestMutantStack() << std::endl;
}

void	test3( void )
{
	std::cout << std::endl << CYAN ">>>>>>>>>> TEST3 CALLED <<<<<<<<<<" RESET << std::endl;
	std::cout << "input 2000000 numbers" << std::endl;
	//It's kind of limit size to allocate
	int max = 2000000;
	MutantStack sp = MutantStack(max);
	int inputNumbers[max];
	for (int i = 0; i < max; i++)
	{
		inputNumbers[i] = i;
	}
	int	*begin = inputNumbers;
	int *end = inputNumbers + sizeof(inputNumbers) / sizeof(inputNumbers[0]);
	sp.addMultipulNumber(begin, end);
	std::cout << sp.shortestMutantStack() << std::endl;
	std::cout << sp.longestMutantStack() << std::endl;
} */

/* void	subject_test( void )
{
	std::cout << std::endl << CYAN ">>>>>>>>>> SUBJECT TEST CALLED <<<<<<<<<<" RESET << std::endl;

	MutantStack sp = MutantStack(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestMutantStack() << std::endl;
	std::cout << sp.longestMutantStack() << std::endl;
} */

/* int	main( int ac, char **av )//main in subject
{
	if (ac == 2)
	{
		std::string arg = av[1];
		if (arg == "test1")
			test1();
		if (arg == "test2")
			test2();
		if (arg == "test3")
			test3();
	}
	else
		subject_test();
	return (0);
} */

int main( void )
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
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
	return 0;
}

