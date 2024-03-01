/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:51:22 by nimai             #+#    #+#             */
/*   Updated: 2024/02/23 13:25:59 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
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
		Bureaucrat	topo("topo", 140);
		Form	form("form", 123, 50);
//		std::cout << "Is it signed form?: " << form.isSigned() << std::endl;
//		std::cout << "Getter form name: " << form.getName() << std::endl;
//		std::cout << "Getter form grade to sign: " << form.getGradeToSign() << std::endl;
//		std::cout << "Getter form grade to execute: " << form.getGradeToExecute() << std::endl;
		std::cout << form << std::endl;
		for (int i = 0; i < 5; i++)
		{
			topo.signForm(form);
			if (!form.isSigned())
				topo.incrementGrade(5);
		}
	}
	catch(std::exception& e)
	{
		std::cerr << RED << e.what() << '\n';
	}
}

void second_test()
{
	std::cout << std::endl << std::endl;
	std::cout << "********** SECOND TEST **********"<< std::endl;
	std::cout << std::endl;

    try {
        Bureaucrat bureaucrat("John Doe", 75);
        Form form("FormA", 50, 80);

        std::cout << form << std::endl;

        bureaucrat.signForm(form);

        // Attempting to sign the form again (should fail)
        bureaucrat.signForm(form);
    } catch (const std::exception& e) {
        std::cerr << RED << "Exception: " << e.what() << std::endl;
    }

}


int	main( void )
{
	main_test();
	// second_test();
	
   
	return (0);
}
