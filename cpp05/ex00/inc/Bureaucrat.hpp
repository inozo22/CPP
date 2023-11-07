/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:50:58 by nimai             #+#    #+#             */
/*   Updated: 2023/11/07 10:46:18 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

# include <string>

# define HIGHEST	1
# define LOWEST	150

class Bureaucrat
{
	private:
			std::string const _name;
			int	_grade;
	public:
			Bureaucrat( void );
			Bureaucrat( Bureaucrat const & src);
			Bureaucrat( std::string const & name, int grade );
			~Bureaucrat( void );

			Bureaucrat & operator=(const Bureaucrat &src);

			std::string const &	getName( void ) const;
			int	getGrade( void ) const;

			void	incrementGrade( void );
			void	incrementGrade( int i );
			void	decrementGrade( void );
			void	decrementGrade( int i );

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
};
std::ostream &	operator << (std::ostream & os, Bureaucrat const & obj);
#endif
