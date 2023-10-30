/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:03:41 by nimai             #+#    #+#             */
/*   Updated: 2023/10/30 16:53:29 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//***	constructor and destructor//constructor and destructor	***//
Brain::Brain( void )
{
	std::cout << "Default constructor called in Brain. type: " << std::endl;
}

// Brain::Brain( std::string type ) : type(type)
// {
// 	std::cout << this->type << ": Created in Brain." << std::endl;
// }

Brain::~Brain(void)
{	
	std::cout << this->type << ": Default destructor called in Brain." << std::endl;
}

Brain::Brain( const Brain &src )
{
	std::cout << this->type << ": Copy constructor called in Brain." << std::endl;
	this->operator=(src);
}

Brain &Brain::operator=( const Brain &src )
{
	std::cout << GREEN "Brain assignment overload operator called." CLEAR << std::endl;
	if (this != &src)
	{
		this->type = src.getType();
	}
	return (*this);
}
//***	constructor and destructor//constructor and destructor	***//

