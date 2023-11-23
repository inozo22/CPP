/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:50:58 by nimai             #+#    #+#             */
/*   Updated: 2023/11/14 17:34:14 by nimai            ###   ########.fr       */
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
	private:
			static std::string const _shrubbery;
			std::string _target;
	public:
			ShrubberyCreationForm( void );
			ShrubberyCreationForm( ShrubberyCreationForm const & src);
			// ShrubberyCreationForm( std::string const & name, int const gradeToSign, int const gradeToExecute );
			ShrubberyCreationForm( std::string const & target );

			~ShrubberyCreationForm( void );

			ShrubberyCreationForm & operator=(const ShrubberyCreationForm &src);

			std::string const &		getTarget( void ) const;	
			void	beExecuted( void ) const;
};
// std::ostream &	operator << (std::ostream & os, ShrubberyCreationForm const & obj);
#endif
