/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:50:04 by nimai             #+#    #+#             */
/*   Updated: 2023/11/21 16:52:13 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("presidentialpardonform", PP_SIGN, PP_EXEC), _target("noname")
{
	std::cout << "PresidentialPardonForm: Default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ): AForm(src), _target(src._target)
{
	std::cout << "PresidentialPardonForm: copy constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string const & target ): AForm("presidentialpardonform", PP_SIGN, PP_EXEC), _target(target)
{
	std::cout << "PresidentialPardonForm: arrtibute constructor called." << std::endl;
	if (this->_target.empty())
		this->_target = "noname";
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "Default destructor called in PresidentialPardonForm." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &src )
{
	if (this == &src)
		return *this;
	std::cout << "PresidentialPardonForm assignment operator overload called." << std::endl;
	this->_target = src._target;

	return (*this);
}

//			std::string const &		getTarget( void ) const;	
//			void	beExecuted( void ) const;

void	PresidentialPardonForm::beExecuted( void ) const
{
	std::cout << this->_target << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string const &	PresidentialPardonForm::getTarget( void ) const
{
	return (this->_target);
}
