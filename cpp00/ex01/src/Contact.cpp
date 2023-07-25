/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:05:37 by nimai             #+#    #+#             */
/*   Updated: 2023/07/25 16:33:51 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
//	std::cout << "Has been made Contact object." << std::endl;
//	std::cout << "first: " << Contact::firstname << "\nlast: " << Contact::lastname << "\nnickname: " << Contact::nickname << "\nphone: " << Contact::phone << "\nsecret: " << Contact::secret << std::endl;
}

Contact::~Contact()
{
//	std::cout << "Has been destloyed Contact object." << std::endl;
}

void Contact::set_info(int &colum, std::string &input)
{
	std::cout << "colum: " << colum << "input: " << input << std::endl;
	this->info[colum] = input;
}

void Contact::get_info_list(int &index) const
{
	(void)index;
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10) << this->info[5];
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "|";
		if (this->info[i].size() <= 10)
			std::cout << std::setfill(' ') << std::setw(10) << this->info[i];
		else
		{
			for (int j = 0; j < 9; ++j)
			{
				std::cout << this->info[i][j];
			}
			std::cout << ".";
		}
	}
	std::cout << "|" << std::endl;
}
