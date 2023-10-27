/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:49 by nimai             #+#    #+#             */
/*   Updated: 2023/10/27 12:09:46 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//***	constructor and destructor//constructor and destructor	***//
Cat::Cat( void ) : Animal("Cat")
{
	std::cout << "Default constructor called in Cat. type: " << this->type << std::endl;
}

// Cat::Cat( std::string name ) : type(DEFAULT_Cat)
// {
// 	std::cout << this->name << ": Created in Cat." << std::endl;
// }

Cat::~Cat(void)
{	
	std::cout << this->type << ": Default destructor called in Cat." << std::endl;
}

Cat::Cat( const Cat &src )
{
	std::cout << this->type << ": Copy constructor called in Cat." << std::endl;
	this->operator=(src);
}

Cat &Cat::operator=( const Cat &src )
{
	std::cout << GREEN "Cat assignment overload operator called." CLEAR << std::endl;
	if (this != &src)
	{
		this->type = src.getType();
	}
	return (*this);
}
//***	constructor and destructor//constructor and destructor	***//


/**********************************************************************************/
void	Cat::makeSound( void ) const
{
    std::cout << GREEN << this->type << ": " << CAT_SOUND << CLEAR << std::endl;
	return ;
}
/**********************************************************************************/
