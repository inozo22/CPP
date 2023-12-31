/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:05:51 by nimai             #+#    #+#             */
/*   Updated: 2023/12/16 11:16:14 by nimai            ###   ########.fr       */
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
		_pos = 0;
	std::string input;
	int	i = 0;
	while (i < 5)
	{
		std::cout << "[ADD] " << std::setfill(' ') << std::setw(15);
		std::cout << heads[i] << " > ";
		if (!std::getline(std::cin, input))
		{
			std::cout << "in cmd_add: " << COLOR_RED "Please don't send eof!!!!" COLOR_RESET << std::endl;
			break ;
		}
		if (!input.length() || (input.find_first_not_of("\t\v\n\r\f ") == std::string::npos))
			std::cout << "CAUTION! Input field is empty, please fill it." << std::endl;
		else if (input.find_first_of("\t\v\n\r\f ") != std::string::npos)
			std::cout << "CAUTION! You are using inappropriate space." << std::endl;
		else if (i == 3 && (input.find_first_of("0123456789-") == std::string::npos))
			std::cout << "CAUTION! Only numeric letter and '-' are required." << std::endl;
		else
		{	
			this->contact[_pos].set_info(i, input);
			i++;
		}
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
	std::cout << "|     index|first name| last name| nick name|\n";
	std::cout << "+----------+----------+----------+----------+\n";
	for (int i = 0; i < _line; ++i)
	{
		this->contact[i].get_info_list(i);
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	while (1)
	{
		int	ret = 0;
		std::string input;
		std::cout << "[SEARCH] > ";
		if (!std::getline(std::cin, input))
		{
			std::cout << "in cmd_search: " << COLOR_RED "Please don't send eof!!!!" COLOR_RESET << std::endl;
			break ;
		}
		if (input == "Q" || input == "q")
			break;
		for (int i = 0; i < _line; ++i)
			ret += this->contact[i].get_info_full(input);
		if (ret == _line)
			std::cout << USAGE_SEARCH << std::endl;
	}	
}

void	PhoneBook::cmd_exit()
{
	std::cout << "EXIT" << std::endl;
	PhoneBook::~PhoneBook();
	exit (0);
}
