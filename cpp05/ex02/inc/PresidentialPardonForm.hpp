/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:50:58 by nimai             #+#    #+#             */
/*   Updated: 2023/11/08 09:38:43 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	// private:
	// 		std::string const	_name;
	// 		bool				_signed;
	// 		int					_gradeToSign;
	// 		int					_gradeToExecute;
	public:
			PresidentialPardonForm( void );
			PresidentialPardonForm( PresidentialPardonForm const & src);
			PresidentialPardonForm::PresidentialPardonForm( std::string const & target );

			// PresidentialPardonForm( std::string const & name, int const gradeToSign, int const gradeToExecute );
			~PresidentialPardonForm( void );

			PresidentialPardonForm & operator=(const PresidentialPardonForm &src);

			// std::string const &	getName( void ) const;
			// int	getGradeToSign( void ) const;
			// int	getGradeToExecute( void ) const;

			AForm *	clone( void ) const;
			void	execute( Bureaucrat const & executor ) const;



};
std::ostream &	operator << (std::ostream & os, PresidentialPardonForm const & obj);
#endif
