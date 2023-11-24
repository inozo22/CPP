/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:50:47 by nimai             #+#    #+#             */
/*   Updated: 2023/11/24 11:58:18 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("robotomyrequestform", RR_SIGN, RR_EXEC)
{
	std::cout << "RobotomyRequestForm: Default constructor called." << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src )
: AForm("robotomyrequestform", RR_SIGN, RR_EXEC)
{
	*this = src;
	// std::cout << this->_name << "RobotomyRequestForm: copy constructor called." << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm( std::string const & target )
: AForm("RobotomyRequestForm", RR_SIGN, RR_EXEC), _target(target)
{
	std::cout << "RobotomyRequestForm: arrtibute constructor called." << std::endl;
	if (this->_target.empty())
		this->_target = "noname";
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << this->getName() << ": Default destructor called." << std::endl;	
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &src )
{
	std::cout << "RobotomyRequestForm assignment operator overload called." << std::endl;
	this->_target = src._target;
	return (*this);
}



void	RobotomyRequestForm::beExecuted( void ) const
{
	std::srand(std::time(nullptr));//did not work without this

	std::cout << CYAN << this->_target 
	<< " * chuiiiiiiiin dlullululluulu pi--- pi--- BIIIIIIIIII * " RESET << std::endl;
	if (std::rand() % 2)
		std::cout << RED "ROBOTOMIZATION FAILED! CAPTURE " << this->_target << " NOW!!!" RESET << std::endl;
	else
		std::cout << CYAN << this->_target << " SUCCESSFULLY ROBOTOMIZED." RESET << std::endl;
}

std::string const &	RobotomyRequestForm::getTarget( void ) const
{
	return (this->_target);
}
