/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:50:58 by nimai             #+#    #+#             */
/*   Updated: 2023/11/07 12:55:23 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
# define __FORM_HPP__

# include <string>
# include "Bureaucrat.hpp"

class Form
{
	private:
			std::string const	_name;
			bool				_signed;
			int					_gradeToSign;
			int					_gradeToExecute;
	public:
			Form( void );
			Form( Form const & src);
			Form( std::string const & name, int grade );
			~Form( void );

			Form & operator=(const Form &src);

			std::string const &	getName( void ) const;
			int	getGradeToSign( void ) const;
			int	getGradeToExecute( void ) const;

			void	beSigned( Bureaucrat const & bureaucrat);
			// void	incrementGrade( void );
			// void	incrementGrade( int i );
			// void	decrementGrade( void );
			// void	decrementGrade( int i );

			class GradeTooHighException : public std::exception
			{
				public:
						virtual const char * what( void ) const throw();
			};
			class GradeTooLowException : public std::exception
			{
				public:
						virtual const char * what( void ) const throw();
			};
			class SignedException : public std::exception
			{
				public:
						virtual const char * what( void ) const throw();
			};
};
std::ostream &	operator << (std::ostream & os, Form const & obj);
#endif
