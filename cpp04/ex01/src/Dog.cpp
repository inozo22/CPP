/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:49 by nimai             #+#    #+#             */
/*   Updated: 2023/10/27 12:04:46 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//***	constructor and destructor//constructor and destructor	***//
Dog::Dog( void ) : Animal("Dog")
{
	std::cout << "Default constructor called in Dog. type: " << this->type << std::endl;
}

// Dog::Dog( std::string name ) : type(DEFAULT_Dog)
// {
// 	std::cout << this->name << ": Created in Dog." << std::endl;
// }

Dog::~Dog(void)
{	
	std::cout << this->type << ": Default destructor called in Dog." << std::endl;
}

Dog::Dog( const Dog &src )
{
	std::cout << this->type << ": Copy constructor called in Dog." << std::endl;
	this->operator=(src);
}

Dog &Dog::operator=( const Dog &src )
{
	std::cout << GREEN "Dog assignment overload operator called." CLEAR << std::endl;
	if (this != &src)
	{
		this->type = src.getType();
	}
	return (*this);
}
//***	constructor and destructor//constructor and destructor	***//


/**********************************************************************************/
void	Dog::makeSound( void ) const
{
    std::cout << CYAN << this->type << ": " << DOG_SOUND << CLEAR << std::endl;
	return ;
}
/**********************************************************************************/
