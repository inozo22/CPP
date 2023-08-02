/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:03:55 by nimai             #+#    #+#             */
/*   Updated: 2023/08/01 16:34:41 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace( std::string filename, std::string s1, std::string s2 )
{
	this->_infile = filename;
	this->_outfile = filename + ".replace";
	this->_target = s1;
	this->_replacement = s2;
	std::cout << "filename: " << _infile << " target: " << _target << " replacement: " << _replacement << std::endl;
}

Replace::~Replace(void)
{	
	//std::cout << this->_filename << " has left from the field." << std::endl;
}

void	Replace::func( void )
{
//	size_t pos = 0;
	std::cout << "Im in func " << this->_infile << std::endl;//print to check
	std::ifstream ifs(this->_infile);

/* I cannot compile in codespaces, but I think it's fine */


/* 	if (!ifs)
	{
		std::cerr << "failed open file." << std::endl;
		//std::exit(1);
		//return (1);
	}
	else
	{
		std::string tmp;
		std::string str;
		while (getline(ifs, tmp))
		{
			std::cout << tmp << "\n";
			while (pos += this->_replacement.length())
			pos = tmp.find(this->_target, pos);
			if (pos == std::string::npos)
			{
				break ;
			}
			tmp.erase();
			tmp.insert();
			std::cout << tmp << std::endl;
			str += tmp;
		}
	//	std::ofstream ofs(this->_outfile);
		std::ofstream ofs;
		ofs.open(_outfile, std::ios::out);
		ofs << str;
		ofs.close();
	} */
}




//make all of above as required in c++

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

// void	HumanA::attack( void )
// {
// 	std::cout << this->name << " has attacked with his " << this->weapon.getType() << std::endl;
// }
