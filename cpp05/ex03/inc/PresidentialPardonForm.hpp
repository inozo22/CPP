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
	private:
			std::string			_target;
	public:
			PresidentialPardonForm( void );
			PresidentialPardonForm( PresidentialPardonForm const & src);
			PresidentialPardonForm( std::string const & target );

			~PresidentialPardonForm( void );

			PresidentialPardonForm & operator=(const PresidentialPardonForm &src);

			std::string const &		getTarget( void ) const;	
			void	beExecuted( void ) const;



};
// std::ostream &	operator << (std::ostream & os, PresidentialPardonForm const & obj);
#endif
