/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:37:11 by nimai             #+#    #+#             */
/*   Updated: 2023/07/26 11:51:56 by nimai            ###   ########.fr       */
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
		std::getline(std::cin, cmd);

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
