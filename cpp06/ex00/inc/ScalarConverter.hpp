/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:59:47 by nimai             #+#    #+#             */
/*   Updated: 2023/11/30 11:38:39 by nimai            ###   ########.fr       */
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


//		const uint32_t BIT_FLAG_0 (1<<0); // 0000 0001
//		const uint32_t BIT_FLAG_2 (1<<2); // 0000 0100
//		const uint32_t BIT_FLAG_4 (1<<4); // 0001 0000
		const uint32_t INT_OVER (1<<0); // 0000 0001
		const uint32_t CHAR_OVER (1<<2); // 0000 0100
		const uint32_t CHAR_UNPRI (1<<4); // 0001 0000

class ScalarConverter
{
    public:
		ScalarConverter( void );
		ScalarConverter( ScalarConverter const & src );
		ScalarConverter( std::string const & str );
		~ScalarConverter( void );

		ScalarConverter & operator=(const ScalarConverter & src);

		char	getChar( void ) const;
		int		getInt( void ) const;
		float	getFloat( void ) const;
		double	getDouble( void ) const;
		int		getType( void ) const;

		class NonConvertableException : public std::exception
		{
			public:
				virtual const char * what( void ) const throw();
		};
		int		bitFlag;

		

	private:

		char	_isChar;
		int		_isInt;
		float	_isFloat;
		double	_isDouble;
		int		_type;

		void	_scalarConversion(std::string const & str);
		void	_typeCheck( std::string const & str );
		bool	_checkInt( std::string const & str );
		bool	_checkFloat( std::string const & str );
		bool	_checkDouble( std::string const & str );
		bool	_checkChar( std::string const & str );
		void	_convertFromChar( void );
		void	_convertFromInt( void );
		void	_convertFromDouble( void );
		void	_convertFromFloat( void );

		enum	e_type
		{
			DEFAULT = 0,
			INT,
			FLOAT,
			DOUBLE,
			CHAR,
			OTHER
		};

};

std::ostream &	operator << (std::ostream & os, ScalarConverter const & obj);

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
