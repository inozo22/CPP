/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:49 by nimai             #+#    #+#             */
/*   Updated: 2023/12/26 11:17:22 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

//***	constructor and destructor//constructor and destructor	***//
Cat::Cat( void ) : AAnimal("Cat")
{
	this->_brain = new Brain();
	std::cout << "Default constructor called in Cat. type: " << this->type << std::endl;
}

// Cat::Cat( std::string name ) : type(DEFAULT_Cat)
// {
// 	std::cout << this->name << ": Created in Cat." << std::endl;
// }

Cat::~Cat(void)
{
	delete (this->_brain);
	std::cout << this->type << ": Default destructor called in Cat." << std::endl;
}

Cat::Cat( const Cat &src )
{
	this->_brain = NULL;
	std::cout << this->type << ": Copy constructor called in Cat." << std::endl;//I have doubt
	this->operator=(src);
}

Cat &Cat::operator=( const Cat &src )
{
	std::cout << "Cat assignment overload operator called." CLEAR << std::endl;
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
void	Cat::makeSound( void ) const
{
    std::cout << GREEN << this->type << ": " << this->getSound() << CLEAR << std::endl;
	return ;
}

std::string Cat::getSound( void ) const
{
	return (CAT_SOUND);
}

Brain*	Cat::getBrain( void ) const
{
	return (this->_brain);
}
/**********************************************************************************/

// std::ostream&	operator<<(std::ostream &out, Cat const &src)
// {
// 	std::cout << "Im here !!!!" << std::endl;
// 	out << "What does the " << src.getType() << " say " << src.getSound();
// 	return (out);
// }
