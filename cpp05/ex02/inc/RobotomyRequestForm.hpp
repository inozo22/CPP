/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:05:04 by nimai             #+#    #+#             */
/*   Updated: 2023/11/09 16:49:41 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	// private:
	// 		std::string const	_name;
	// 		bool				_signed;
	// 		int					_gradeToSign;
	// 		int					_gradeToExecute;
	public:
			RobotomyRequestForm( void );
			RobotomyRequestForm( RobotomyRequestForm const & src);
			// RobotomyRequestForm( std::string const & name, int const gradeToSign, int const gradeToExecute );
			RobotomyRequestForm( std::string const & target );

			~RobotomyRequestForm( void );

			RobotomyRequestForm & operator=(const RobotomyRequestForm &src);

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
std::ostream &	operator << (std::ostream & os, RobotomyRequestForm const & obj);
#endif
