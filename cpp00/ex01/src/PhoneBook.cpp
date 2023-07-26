/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:05:51 by nimai             #+#    #+#             */
/*   Updated: 2023/07/26 11:53:44 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook(): _pos (0), _line (0), _id (0)
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
	_id++;
	std::string heads[5] = 
	{
		"first_name",
		"last_name",
		"nickname",
		"phone_number",
		"darkest_secret"
	};

	if (_pos >= MAX_CONTACT)
	{
		_line = 8;
		_pos = 0;
	}	
	std::string input;
	int	i = 0;
	while (i < 5)
	{
		std::cout << "[ADD] " << std::setfill(' ') << std::setw(15);
		std::cout << heads[i] << " > ";
		std::getline(std::cin, input);
		if (input.length())
		{
			this->contact[_pos].set_info(i, input);
			i++;
		}
		else
			std::cout << "CAUTION! input field is empty, please fill it." << std::endl;
	}
	input = std::to_string(_id);
	this->contact[_pos].set_info(i, input);
	_pos++;
	if (_line < 8)
		_line++;
}

void	PhoneBook::cmd_search()
{
	if (_id == 0)
	{
		std::cout << "phonebook is empty." << std::endl;
		return ;
	}
	std::cout << "+----------+----------+----------+----------+\n";
	std::cout << "|index     |first name|last name |nick name |\n";
	std::cout << "+----------+----------+----------+----------+\n";
	for (int i = 0; i < _line; ++i)
	{
		this->contact[i].get_info_list(i);
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	while (1)
	{
		std::string input;
		std::cout << "[SEARCH] > ";
		std::getline(std::cin, input);
		if (input == "Q" || input == "q")
			break;
		if (input > "0" && input <= std::to_string(_id))
		{
			for (int i = 0; i < _line; ++i)
			{
				this->contact[i].get_info_full(input);
			}	
		}
		else
			std::cout << "please input one of index, or, 'q' or 'Q' to quit search command."  << std::endl;
	}	
}

void	PhoneBook::cmd_exit()
{
	std::cout << "EXIT" << std::endl;
	PhoneBook::~PhoneBook();
	system ("leaks phonebook");
	exit (0);
}

