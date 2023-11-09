/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:51:13 by nimai             #+#    #+#             */
/*   Updated: 2023/11/09 16:51:41 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("shrubberycreationform", SC_SIGN, SC_EXEC) 
{
	std::cout << "ShrubberyCreationForm: Default constructor called." << std::endl;
}

// ShrubberyCreationForm::ShrubberyCreationForm( std::string const & name, int const gradeToSign, int const gradeToExecute ) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
// {
// 	if (gradeToSign < HIGHEST || gradeToExecute < HIGHEST)
// 		throw(ShrubberyCreationForm::GradeTooHighException());
// 	if (gradeToSign > LOWEST || gradeToExecute > LOWEST)
// 		throw(ShrubberyCreationForm::GradeTooLowException());
// 	this->_gradeToSign = gradeToSign;
// 	this->_gradeToExecute =gradeToExecute;
// 	std::cout << this->_name << ": Created. Grade to sign: " << this->_gradeToSign << " and grade to execute: " << this->_gradeToExecute << std::endl;
// }

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ):AForm("shrubberycreationform", SC_SIGN, SC_EXEC)
{
	std::cout << this->_name << "ShrubberyCreationForm: copy constructor called." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << this->_name << ": Default destructor called." << std::endl;	
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &src )
{
	std::cout << "ShrubberyCreationForm assignment operator overload called." << std::endl;
	this->_signed = src._signed;
	return (*this);
}

// void	ShrubberyCreationForm::beSigned(  Bureaucrat const & bureaucrat )
// {
// 	if (this->_signed)
// 		return (throw(ShrubberyCreationForm::SignedException()));
// 	if (bureaucrat.getGrade() > this->getGradeToSign())
// 		return (throw(ShrubberyCreationForm::GradeTooLowException()));
// 	this->_signed = true;
// 	std::cout << this->_name << " has signed with " << bureaucrat.getGrade() << "th postion. Good job!" << std::endl;
// }


// std::string const &ShrubberyCreationForm::getName( void ) const
// {
// 	return (this->_name);
// }

// int	ShrubberyCreationForm::getGradeToSign( void ) const
// {
// 	return (this->_gradeToSign);
// }

// int	ShrubberyCreationForm::getGradeToExecute( void ) const
// {
// 	return (this->_gradeToExecute);
// }

// const char	*	ShrubberyCreationForm::GradeTooHighException::what(void) const throw()
// {
// 	return ("ShrubberyCreationForm: grade too high to sign.");
// }

// const char	*	ShrubberyCreationForm::GradeTooLowException::what(void) const throw()
// {
// 	return ("ShrubberyCreationForm: grade too low to sign.");
// }

// const char	*	ShrubberyCreationForm::SignedException::what(void) const throw()
// {
// 	return ("ShrubberyCreationForm: is already signed.");
// }

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	
}

std::ostream &	operator << (std::ostream & os, ShrubberyCreationForm const & obj)
{
	os << "ShrubberyCreationForm: " << obj.getName() << " ShrubberyCreationForm required grade " << obj.getGradeToSign() << " to sign. ";
	return (os);
}
