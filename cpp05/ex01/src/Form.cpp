/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:51:24 by nimai             #+#    #+#             */
/*   Updated: 2023/11/07 15:59:43 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
// #include <string>
#include <iostream>

Form::Form( void ) : _name("unknown"), _gradeToSign(LOWEST), _gradeToExecute(LOWEST), _signed(0)
{
	std::cout << "Form: Default constructor called." << std::endl;
}

Form::Form( std::string const & name, int const gradeToSign, int const gradeToExecute ) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < HIGHEST || gradeToExecute < HIGHEST)
		throw(Form::GradeTooHighException());
	if (gradeToSign > LOWEST || gradeToExecute > LOWEST)
		throw(Form::GradeTooLowException());
	else
	{
		this->_gradeToSign = gradeToSign;
		///////////////////
		std::cout << this->_name << ": Created. Grade: " << this->_grade << std::endl;
	}
	std::cout << this->_name << ": Form constructor called. Grade: " << grade << std::endl;
}

Form::Form( Form const & src ): _name(src._name), _grade(src._grade)

{
	std::cout << "Form: assignment overload operator called." << std::endl;
}

Form::~Form( void )
{
	std::cout << this->_name << ": Default destructor called." << std::endl;
	
}

Form &Form::operator=( const Form &src )
{
	if (this != &src)
	{
		this->_grade = src._grade;
	}
	return (*this);
}

void	Form::beSigned(  Bureaucrat const & bureaucrat )
{
	if (this->_grade + i > LOWEST)
		return (throw(Form::GradeTooLowException()));
	this->_grade += i;
	std::cout << this->_name << " is demoted to " << this->_grade << "th postion. Never mind!" << std::endl;
}


std::string const &Form::getName( void ) const
{
	return (this->_name);
}

int	Form::getGradeToSign( void ) const
{
	return (this->_gradeToSign);
}

int	Form::getGradeToExecute( void ) const
{
	return (this->_gradeToExecute);
}

const char	*	Form::GradeTooHighException::what(void) const throw()
{
	return ("Form: grade too high.");
}

const char	*	Form::GradeTooLowException::what(void) const throw()
{
	return ("Form: grade too low.");
}

std::ostream &	operator << (std::ostream & os, Form const & obj)
{
	os << "Form: " << obj.getName() << " Form grade " << obj.getGrade();
	return (os);
}
