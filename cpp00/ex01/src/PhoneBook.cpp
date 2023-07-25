/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:05:51 by nimai             #+#    #+#             */
/*   Updated: 2023/07/25 14:54:54 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook(): _count (0)
{
	std::string empty = "";
	for (int i = 0; i < MAX_CONTACT; i++)
		contact[i].set_info(i, empty);
	std::cout << "Has been made PhoneBook object." << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Has been destloyed PhoneBook object." << std::endl;
}

void	PhoneBook::cmd_add()
{
	std::cout << "I'm in cmd_add." << std::endl;
	// std::string info;

	// std::cout << PHONEBOOK;
	// std::getline(std::cin, info);
	std::string heads[5] = 
	{
		"first_name",
		"last_name",
		"nickname",
		"phone_number",
		"darkest_secret"
	};

	if (_count > MAX_CONTACT)
		_count = 0;
	
	std::string input;
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "[ADD] " << std::setfill(' ') << std::setw(15);
		std::cout << heads[i] << " > ";
		std::getline(std::cin, input);
		if (input.length())
		{
			this->contact[_count].set_info(i, input);
		}
	}
	
	_count++;
}

void	PhoneBook::cmd_search()
{
	std::cout << "I'm in cmd_search." << std::endl;
	
}

void	PhoneBook::cmd_exit()
{
	std::cout << "EXIT" << std::endl;
	PhoneBook::~PhoneBook();
	exit (0);
}

