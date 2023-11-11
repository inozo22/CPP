/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:50:58 by nimai             #+#    #+#             */
/*   Updated: 2023/11/09 17:08:07 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include "Bureaucrat.hpp"

# define SC_SIGN 145
# define SC_EXEC 137
# define RR_SIGN 72
# define RR_EXEC 45
# define PP_SIGN 25
# define PP_EXEC 5

class Bureaucrat;

class AForm
{
	// private:
	// 		std::string const	_name;
	// 		bool				_signed;
	// 		int					_gradeToSign;
	// 		int					_gradeToExecute;
	protected:
			std::string const	_name;
			bool				_signed;
			int					_gradeToSign;
			int					_gradeToExecute;
	public:
			AForm( void );
			AForm( AForm const & src);
			AForm( std::string const & name, int const gradeToSign, int const gradeToExecute );
			virtual ~AForm( void );

			AForm & operator=(const AForm &src);

			std::string const &	getName( void ) const;
			int	getGradeToSign( void ) const;
			int	getGradeToExecute( void ) const;

			void	beSigned( Bureaucrat const & bureaucrat);
			virtual void	execute( Bureaucrat const & bureaucrat ) const;

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
std::ostream &	operator << (std::ostream & os, AForm const & obj);
#endif
