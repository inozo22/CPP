/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/07/31 15:58:31 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>


int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << std::left << std::setw(32) << "string memory address: " << &string << "\n";
	std::cout << std::left << std::setw(32) << "stringPTR memory address: " << stringPTR << "\n";
	std::cout << std::left << std::setw(32) << "stringREF memory address: " << &stringREF << std::endl;

	std::cout << std::left << std::setw(32) << "string value: " << string << "\n";
	std::cout << std::left << std::setw(32) << "stringPTR value: " << *stringPTR << "\n";
	std::cout << std::left << std::setw(32) << "stringREF value: " << stringREF << std::endl;
	return 0;
}
