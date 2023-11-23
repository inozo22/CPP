/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:49:03 by nimai             #+#    #+#             */
/*   Updated: 2023/11/23 15:49:37 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


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

AForm	*Intern::makeForm( std::string formName, std::string target)
{
	int			i;
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
			/* code */
			break;	
		case 1:
			/* code */
			break;
		case 2:
			/* code */
			break;
		default:
			break;
    }
    std::cout << "Intern creates " << formName << std::endl;
    
}

