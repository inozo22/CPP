/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:50:47 by nimai             #+#    #+#             */
/*   Updated: 2023/11/09 16:08:01 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("robotomyrequestform", LOWEST, LOWEST)
{
	std::cout << "RobotomyRequestForm: Default constructor called." << std::endl;
}

// RobotomyRequestForm::RobotomyRequestForm( std::string const & name, int const gradeToSign, int const gradeToExecute ) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
// {
// 	if (gradeToSign < HIGHEST || gradeToExecute < HIGHEST)
// 		throw(RobotomyRequestForm::GradeTooHighException());
// 	if (gradeToSign > LOWEST || gradeToExecute > LOWEST)
// 		throw(RobotomyRequestForm::GradeTooLowException());
// 	this->_gradeToSign = gradeToSign;
// 	this->_gradeToExecute =gradeToExecute;
// 	std::cout << this->_name << ": Created. Grade to sign: " << this->_gradeToSign << " and grade to execute: " << this->_gradeToExecute << std::endl;
// }

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ): AForm("robotomyrequestform", LOWEST, LOWEST)
{
	*this = src;
	// std::cout << this->_name << "RobotomyRequestForm: copy constructor called." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << this->_name << ": Default destructor called." << std::endl;	
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &src )
{
	std::cout << "RobotomyRequestForm assignment operator overload called." << std::endl;
	this->_signed = src._signed;
	return (*this);
}

// void	RobotomyRequestForm::beSigned(  Bureaucrat const & bureaucrat )
// {
// 	if (this->_signed)
// 		return (throw(RobotomyRequestForm::SignedException()));
// 	if (bureaucrat.getGrade() > this->getGradeToSign())
// 		return (throw(RobotomyRequestForm::GradeTooLowException()));
// 	this->_signed = true;
// 	std::cout << this->_name << " has signed with " << bureaucrat.getGrade() << "th postion. Good job!" << std::endl;
// }


// std::string const &RobotomyRequestForm::getName( void ) const
// {
// 	return (this->_name);
// }

// int	RobotomyRequestForm::getGradeToSign( void ) const
// {
// 	return (this->_gradeToSign);
// }

// int	RobotomyRequestForm::getGradeToExecute( void ) const
// {
// 	return (this->_gradeToExecute);
// }

// const char	*	RobotomyRequestForm::GradeTooHighException::what(void) const throw()
// {
// 	return ("RobotomyRequestForm: grade too high to sign.");
// }

// const char	*	RobotomyRequestForm::GradeTooLowException::what(void) const throw()
// {
// 	return ("RobotomyRequestForm: grade too low to sign.");
// }

// const char	*	RobotomyRequestForm::SignedException::what(void) const throw()
// {
// 	return ("RobotomyRequestForm: is already signed.");
// }

std::ostream &	operator << (std::ostream & os, RobotomyRequestForm const & obj)
{
	os << "RobotomyRequestForm: " << obj.getName() << " RobotomyRequestForm required grade " << obj.getGradeToSign() << " to sign. ";
	return (os);
}
