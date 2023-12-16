/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:05:37 by nimai             #+#    #+#             */
/*   Updated: 2023/12/16 10:54:49 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
//	std::cout << "Has been made Contact object." << std::endl;
}

Contact::~Contact()
{
//	std::cout << "Has been destloyed Contact object." << std::endl;
}

void Contact::set_info(int &colum, std::string &input)
{
	this->_info[colum] = input;
}

/**
 * @note info[5] has id from phonebook
  */
void Contact::get_info_list(int &index) const
{
	(void)index;
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10) << this->_info[5];
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "|";
		if (this->_info[i].size() <= 10)
			std::cout << std::setfill(' ') << std::setw(10) << this->_info[i];
		else
			std::cout << this->_info[i].substr(0, 9) << ".";
	}
	std::cout << "|" << std::endl;
}

int Contact::get_info_full(std::string &input) const
{
	std::string heads[5] = 
	{
		"first_name",
		"last_name",
		"nickname",
		"phone_number",
		"darkest_secret"
	};
	if (input != _info[5])
		return(1) ;
	for (int i = 0; i < 5; ++i)
	{
		std::cout << std::setw(15) << heads[i] << " : ";
		std::cout << _info[i] << std::endl;
	}
	return (0);
}
