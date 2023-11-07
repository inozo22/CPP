/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:51:24 by nimai             #+#    #+#             */
/*   Updated: 2023/11/07 11:14:34 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
// #include <string>
#include <iostream>

Bureaucrat::Bureaucrat( void ) : _name("unknown"), _grade(LOWEST)
{
	std::cout << "Bureaucrat: Default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat( std::string const & name, int grade ) : _name(name), _grade(LOWEST)
{
	if (grade < HIGHEST)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > LOWEST)
		throw(Bureaucrat::GradeTooLowException());
	else
	{
		this->_grade = grade;
		std::cout << this->_name << ": Created. Grade: " << this->_grade << std::endl;
	}
	std::cout << this->_name << ": Bureaucrat constructor called. Grade: " << grade << std::endl;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ): _name(src._name), _grade(src._grade)

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

void	Bureaucrat::incrementGrade( void )
{
	this->incrementGrade(1);
}
void	Bureaucrat::incrementGrade( int i )
{
	if (this->_grade - i < HIGHEST)
		return (throw(Bureaucrat::GradeTooHighException()));
	this->_grade -= i;
	std::cout << this->_name << " is promoted to " << this->_grade << "th postion. Congrats!" << std::endl;
}
void	Bureaucrat::decrementGrade( void )
{
	this->decrementGrade(1);
}
void	Bureaucrat::decrementGrade( int i )
{
	if (this->_grade + i > LOWEST)
		return (throw(Bureaucrat::GradeTooLowException()));
	this->_grade += i;
	std::cout << this->_name << " is demoted to " << this->_grade << "th postion. Never mind!" << std::endl;
}


std::string const &Bureaucrat::getName( void ) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

const char	*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat: grade too high.");
}

const char	*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat: grade too low.");
}

std::ostream &	operator << (std::ostream & os, Bureaucrat const & obj)
{
	os << "Bureaucrat: " << obj.getName() << " bureaucrat grade " << obj.getGrade();
	return (os);
}
