/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:49 by nimai             #+#    #+#             */
/*   Updated: 2023/10/27 12:09:46 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//***	constructor and destructor//constructor and destructor	***//
WrongCat::WrongCat( void ) : WrongAnimal("WrongCat")
{
	std::cout << "Default constructor called in WrongCat. type: " << this->type << std::endl;
}

// WrongCat::WrongCat( std::string name ) : type(DEFAULT_WrongCat)
// {
// 	std::cout << this->name << ": Created in WrongCat." << std::endl;
// }

WrongCat::~WrongCat(void)
{	
	std::cout << this->type << ": Default destructor called in WrongCat." << std::endl;
}

WrongCat::WrongCat( const WrongCat &src )
{
	std::cout << this->type << ": Copy constructor called in WrongCat." << std::endl;
	this->operator=(src);
}

WrongCat &WrongCat::operator=( const WrongCat &src )
{
	std::cout << GREEN "WrongCat assignment overload operator called." RESET << std::endl;
	if (this != &src)
	{
		this->type = src.getType();
	}
	return (*this);
}
//***	constructor and destructor//constructor and destructor	***//


/**********************************************************************************/
void	WrongCat::makeSound( void ) const
{
    std::cout << GREEN << this->type << ": " << "Baa baa" << RESET << std::endl;
	return ;
}
/**********************************************************************************/
