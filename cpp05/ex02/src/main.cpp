/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:51:22 by nimai             #+#    #+#             */
/*   Updated: 2024/02/23 10:02:06 by nimai            ###   ########.fr       */
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
	// AForm	form("form", 123, 50);
	

	std::cout << MAGENTA "Forms are created:\n" RESET
				"\t" << SCForm << "\n"
				"\t" << RRForm << "\n"
				"\t" << PPForm << std::endl;
	
	std::cout << std::endl << std::endl;
	std::cout << GREEN "----- ShrubberyCreationForm Sign and execute -----" RESET << std::endl << std::endl;

	commonOfficer.signForm(SCForm);
	managerialPost.signForm(SCForm);
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

int	main( void )
{
	main_test();
   
	return (0);
}
