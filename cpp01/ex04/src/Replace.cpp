/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:03:55 by nimai             #+#    #+#             */
/*   Updated: 2023/12/19 12:07:55 by nimai            ###   ########.fr       */
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

Replace::~Replace(void)
{	
	//std::cout << this->_filename << " has left from the field." << std::endl;
}

void	Replace::func( void )
{
	
	// std::cout << "Im in func " << this->_inFile << std::endl;//print to check
	std::ifstream ifs(this->_inFile);

	if (!ifs.is_open())
	{
		std::cerr << "failed open file." << std::endl;
	}
	else
	{
		std::string tmp;
		std::string str;
		while (std::getline(ifs, tmp, '\0'))
		{
			size_t pos = 0;
			while (pos <= tmp.length())
			{
				pos = tmp.find(this->_target, pos);
				if (pos == std::string::npos)
				{
					// std::cout << "break!" << std::endl;
					break ;
				}
				tmp.erase(pos, this->_target.length());
				tmp.insert(pos, this->_replacement);
			}
		}
		std::ofstream ofs;
		ofs.open(this->_outFile, std::ios::out);
		ofs << tmp;
		ofs.close();
	}
}
