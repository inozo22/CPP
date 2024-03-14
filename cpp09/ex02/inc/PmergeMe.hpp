#ifndef PMERGEME_HPP
# define PMERGEME_HPP

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

# include <deque>
# include <vector>
# include <string>

class PmergeMe
{
	public:
//- - - Orthodox Canonical Form - - -//
			PmergeMe( void );
			~PmergeMe( void );
			PmergeMe( PmergeMe const & src );
			PmergeMe & operator=( PmergeMe const & src );
//- - - Orthodox Canonical Form - - -//
			PmergeMe( int ac, char **av );

//- - -     member function     - - -//
			void    sortProcess( void );
			void    printResult( void );
//- - -     member function     - - -//

	private:
			int		*sequence;
			int		size;
			double	timeVector;
			double	timeDeque;
			std::vector<int> sorted_vector;
			std::deque<int> sorted_deque;

//- - -     member function     - - -//
			std::vector<int>	merge_insert_vector(int *sequence, int size);
			std::deque<int>		merge_insert_deque(int *sequence, int size);
			bool				isNumber( const std::string & token);

//- - -     member function     - - -//



};

#endif // PMERGEME_HPP
