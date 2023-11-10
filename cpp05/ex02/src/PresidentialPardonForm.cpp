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



void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	
}



std::ostream &	operator << (std::ostream & os, PresidentialPardonForm const & obj)
{
	os << "PresidentialPardonForm: " << obj.getName() << " PresidentialPardonForm required grade " << obj.getGradeToSign() << " to sign. ";
	return (os);
}
