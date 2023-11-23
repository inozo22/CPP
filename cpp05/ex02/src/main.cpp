/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:51:22 by nimai             #+#    #+#             */
/*   Updated: 2023/11/23 11:02:49 by nimai            ###   ########.fr       */
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
	std::cout << std::endl << std::endl;
	std::cout << YELLOW "********** MAIN TEST **********" RESET << std::endl;
	std::cout << std::endl;

	Bureaucrat	commonOfficer("Common Officer", 147);
	Bureaucrat	managerialPost("Managerial Post", 50);
	Bureaucrat	bigwig("Bigwig", 3);
	
	std::cout <<  MAGENTA "Bureaucrats are created:\n" RESET 
				"\t" << commonOfficer << "\n"
				"\t" << managerialPost << "\n"
				"\t" << bigwig << std::endl << std::endl;

	ShrubberyCreationForm SCForm("Bonsai");
	RobotomyRequestForm RRForm("iCOP");
	PresidentialPardonForm PPForm(bigwig.getName());

	std::cout << MAGENTA "Forms are created:\n" RESET
				"\t" << SCForm << "\n"
				"\t" << RRForm << "\n"
				"\t" << PPForm << std::endl;
	
	std::cout << std::endl << std::endl;
	std::cout << GREEN "----- ShrubberyCreationForm Sign and execute -----" RESET << std::endl << std::endl;

	commonOfficer.signForm(SCForm);
	commonOfficer.executeForm(SCForm);
	managerialPost.executeForm(SCForm);


	
	std::cout << std::endl;

	std::cout << std::endl << std::endl;
	std::cout << CYAN "----- RobotomyRequestForm Sign and execute -----" RESET << std::endl << std::endl;

	managerialPost.executeForm(RRForm);
	managerialPost.signForm(RRForm);
	managerialPost.executeForm(RRForm);
	bigwig.executeForm(RRForm);
		

	std::cout << std::endl;

	std::cout << std::endl << std::endl;
	std::cout << ORANGE "----- PresidentialPardonForm Sign and execute -----" RESET << std::endl << std::endl;

	bigwig.signForm(PPForm);
	bigwig.executeForm(PPForm);


	std::cout << std::endl << std::endl;
	
	
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
