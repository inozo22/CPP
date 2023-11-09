/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:50:04 by nimai             #+#    #+#             */
/*   Updated: 2023/11/09 17:05:15 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("presidentialpardonform", PP_SIGN, PP_EXEC) 
{
	std::cout << "PresidentialPardonForm: Default constructor called." << std::endl;
}

// PresidentialPardonForm::PresidentialPardonForm( std::string const & name, int const gradeToSign, int const gradeToExecute ) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
// {
// 	if (gradeToSign < HIGHEST || gradeToExecute < HIGHEST)
// 		throw(PresidentialPardonForm::GradeTooHighException());
// 	if (gradeToSign > LOWEST || gradeToExecute > LOWEST)
// 		throw(PresidentialPardonForm::GradeTooLowException());
// 	this->_gradeToSign = gradeToSign;
// 	this->_gradeToExecute =gradeToExecute;
// 	std::cout << this->_name << ": Created. Grade to sign: " << this->_gradeToSign << " and grade to execute: " << this->_gradeToExecute << std::endl;
// }

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ): AForm("presidentialpardonform", PP_SIGN, PP_EXEC)
{
	std::cout << "PresidentialPardonForm: copy constructor called." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "Default destructor called." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &src )
{
	if (this == &src)
		return *this;
	std::cout << "PresidentialPardonForm assignment operator overload called." << std::endl;
	this->_signed = src._signed;
	return (*this);
}

// void	PresidentialPardonForm::beSigned(  Bureaucrat const & bureaucrat )
// {
// 	if (this->_signed)
// 		return (throw(PresidentialPardonForm::SignedException()));
// 	if (bureaucrat.getGrade() > this->getGradeToSign())
// 		return (throw(PresidentialPardonForm::GradeTooLowException()));
// 	this->_signed = true;
// 	std::cout << this->_name << " has signed with " << bureaucrat.getGrade() << "th postion. Good job!" << std::endl;
// }


// std::string const &PresidentialPardonForm::getName( void ) const
// {
// 	return (this->_name);
// }

// int	PresidentialPardonForm::getGradeToSign( void ) const
// {
// 	return (this->_gradeToSign);
// }

// int	PresidentialPardonForm::getGradeToExecute( void ) const
// {
// 	return (this->_gradeToExecute);
// }

// const char	*	PresidentialPardonForm::GradeTooHighException::what(void) const throw()
// {
// 	return ("PresidentialPardonForm: grade too high to sign.");
// }

// const char	*	PresidentialPardonForm::GradeTooLowException::what(void) const throw()
// {
// 	return ("PresidentialPardonForm: grade too low to sign.");
// }

// const char	*	PresidentialPardonForm::SignedException::what(void) const throw()
// {
// 	return ("PresidentialPardonForm: is already signed.");
// }

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	
}



std::ostream &	operator << (std::ostream & os, PresidentialPardonForm const & obj)
{
	os << "PresidentialPardonForm: " << obj.getName() << " PresidentialPardonForm required grade " << obj.getGradeToSign() << " to sign. ";
	return (os);
}
