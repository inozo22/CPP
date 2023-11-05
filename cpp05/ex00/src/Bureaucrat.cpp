/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:51:24 by nimai             #+#    #+#             */
/*   Updated: 2023/11/03 17:29:15 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
// #include <string>
#include "colors.h"
#include <iostream>

Bureaucrat::Bureaucrat( void ) : _name("unknown"), _grade(LOWEST)
{
	std::cout << "Bureaucrat: Default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat( std::string const & name, int grade ) : _name(name), _grade(LOWEST)
{
	std::cout << this->_name << ": Bureaucrat constructor called. Grade: " << grade << std::endl;
	if (grade < HIGHEST)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > LOWEST)
		throw(Bureaucrat::GradeTooLowException());
	else
	{
		this->_grade = grade;
		std::cout << this->_name << ": Created. Grade: " << this->_grade << std::endl;
	}
}

Bureaucrat::Bureaucrat( Bureaucrat const & src )
{
	std::cout << "Bureaucrat: assignment overload operator called." << std::endl;
	
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << this->_name << ": Default destructor called." << std::endl;
	
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &src )
{
	if (this != &src)
	{
		this->_grade = src._grade;
	}
	return (*this);
}



std::string const &Bureaucrat::getName( void ) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade( void )
{
	return (this->_grade);
}
