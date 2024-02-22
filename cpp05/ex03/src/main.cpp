/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:51:22 by nimai             #+#    #+#             */
/*   Updated: 2024/02/22 18:04:03 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <iomanip>

#define SCFormName "shrubbery creation"
#define RRFormName "robotomy request"
#define PPFormName "presidential pardon"

void	intern_test(std::string formName, std::string target)
{
	std::cout << std::endl << std::endl;
	std::cout << YELLOW "********** INTERN TEST **********" RESET << std::endl;
	std::cout << BLUE << "Form name: " << formName << "\n";
	std::cout << std::setfill(' ') << std::setw(11) <<"target: " << target << RESET << std::endl << std::endl;

	Intern jorge = Intern();
	Bureaucrat bigwig("Bigwig", 1);
	AForm * form;
	try
	{
		form = jorge.makeForm(formName, target);
		bigwig.signForm(*form);
		bigwig.executeForm(*form);
		delete (form);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	

}

int	main( void )
{
	intern_test(SCFormName, "Forest");
	intern_test(RRFormName, "iCOP");
	intern_test(PPFormName, "Tramp");
	intern_test("form does not exit", "Momomi");
	intern_test("", "");
   
	return (0);
}
