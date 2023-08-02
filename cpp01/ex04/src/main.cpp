/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/08/01 17:26:34 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <fstream>
#include "Replace.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "you have to put for arguments as \"./replace <filename> s1 s2\"" << std::endl;
		//std::exit(1);
		return (1);
	}
	Replace replace(av[1], av[2], av[3]);
	replace.func();


/* 	std::ifstream ifs(av[1]);
	if (!ifs)
	{
		std::cerr << "failed open file." << std::endl;
		//std::exit(1);
		return (1);
	}
	std::string buf;
	std::string filename;
	std::string sur = ".replace";
	filename = av[1] + sur;
	ifs >> buf;
//	std::ofstream ofs(filename);
	std::ofstream ofs;

	//ofs.open(filename, std::ios::out);
	ofs.open(filename.c_str(), std::ios::out);//to compile in codespase
	//to read original file.
	if (!ifs)
	{
		std::cerr << "failed read file." << std::endl;
		//std::exit(1);
		return (1);
	}
	while (ifs)
	{
		ofs << buf << std::endl;
	//	std::cout << buf << std::endl;
		ifs >> buf;
	}
	ofs.close(); */
//	std::cout << "over the file." << std::endl;
	return (std::cout << "made it" << std::endl, 0);
	
}
