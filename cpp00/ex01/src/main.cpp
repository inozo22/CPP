/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:37:11 by nimai             #+#    #+#             */
/*   Updated: 2023/10/24 12:30:27 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phonebook;
	std::string	cmd;

	while (1)
	{
		std::cout << PHONEBOOK;
		if (!std::getline(std::cin, cmd))
		{
			std::cout << COLOR_RED"Please don't send eof!!!!" << COLOR_RESET << std::endl;
			return (1);
		}
		if (cmd == "ADD")
			phonebook.cmd_add();
		else if (cmd == "SEARCH")
			phonebook.cmd_search();
		else if (cmd == "EXIT")
			phonebook.cmd_exit();
		else
			std::cout << USAGE << std::endl;
	}
	return 0;
}
