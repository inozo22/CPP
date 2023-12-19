/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/12/19 12:06:43 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "Replace.hpp"

int	main( void )
{
	std::ofstream writing_file;
	std::string file_name = "sample.txt";
	std::string writing_text;
	
	std::cout << GREEN ">>>>>>>>>> MY TEST1 <<<<<<<<<<" CLEAR << std::endl;

	writing_file.open(file_name, std::ios::out);
	writing_text = "C++ (C++) is a general-purpose programming language.\nIt is commonly referred to as 'C pula pula' or 'C pula' among Japanese speakers.";
	writing_file << writing_text << std::endl;

	writing_file.close();

	Replace	replace(file_name, "C", "D");
	replace.func();

	std::ofstream writing_file2;
	std::string file_name2 = "test.txt";
	std::string writing_text2;
	
	std::cout << GREEN ">>>>>>>>>> MY TEST2 <<<<<<<<<<" CLEAR << std::endl;

	writing_file2.open(file_name2, std::ios::out);
	writing_text2 = "a\nbattlecc\ndefinef\ngetTypeh\nIj\nk\nL\n\nOhayougozaimasu\nKonnichiwa\n\nLDLIBS\nyouy\n\nyouy\nyou\n";
	writing_file2 << writing_text2 << std::endl;

	writing_file2.close();

	Replace	replace2(file_name2, "you", "hohoho");
	replace2.func();	

	return (0);
}

// int	main(int ac, char **av)
// {
// 	if (ac != 4)
// 	{
// 		std::cerr << "you have to put for arguments as \"./replace <filename> s1 s2\"" << std::endl;
// 		//std::exit(1);
// 		return (1);
// 	}
// 	Replace replace(av[1], av[2], av[3]);
// 	replace.func();


// /* 	std::ifstream ifs(av[1]);
// 	if (!ifs)
// 	{
// 		std::cerr << "failed open file." << std::endl;
// 		//std::exit(1);
// 		return (1);
// 	}
// 	std::string buf;
// 	std::string filename;
// 	std::string sur = ".replace";
// 	filename = av[1] + sur;
// 	ifs >> buf;
// //	std::ofstream ofs(filename);
// 	std::ofstream ofs;

// 	//ofs.open(filename, std::ios::out);
// 	ofs.open(filename.c_str(), std::ios::out);//to compile in codespase
// 	//to read original file.
// 	if (!ifs)
// 	{
// 		std::cerr << "failed read file." << std::endl;
// 		//std::exit(1);
// 		return (1);
// 	}
// 	while (ifs)
// 	{
// 		ofs << buf << std::endl;
// 	//	std::cout << buf << std::endl;
// 		ifs >> buf;
// 	}
// 	ofs.close(); */
// //	std::cout << "over the file." << std::endl;
// 	return (std::cout << "made it" << std::endl, 0);
	
// }
