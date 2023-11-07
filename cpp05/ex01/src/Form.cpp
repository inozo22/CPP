/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:51:24 by nimai             #+#    #+#             */
/*   Updated: 2023/11/07 17:21:41 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
// #include <string>
#include <iostream>

Form::Form( void ) : _name("unknown"), _gradeToSign(LOWEST), _gradeToExecute(LOWEST), _signed(false)
{
	std::cout << "Form: Default constructor called." << std::endl;
}

Form::Form( std::string const & name, int const gradeToSign, int const gradeToExecute ) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false)
{
	if (gradeToSign < HIGHEST || gradeToExecute < HIGHEST)
		throw(Form::GradeTooHighException());
	if (gradeToSign > LOWEST || gradeToExecute > LOWEST)
		throw(Form::GradeTooLowException());
	this->_gradeToSign = gradeToSign;
	this->_gradeToExecute =gradeToExecute;
	///////////////////
	std::cout << this->_name << ": Created. Grade to sign: " << this->_gradeToSign << "and grade to execute: " << this->_gradeToExecute << std::endl;
}

Form::Form( Form const & src ): _name(src._name),  _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute), _signed(false)
{
	std::cout << this->_name << "Form: copy constructor called." << std::endl;
}

Form::~Form( void )
{
	std::cout << this->_name << ": Default destructor called." << std::endl;	
}

Form &Form::operator=( const Form &src )
{
	std::cout << "Form assignment operator overload called." << std::endl;
	// if (this != &src)
	// {
	// 	this->_grade = src._grade;
	// }
	this->_signed = src._signed;
	return (*this);
}

void	Form::beSigned(  Bureaucrat const & bureaucrat )
{
	if (this->_signed)
		throw(Form::SignedException());
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw(Form::GradeTooLowException());
	this->_signed = true;
	std::cout << this->_name << " has signed with " << bureaucrat.getGrade() << "th postion. Good job!" << std::endl;
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
	os << "Form: " << obj.getName() << " Form required grade " << obj.getGradeToSign() << " to sign, ";
	return (os);
}
