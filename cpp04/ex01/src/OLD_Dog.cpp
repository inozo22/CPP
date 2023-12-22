/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:49 by nimai             #+#    #+#             */
/*   Updated: 2023/10/31 12:40:23 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

//***	constructor and destructor//constructor and destructor	***//
Dog::Dog( void ) : Animal("Dog")
{
	this->_brain = new Brain();
	std::cout << "Default constructor called in Dog. type: " << this->type << std::endl;
}

Dog::~Dog(void)
{
	delete (this->_brain);
	std::cout << " in Dog destructor." << std::endl;
	std::cout << this->type << ": Default destructor called in Dog." << std::endl;
}

Dog::Dog( const Dog &src )
{
	this->_brain = NULL;
	std::cout << this->type << ": Copy constructor called in Dog." << std::endl;
	this->operator=(src);
}

Dog &Dog::operator=( const Dog &src )
{
	if (this == &src)
		return *this;
	std::cout << GREEN "Dog assignment overload operator called." CLEAR << std::endl;
	this->type = src.getType();
	if (this->_brain != NULL)
		delete this->_brain;
	this->_brain = new Brain(*src._brain);
	return (*this);
}
//***	constructor and destructor//constructor and destructor	***//


/**********************************************************************************/
void	Dog::makeSound( void ) const
{
    std::cout << CYAN << this->type << ": " << DOG_SOUND << CLEAR << std::endl;
	return ;
}

Brain*	Dog::getBrain(void) const
{
	return (this->_brain);
}
/**********************************************************************************/
