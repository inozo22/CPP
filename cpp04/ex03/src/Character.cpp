/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:28:12 by nimai             #+#    #+#             */
/*   Updated: 2023/11/03 13:23:10 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <string>

Character::Character ( void ): _name("unknown")
{
	for (int i = 0; i < MAX_MATERIA; i++)
		this->_materias[i] = NULL;
	std::cout << "Default constructor called in Character. name: " << this->_name << std::endl;

}

Character::Character( std::string name ): _name(name)
{
	for (int i = 0; i < MAX_MATERIA; i++)
		this->_materias[i] = NULL;
 	std::cout << this->_name << ": Created in Character." << std::endl;

}

Character::Character( Character const &src )
{
	this->_name = src.getName();
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (src._materias[i] != NULL)
			this->_materias[i] = src._materias[i]->clone();
	}
	std::cout << "Copy constructor called in Character." << std::endl;
}

Character::~Character( void )
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->_materias[i] != NULL)
			delete (this->_materias[i]);
	}
	std::cout << "Default destructor called in Character";
}

Character &Character::operator=( const Character &src )
{
	if (this != &src)
	{
		this->_name = src.getName();
		for (int i = 0; i < MAX_MATERIA; i++)
		{
			if (src._materias[i] != NULL)
				this->_materias[i] = src._materias[i]->clone();
		}
		std::cout << GREEN "Character assignment overload operator called." RESET << std::endl;
	}
	return (*this);
}



std::string const & Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = m;
			std::cout << this->getName() << ": got materia: " << m->getType() << std::endl;
			return ;
		}
	}
	std::cout << this->getName() << ": I can't have more." << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx >= MAX_MATERIA || idx < 0)
	{
		std::cout << this->getName() << ": the "<< idx + 1 << "'th inventory doesn't exist." << std::endl;
	}
	else
	{
		if (this->_materias[idx])
		{
			this->_materias[idx] = NULL;
			std::cout << this->getName() << ": threw materia: " << this->_materias[idx]->getType() << std::endl;
		}
		else
			std::cout << this->getName() << ": this inventory is empty." << std::endl;
	}
}

void	Character::use (int idx, ICharacter& target)
{
	if (idx >= MAX_MATERIA || idx < 0)
	{
		std::cout << this->getName() << RED ": the "<< idx << "'th inventory doesn't exist so you can't use nothing." RESET << std::endl;
	}
	else
	{
		if (this->_materias[idx])
		{

			if (this->_materias[idx]->getType() == "ice")
				std::cout << this->getName() << ": * shoots an ice bolt at " << target.getName() << " *" << std::endl;
			else if (this->_materias[idx]->getType() == "cure")
				std::cout << this->getName() << ": * heal " << target.getName() << "'s wounds *" << std::endl;
			std::cout << this->getName() << ": threw materia: " << this->_materias[idx]->getType() << std::endl;
			delete (this->_materias[idx]);
			this->_materias[idx] = NULL;
		}
		else
		{
			std::cout << this->getName() << ": I don't have nothing to use." << std::endl;
		}
	}

}
