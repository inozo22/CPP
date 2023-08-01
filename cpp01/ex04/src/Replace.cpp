/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:03:55 by nimai             #+#    #+#             */
/*   Updated: 2023/08/01 16:34:41 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace( std::string filename, std::string s1, std::string s2 )
{
	std::cout << "HumanA, his/her name is " << name << std::endl;
}

Replace::~Replace(void)
{	
	std::cout << this->name << " has left from the field." << std::endl;
}

// void	HumanA::attack( void )
// {
// 	std::cout << this->name << " has attacked with his " << this->weapon.getType() << std::endl;
// }
