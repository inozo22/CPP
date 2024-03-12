/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:01:25 by nimai             #+#    #+#             */
/*   Updated: 2024/03/11 09:26:26 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./btc < input file name >" << std::endl;
		return 1;
	}
	std::string inputFileName = argv[1];
	BitcoinExchange exchange("./database/data.csv");
	BitcoinExchange exchange2("./database/data2.csv");
//	BitcoinExchange exchange3(exchange);
	exchange2 = exchange;
	exchange2.processInputFile(inputFileName);

	return 0;
}
