#ifndef EASYFIND_HPP
# define EASYFIND_HPP

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

# include <stdexcept>
# include <algorithm>
# include <iterator>

template <typename T>
typename T::const_iterator	easyfind(T const & container, int element)
{
	typename T::const_iterator	iter;

	iter = std::find(container.begin(), container.end(), element);
	if (iter == container.end())
	{
		throw(std::out_of_range("Element is out of range."));
	}
	return (iter);
}



#endif
