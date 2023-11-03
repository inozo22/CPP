/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:22:30 by nimai             #+#    #+#             */
/*   Updated: 2023/11/03 12:22:32 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "MateriaSource.hpp"
// #include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource( void )
{
	std::cout << "Default constructor called in MateriaSource" << std::endl;
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		this->_materias[i] = NULL;
	}
}

// MateriaSource::MateriaSource( MateriaSource const & src )
// {
// 	std::cout << "Created in MateriaSource." << std::endl;
// 	for (int i = 0; i < MAX_MATERIA; i++)
// 	{
// 		this->_materias[i] = NULL;
// 	}
// }

MateriaSource::~MateriaSource( void )
{
	std::cout << "Default destructor called in MateriaSource." << std::endl;
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->_materias[i] != NULL)
		{
			delete (this->_materias[i]);
			this->_materias[i] = NULL;
		}
	}
}

// MateriaSource::MateriaSource & operator=(MateriaSource const & src)
// {

// }


void MateriaSource::learnMateria( AMateria *newOne )
{
	if (!newOne)
	{
		std::cout << RED "MateriaSource with no materia to learn." RESET << std::endl;
		return ;
	}
	for (int i = 0; i < MAX_MATERIA; i++)
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = newOne;
			std::cout << "Learned " << this->_materias[i]->getType() << std::endl;
			return ;
		}
	std::cout << RED "Sorry, you can't learn more than 4 materias." RESET<< std::endl;
	delete newOne;
	return ;
}

AMateria* MateriaSource::createMateria( std::string const & type )
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->_materias[i] && this->_materias[i]->getType() == type)
		{
			std::cout << "Creating " << this->_materias[i]->getType() << "... " << std::endl;
			return (this->_materias[i]->clone());
		}
	}
	std::cout << RED "Sorry, MateriaSource doesn't know how to create " RESET << type << std::endl;
	return (NULL);
}
