/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:05:37 by nimai             #+#    #+#             */
/*   Updated: 2023/07/25 15:06:26 by nimai            ###   ########.fr       */
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
}
