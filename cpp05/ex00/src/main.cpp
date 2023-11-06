/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:51:22 by nimai             #+#    #+#             */
/*   Updated: 2023/11/06 15:21:04 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main( void )
{
	std::cout << std::endl << std::endl;
	std::cout << "********** MAIN TEST **********"<< std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat	test("test", 47);
		Bureaucrat	Badman("Badman", 150);
		Bureaucrat	presidente("presidente", 1);
		Bureaucrat	angel("angel", -20);
		Bureaucrat	topo("topo", 200);
		/* code */
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

    
	return (0);
}
