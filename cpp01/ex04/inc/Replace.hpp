/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:08:19 by nimai             #+#    #+#             */
/*   Updated: 2023/08/03 10:19:18 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __REPLACE_HPP__
#define __REPLACE_HPP__

# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define RED "\033[1;31m"
# define CYAN "\033[1;36m"
# define GREEN "\033[1;32m"
# define CLEAR "\033[0m"

# include <string>
# include <iostream>
# include <iomanip>
# include <fstream>

class Replace {


public:

	Replace( std::string filename, std::string s1, std::string s2 );
//	Replace( char **av );
	~Replace( void );
	void	func( void );

private:
	std::string _inFile;
	std::string _outFile;
	std::string _target;
	std::string _replacement;

};


#endif
