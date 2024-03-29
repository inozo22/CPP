/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:51:22 by nimai             #+#    #+#             */
/*   Updated: 2024/02/23 09:49:30 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

void	main_test( void )
{
	std::cout << std::endl << std::endl;
	std::cout << "********** MAIN TEST **********"<< std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat	test("test", 47);
		Bureaucrat	Badman("Badman", 150);
		// Badman.decrementGrade();
		Bureaucrat	presidente("presidente", 1);
		// Bureaucrat	angel("angel", -20);
		Bureaucrat	topo("topo", 10);
		for (int i = 0; i < 100; i++)
		{
			topo.incrementGrade();
		}

	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void second_test()
{
	std::cout << std::endl << std::endl;
	std::cout << "********** SECOND TEST **********"<< std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat bureaucrat("second", 47);
		std::cout << bureaucrat << " successfully created." << std::endl;
		Bureaucrat bureaucrat1("second", 150);
		std::cout << bureaucrat1 << " successfully created." << std::endl;
		bureaucrat.incrementGrade(5);
		bureaucrat1.decrementGrade(5);
		bureaucrat.incrementGrade(5);
		return ;
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << MAGENTA << e.what() << RESET << '\n';
	}
	

}

void third_test() 
{
	std::cout << std::endl << std::endl;
	std::cout << "********** THIRD TEST **********"<< std::endl;
	std::cout << std::endl;

    try {
        Bureaucrat highGradeBureaucrat("John", 1);
        Bureaucrat lowGradeBureaucrat("Alice", 150);

        std::cout << highGradeBureaucrat << std::endl;
        std::cout << lowGradeBureaucrat << std::endl;

        lowGradeBureaucrat.decrementGrade();
        highGradeBureaucrat.incrementGrade();

        std::cout << highGradeBureaucrat << std::endl;
        std::cout << lowGradeBureaucrat << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}


int	main( void )
{
	main_test();
	// second_test();
	// third_test();
	


    
	return (0);
}
