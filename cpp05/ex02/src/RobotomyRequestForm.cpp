/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:50:47 by nimai             #+#    #+#             */
/*   Updated: 2023/11/21 16:52:20 by nimai            ###   ########.fr       */
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
RobotomyRequestForm::RobotomyRequestForm( std::string const & target ): AForm("RobotomyRequestForm", RR_SIGN, RR_EXEC), _target(target)
{
	std::cout << "RobotomyRequestForm: arrtibute constructor called." << std::endl;
	if (this->_target.empty())
		this->_target = "noname";
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << this->_name << ": Default destructor called." << std::endl;	
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &src )
{
	std::cout << "RobotomyRequestForm assignment operator overload called." << std::endl;
	this->_target = src._target;
	return (*this);
}



void	RobotomyRequestForm::beExecuted( void ) const
{
	std::cout << this->_target << " * chuiiiiiiiin dlullululluulu pi--- pi--- BIIIIIIIIII * " << std::endl;
	if (std::rand() % 2)
		std::cout << "ROBOTOMIZATION FAILED! CAPTURE " << this->_target << " NOW!!!" << std::endl;
	else
		std::cout << this->_target << "SUCCESSFULLY ROBOTOMIZED." << std::endl;
}

std::string const &	RobotomyRequestForm::getTarget( void ) const
{
	return (this->_target);
}
