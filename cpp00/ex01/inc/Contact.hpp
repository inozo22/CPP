/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:04:56 by nimai             #+#    #+#             */
/*   Updated: 2023/07/25 15:06:48 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CONTACT_HPP_
# define _CONTACT_HPP_

# include <string>
# include <iostream>
# include <iomanip>

class Contact
{
	public:
		Contact();
		~Contact();
		Contact(const Contact &src);
		Contact& operator = (const Contact &src);
		void	set_info(int &colum, std::string &input);
	//	void	get_info_head(int &index) const;
	//	void	get_info_index() const;
	private:
		std::string	info[5];
	
};

#endif
