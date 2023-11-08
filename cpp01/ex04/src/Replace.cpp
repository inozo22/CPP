/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:03:55 by nimai             #+#    #+#             */
/*   Updated: 2023/11/08 15:34:56 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace( std::string filename, std::string s1, std::string s2 )
{
	if (s1.empty() || s2.empty())
		return ;
	this->_inFile = filename;
	this->_outFile = filename + ".replace";
	this->_target = s1;
	this->_replacement = s2;
	std::cout << "filename: " << _inFile << " target: " << _target << " replacement: " << _replacement << std::endl;
}

// Replace::Replace( char **av ) : _infile(av[1]), _target(av[2]), _replacement(av[3])
// {
// 	this->_outfile = this->_infile + ".replace";
// 	std::cout << "filename: " << _infile << " target: " << _target << " replacement: " << _replacement << std::endl;
// }

Replace::~Replace(void)
{	
	//std::cout << this->_filename << " has left from the field." << std::endl;
}

void	Replace::func( void )
{
	
	std::cout << "Im in func " << this->_inFile << std::endl;//print to check
	std::ifstream ifs(this->_inFile);

	if (!ifs.is_open())
	{
		std::cerr << "failed open file." << std::endl;
		//std::exit(1);
		//return (1);
	}
	else
	{
		std::string tmp;
		std::string str;
		while (std::getline(ifs, tmp, '\0'))
		{
			size_t pos = 0;
			std::cout << "1st tmp: " << tmp << "\n";
			while (pos <= tmp.length()/* pos += this->_replacement.length() */)
			{
				std::cout << "pos: " << pos << std::endl;
				pos = tmp.find(this->_target, pos);
				if (pos == std::string::npos)
				{
					std::cout << "break!" << std::endl;
					break ;
				}
				tmp.erase(pos, this->_target.length());
				tmp.insert(pos, this->_replacement);
			}
			std::cout << "2nd tmp: " << tmp << std::endl;
//			str += tmp;
		}
	//	std::ofstream ofs(this->_outfile);
		std::ofstream ofs;
		ofs.open(this->_outFile, std::ios::out);
		ofs << tmp;
		ofs.close();
	}
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
