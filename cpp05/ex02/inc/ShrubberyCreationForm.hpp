/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:50:58 by nimai             #+#    #+#             */
/*   Updated: 2023/11/09 16:49:46 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	// private:
	// 		std::string const	_name;
	// 		bool				_signed;
	// 		int					_gradeToSign;
	// 		int					_gradeToExecute;
	public:
			ShrubberyCreationForm( void );
			ShrubberyCreationForm( ShrubberyCreationForm const & src);
			// ShrubberyCreationForm( std::string const & name, int const gradeToSign, int const gradeToExecute );
			~ShrubberyCreationForm( void );

			ShrubberyCreationForm & operator=(const ShrubberyCreationForm &src);

			AForm *	clone( void ) const;
			void	execute( Bureaucrat const & executor ) const;

			// std::string const &	getName( void ) const;
			// int	getGradeToSign( void ) const;
			// int	getGradeToExecute( void ) const;

			// void	beSigned( Bureaucrat const & bureaucrat);

			// class GradeTooHighException : public std::exception
			// {
			// 	public:
			// 			virtual const char * what( void ) const throw();
			// };
			// class GradeTooLowException : public std::exception
			// {
			// 	public:
			// 			virtual const char * what( void ) const throw();
			// };
			// class SignedException : public std::exception
			// {
			// 	public:
			// 			virtual const char * what( void ) const throw();
			// };
};
std::ostream &	operator << (std::ostream & os, ShrubberyCreationForm const & obj);
#endif
