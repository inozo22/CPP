/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:49 by nimai             #+#    #+#             */
/*   Updated: 2023/12/22 17:40:53 by nimai            ###   ########.fr       */
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

// Dog::Dog( std::string name ) : type(DEFAULT_Dog)
// {
// 	std::cout << this->name << ": Created in Dog." << std::endl;
// }

Dog::~Dog(void)
{	
	delete (this->_brain);
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
	std::cout << "Dog assignment overload operator called." CLEAR << std::endl;
	if (this != &src)
	{
		this->type = src.getType();
		if (this->_brain != NULL)
			delete (this->_brain);
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}
//***	constructor and destructor//constructor and destructor	***//


/**********************************************************************************/
void	Dog::makeSound( void ) const
{
    std::cout << CYAN << this->type << ": " << this->getSound() << CLEAR << std::endl;
	return ;
}

std::string Dog::getSound( void ) const
{
	return (DOG_SOUND);
}

Brain*	Dog::getBrain( void ) const
{
	return (this->_brain);
}
/**********************************************************************************/

// std::ostream&	operator<<(std::ostream &out, Dog const &src)
// {
// 	out << "What does the " << src.getType() << " say " << src.getSound();
// 	return (out);
// }



