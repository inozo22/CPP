/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:51:24 by nimai             #+#    #+#             */
/*   Updated: 2023/11/23 16:48:31 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>
#include <iomanip>

AForm::AForm( void ) : _name("unknown"), _signed(false), _gradeToSign(LOWEST), _gradeToExecute(LOWEST) 
{
	std::cout << "AForm: Default constructor called." << std::endl;
}

AForm::AForm( std::string const & name, int const gradeToSign, int const gradeToExecute ) : 
_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < HIGHEST || gradeToExecute < HIGHEST)
		throw(AForm::GradeTooHighException());
	if (gradeToSign > LOWEST || gradeToExecute > LOWEST)
		throw(AForm::GradeTooLowException());
	this->_gradeToSign = gradeToSign;
	this->_gradeToExecute =gradeToExecute;
	std::cout << this->_name << ": Created. Grade to sign: " << this->_gradeToSign 
	<< " and grade to execute: " << this->_gradeToExecute << std::endl;
}

AForm::AForm( AForm const & src ): 
_name(src._name), _signed(false),  _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	std::cout << this->_name << "AForm: copy constructor called." << std::endl;
}

AForm::~AForm( void )
{
	std::cout << this->_name << ": Default destructor called." << std::endl;	
}

AForm &AForm::operator=( const AForm &src )
{
	std::cout << "AForm assignment operator overload called." << std::endl;
	this->_signed = src._signed;
	return (*this);
}

void	AForm::beSigned(  Bureaucrat const & bureaucrat )
{
	if (this->_signed)
		return (throw(AForm::SignedException()));
	if (bureaucrat.getGrade() > this->getGradeToSign())
		return (throw(AForm::GradeTooLowException()));
	this->_signed = true;
	std::cout << this->_name << " has signed with " << bureaucrat.getGrade() 
	<< "th postion. Good job!" << std::endl;
}

void	AForm::execute( Bureaucrat const & executer ) const
{
	if (this->_signed == false)
		return (throw(AForm::NoSignedException()));
	if (executer.getGrade() > this->_gradeToExecute)
		return (throw(AForm::GradeTooLowException()));
	std::cout << executer.getName() << " executed " << std::endl;
	this->beExecuted();	
}

std::string const &AForm::getName( void ) const
{
	return (this->_name);
}

int	AForm::getGradeToSign( void ) const
{
	return (this->_gradeToSign);
}

int	AForm::getGradeToExecute( void ) const
{
	return (this->_gradeToExecute);
}

const char	*	AForm::GradeTooHighException::what(void) const throw()
{
	return ("The grade is too high for this form.");
}

const char	*	AForm::GradeTooLowException::what(void) const throw()
{
	return ("The grade is too low for this form.");
}

const char	*	AForm::SignedException::what(void) const throw()
{
	return ("The form is already signed.");
}

const char	*	AForm::NoSignedException::what(void) const throw()
{
	return ("The form hasn't been signed yet.");
}

std::ostream &	operator << (std::ostream & os, AForm const & obj)
{
	os << obj.getName() << " (Required grade " << obj.getGradeToSign()
	<< " to sign and " << obj.getGradeToExecute() << " to execute)";
	return (os);
}
