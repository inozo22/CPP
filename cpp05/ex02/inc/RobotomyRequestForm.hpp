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
	private:
	 		std::string 		_target;
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

			std::string const &		getTarget( void ) const;	
			void	beExecuted( void ) const;


};
std::ostream &	operator << (std::ostream & os, RobotomyRequestForm const & obj);
#endif
