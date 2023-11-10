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



void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	
}

std::ostream &	operator << (std::ostream & os, ShrubberyCreationForm const & obj)
{
	os << "ShrubberyCreationForm: " << obj.getName() << " ShrubberyCreationForm required grade " << obj.getGradeToSign() << " to sign. ";
	return (os);
}
