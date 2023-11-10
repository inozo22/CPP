/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:50:47 by nimai             #+#    #+#             */
/*   Updated: 2023/11/09 16:51:15 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("robotomyrequestform", RR_SIGN, RR_EXEC)
{
	std::cout << "RobotomyRequestForm: Default constructor called." << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ): AForm("robotomyrequestform", RR_SIGN, RR_EXEC)
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



void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	
}

std::ostream &	operator << (std::ostream & os, RobotomyRequestForm const & obj)
{
	os << "RobotomyRequestForm: " << obj.getName() << " RobotomyRequestForm required grade " << obj.getGradeToSign() << " to sign. ";
	return (os);
}
