/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:51:22 by nimai             #+#    #+#             */
/*   Updated: 2023/11/21 17:10:48 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

void	main_test( void )
{
	Bureaucrat	commonOfficer("Common Officer", 147);
	Bureaucrat	managerialPost("Managerial Post", 50);
	Bureaucrat	bigwig("bigwig", 3);
	
	std::cout << "Bureaucrats are created:\n"
				"\t" << commonOfficer << "\n"
				"\t" << managerialPost << "\n"
				"\t" << bigwig << std::endl;
	
	ShrubberyCreationForm SCForm("Bonsai");
	RobotomyRequestForm RRForm("iCOP");
	PresidentialPardonForm PPForm(bigwig.getName());

	std::cout << "Forms are created:\n"
				"\t" << SCForm << "\n"
				"\t" << RRForm << "\n"
				"\t" << PPForm << std::endl;
	
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


int	main( void )
{
	main_test();
	// second_test();
	


    
	return (0);
}
