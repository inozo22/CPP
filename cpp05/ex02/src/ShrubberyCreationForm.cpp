/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:51:13 by nimai             #+#    #+#             */
/*   Updated: 2023/11/14 17:38:06 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("shrubberycreationform", SC_SIGN, SC_EXEC) 
{
	std::cout << "ShrubberyCreationForm: Default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ):AForm("shrubberycreationform", SC_SIGN, SC_EXEC)
{
	std::cout << this->_name << "ShrubberyCreationForm: copy constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const & target ): AForm("ShrubberyCreationForm", SC_SIGN, SC_EXEC), _target(target)
{
	std::cout << "ShrubberyCreationForm: arrtibute constructor called." << std::endl;
	if (this->_target.empty())
		this->_target = "noname";
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << this->_name << ": Default destructor called." << std::endl;	
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &src )
{
	std::cout << "ShrubberyCreationForm assignment operator overload called." << std::endl;
	this->_target = src._target;
	return (*this);
}



void	ShrubberyCreationForm::beExecuted( void ) const
{
	std::ofstream ofs;
	ofs.open((this->_target + "_shrubbery").c_str(), std::ofstream::out | std::ofstream::app);
	if (ofs.is_open())
	{
		ofs << ShrubberyCreationForm::_shrubbery;
	}
}

std::string const &	ShrubberyCreationForm::getTarget( void ) const
{
	return (this->_target);
}

std::string const ShrubberyCreationForm::_shrubbery = 
"\n"
"          %%%%%% %\n"
"        %%% %%%%%%%%%%         %%%%%%%%%%\n"
"    %%%% % %%%%%%%%%%%%%      %%%%%%%%%%% %%% \n"
"      %% %   %% %%'           %%%%%%%% %%% \n"
"        % $  %  %% ¨¨¨¨¨¨¨¨¨¨¨¨ %%% %%¨¨¨¨¨'\n"
"                ''''''''''''''''''''''''''   '\n"
"                        $%%%%%%%$%%$%   '   '\n"
"                   $%%%%%%%%%%%%%%%%%%%%$%%$\n"
"   %$#%%%%%$%%%$%%%% ' %%%%%%%%$%%%%%%%%\n"
"    %%%%%%%%$%$%%%%%%  '   '     \n"
"  $%%%%%#%%%#$%%%%%%%%$%%  '\n"
"    $%%%%%%%%%%%%%%%%%$%%__'___________\n"
"              LLLLLLLLLLLLLLLLLLLLLL\n"
"                LLLLLLLLLLLLLLLLLLL\n"
"                LLLLLLLLLLLLLLLLLL\n"
"                LLLLLLLLLLLLLLLLLL\n"
"                LLLLLLLLLLLLLLLLLL\n"
"\n"
"\n";
