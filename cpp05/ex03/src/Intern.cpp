/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:49:03 by nimai             #+#    #+#             */
/*   Updated: 2023/11/24 11:52:06 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

Intern::Intern( void )
{
    std::cout << "Intern: Default constructor called." << std::endl;
}
Intern::Intern( Intern const &src )
{
    *this = src;
	std::cout << "Intern: copy constructor called." << std::endl;
}
Intern::~Intern( void )
{
    std::cout << "Intern: Default destructor called." << std::endl;
    
}

Intern & Intern::operator=(const Intern &src)
{
    (void)src;
	std::cout << "Intern: assignment overload operator called." << std::endl;
	return (*this);
}

const char *	Intern::InvalidFormName::what( void ) const throw()
{
	return ("Invalid form name");
}

/**
 * @note there is no a forest of if/else if, but is it OK?
  */
AForm	*Intern::makeForm( std::string formName, std::string target)
{
	int			i;
	AForm		*ret = NULL;
	std::string	type[3] = 
	{"shrubbery creation", "robotomy request", "presidential pardon"};
	
	for (i = 0; i < 3; i++)
	{
		if (formName == type[i])
			break ;
	}
	switch ( i )
    {
		case 0:
		{
			ret = new ShrubberyCreationForm(target);
			break;	
		}
		case 1:
		{
			ret = new RobotomyRequestForm(target);
			break;
		}
		case 2:
		{
			ret = new PresidentialPardonForm(target);
			break;
		}
		default:
		{
			std::cout << RED "Intern couldn't create " << formName << RESET << std::endl;
			throw Intern::InvalidFormName();
		}
    }
	std::cout << "Intern creates " << formName << std::endl;
	return (ret);    
}

