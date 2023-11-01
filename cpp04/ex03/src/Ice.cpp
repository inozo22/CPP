/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:49 by nimai             #+#    #+#             */
/*   Updated: 2023/11/01 12:17:53 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Brain.hpp"

//***	constructor and destructor//constructor and destructor	***//
Ice::Ice( void ) : AMaterial("Ice")
{
	this->_brain = new Brain();
	std::cout << "Default constructor called in Ice. type: " << this->type << std::endl;
}

Ice::~Ice(void)
{
	delete (this->_brain);
	std::cout << " in Ice destructor." << std::endl;
	std::cout << this->type << ": Default destructor called in Ice." << std::endl;
}

Ice::Ice( const Ice &src )
{
	this->_brain = NULL;
	std::cout << this->type << ": Copy constructor called in Ice." << std::endl;
	this->operator=(src);
}

Ice &Ice::operator=( const Ice &src )
{
	if (this == &src)
		return *this;
	std::cout << GREEN "Ice assignment overload operator called." RESET << std::endl;
	// this->type = src.getType();
	this->type = src.type;
	if (this->_brain != NULL)
		delete this->_brain;
	this->_brain = new Brain(*src._brain);
	return (*this);
}
//***	constructor and destructor//constructor and destructor	***//


/**********************************************************************************/
void	Ice::makeSound( void ) const
{
    std::cout << CYAN << this->type << ": " << Ice_SOUND << RESET << std::endl;
	return ;
}

Brain*	Ice::getBrain(void) const
{
	return (this->_brain);
}

void	Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target << " *" << std::endl;
}
/**********************************************************************************/
