/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:59:47 by nimai             #+#    #+#             */
/*   Updated: 2024/02/27 12:05:35 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <bitset>

//===Color font code===/
#define BLACK   "\x1B[30m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1B[37m"
#define ORANGE  "\x1B[38;2;255;128;0m"
#define ROSE    "\x1B[38;2;255;151;203m"
#define LBLUE   "\x1B[38;2;53;149;240m"
#define LGREEN  "\x1B[38;2;17;245;120m"
#define GRAY    "\x1B[38;2;176;174;174m"
#define RESET   "\x1b[0m"

#define INT_OVER (1<<0) // 0000 0000 0000 0001
#define CHAR_OVER (1<<2) // 0000 0000 0000 0100
#define CHAR_UNPRI (1<<4) // 0000 0000 0001 0000
#define HAS_TYPE (1<<6) // 0000 0000 0100 0000
#define IS_CHAR (1<<8) // 0000 0001 0000 0000
//#define IS_DOUBLE (1<<10) // 0000 0100 0000 0000

class ScalarConverter
{
    public:
		~ScalarConverter( void );
		static void	convert(std::string const & input);


		class NonConvertableException : public std::exception
		{
			public:
				virtual const char * what( void ) const throw();
		};
		class ImpossibleConvertException : public std::exception
		{
			public:
				virtual const char * what( void ) const throw();
		};
		class NonDisplableException : public std::exception
		{
			public:
				virtual const char * what( void ) const throw();
		};

	private:
		ScalarConverter( void );
		ScalarConverter( ScalarConverter const & input );
		ScalarConverter & operator=(const ScalarConverter & src);

		static void	convertToChar( std::string const & input );
		static void	convertToInt( std::string const & input );
		static void	convertToDouble( std::string const & input );
		static void	convertToFloat( std::string const & input );
		static bool	checkInt( std::string const & str );
		static bool	checkFloat( std::string const & str );
		static bool	checkDouble( std::string const & str );
		static bool	checkChar( std::string const & str );
		static int	bitFlag;

};


#endif

//1. detect the type of the literal passed as parameter

//2. convert it from string to its actual type, then convert it explicitly to the three other data types

//3. display the results as shown below
/* 
./convert 0
char: Non displayable
int: 0
float: 0.0f 
double: 0.0
./convert nan 
char: impossible
int: impossible
float: nanf
double: nan 
./convert 42.0f
char: '*'
int: 42
float: 42.0f double: 42.0 
*/
