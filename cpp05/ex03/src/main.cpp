/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:51:22 by nimai             #+#    #+#             */
/*   Updated: 2023/11/23 16:58:56 by nimai            ###   ########.fr       */
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
	intern_test(SCFormName, "Forest");
	intern_test(RRFormName, "iCOP");
	intern_test(PPFormName, "Tramp");
	intern_test("form does not exit", "Momomi");
	intern_test("", "");
	// second_test();
	


    
	return (0);
}
