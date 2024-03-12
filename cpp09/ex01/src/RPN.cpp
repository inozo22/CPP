#include "RPN.hpp"
#include <sstream>
#include <stack>
#include <iostream>
#include <cstdlib>

//- - - Orthodox Canonical Form - - -//
RPN::RPN( void )
{
	// std::cout << "Default constructor called" << std::endl;
}
RPN::~RPN( void )
{
	// std::cout << "Destructor called" << std::end;
}
RPN::RPN( RPN & src ) : _input(src._input)
{
	// std::cout << "Copy constructor called" << std::endl;
}
RPN & RPN::operator=( RPN const & src )
{
	// std::cout << "Copy assigment operator called" << std::endl;
	if (this != &src)
		this->_input = src._input;
	return (*this);
}
//- - - Orthodox Canonical Form - - -//

//- - - Constructor with parametor - - -//
RPN::RPN( const std::string & input ): _input(input)
{
	// std::cout << "Constructor called with parametor: " << input << std::endl;
}
//- - - Constructor with parametor - - -//


//- - - Main member function - - -//
int RPN::evaluate( void )
{
	std::stack<int> stack;

	std::istringstream iss(this->_input);
	std::string token;

	try
	{
		while (iss>>token)
		{
			if (token.find_first_not_of("\t\v\n\r\f ") == std::string::npos)
				continue ;
			if (isNumber(token))
				stack.push(std::atoi(token.c_str()));
			else if (isOperator(token))
			{
				if (stack.size() < 2)
					errorControl("Insufficient operands for operator " + token);
				int operand2 = stack.top();
				stack.pop();
				int operand1 = stack.top();
				stack.pop();
				int result = calculation(operand1, operand2, token);
				stack.push(result);
			}
			else
				throw errorException(/*"Invalid token " + token*/);
		}
		if (stack.size() != 1)
			throw errorException(/*"Invalid input"*/);
		return stack.top();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << RESET << "\n";
		exit (1);
	}
	return 0;
}

//- - - Main member function - - -//

//- - - Member functions - - -//
bool	RPN::isOperator( const std::string & token)
{
	return token == "+" || token == "-" || token == "*" || token == "/";
}
bool	RPN::isNumber( const std::string & token)
{
	return std::isdigit(token[0]);
}
int		RPN::calculation( int num1, int num2, const std::string & op )
{
	switch (op.c_str()[0])
	{
		case '+': return num1 + num2;
		case '-': return num1 - num2;
		case '*': return num1 * num2;
		case '/': if (num2 != 0){
		return num1 / num2;
		}
		else
			throw errorException(/*"Division by zero"*/);
		default: throw errorException(/*"some error"*/);
			break ;
	}
	return 0;

}
void	RPN::errorControl( const std::string & comment)
{
	std::cerr << /*"Error: " <<*/ comment << "\n";
}
//- - - Member functions - - -//

//const char	*	RPN::errorException::what(void) const throw()
//{
//	return ("");
//}
const char	*	RPN::errorException::what(void) const throw()
{
	return ("Error");
}
