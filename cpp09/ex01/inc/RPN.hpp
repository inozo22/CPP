#ifndef RPN_HPP
# define RPN_HPP

//===Color font code===/
# define BLACK   "\x1B[30m"
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define WHITE   "\x1B[37m"
# define ORANGE  "\x1B[38;2;255;128;0m"
# define ROSE    "\x1B[38;2;255;151;203m"
# define LBLUE   "\x1B[38;2;53;149;240m"
# define LGREEN  "\x1B[38;2;17;245;120m"
# define GRAY    "\x1B[38;2;176;174;174m"
# define RESET   "\x1b[0m"

# include <string>

class RPN
{
	public:
			~RPN( void );
			RPN( RPN & src );
			RPN & operator=( RPN const & src );
			RPN( const std::string & input );
			int evaluate( void );

	private:
			RPN( void );
			std::string _input;
			bool	isOperator( const std::string & token);
			bool	isNumber( const std::string & token);
			int		calculation( int num1, int num2, const std::string & op );
			void	errorControl( const std::string & comment);


};


#endif // RPN_HPP