/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:37:11 by nimai             #+#    #+#             */
/*   Updated: 2023/07/25 11:49:34 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

int	main()
{
	PhoneBook	phonebook;
	std::string	cmd;

	while (1)
	{
		std::cout << PHONEBOOK;
		std::cin >> cmd;

		if (cmd == "ADD")
		{
			phonebook.cmd_add();
		}
		else if (cmd == "SEARCH")
		{
			phonebook.cmd_search();
		}
		else if (cmd == "EXIT")
		{
			phonebook.cmd_exit();
		}
		else
			std::cout << "USAGE: ADD / SEARCH / EXIT" << std::endl;
	}

	
//	CSample obj1, obj2;
//	int num;
//	Sample s;
	
//	s.a = 1;
//	s.b = 1;
//	s.func1();
//	s.func2();
//	std::string s;

	// s = "This is a";
	// s.append(" pen.");
	// std::cout << s << std::endl;
	// std::cout << "length of the string: " << s.length() << std::endl;
	
	// printf("char*: %s\n", s.c_str());
	

//	std::cout << "input number:" << std::endl;
//	std::cin >> num;

	// obj1.set(1);
	// obj2.set(2);
	// std::cout << obj1.get() << std::endl;
	// std::cout << obj2.get() << std::endl;
	
	return 0;
}
