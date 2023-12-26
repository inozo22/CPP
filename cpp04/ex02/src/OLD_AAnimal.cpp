/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:49 by nimai             #+#    #+#             */
/*   Updated: 2023/10/27 12:03:21 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

//***	constructor and destructor//constructor and destructor	***//
AAnimal::AAnimal( void ) : type(DEFAULT_AANIMAL)
{
	std::cout << "Default constructor called in AAnimal. type: " << this->type << std::endl;
}

AAnimal::AAnimal( std::string type ) : type(type)
{
	std::cout << this->type << ": Created in AAnimal." << std::endl;
}

AAnimal::~AAnimal(void)
{	
	std::cout << this->type << ": Default destructor called in AAnimal." << std::endl;
}

// AAnimal::AAnimal( const AAnimal &src )
// {
// 	std::cout << this->type << ": Copy constructor called in AAnimal." << std::endl;
// 	this->operator=(src);
// }

AAnimal &AAnimal::operator=( const AAnimal &src )
{
	std::cout << GREEN "AAnimal assignment overload operator called." RESET << std::endl;
	if (this != &src)
	{
		// this->type = src.getType();
	}
	return (*this);
}
//***	constructor and destructor//constructor and destructor	***//


/**********************************************************************************/
void	AAnimal::makeSound( void ) const
{
    std::cout << YELLOW << this->type << ": Piyo piyo" RESET << std::endl;
	return ;
}

// std::string		AAnimal::getType(void) const
// {
// 	return (this->type);
// }

/**********************************************************************************/
