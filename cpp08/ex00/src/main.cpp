#include "easyfind.hpp"
#include <vector>
#include <iostream>


//template<typename T>
template<typename T>
void	searcher(std::string type, T & container, int num)
{
//	int	ret = 0;
	std::cout << CYAN "function searcher: searching for " << num << RESET << std::endl;
	std::cout << "Container type: " << type << std::endl;
	for (typename T::iterator iter = container.begin(); iter != container.end(); iter++)
	{
		if (*iter == num)
		{
			std::cout << *iter << std::endl;
		}
	}

}



int	main( void )
{
	
	std::cout << GREEN "<<<<<TEST<<<<<" RESET << std::endl;
	std::vector<int>	container;
	
	std::cout << "Vector container: ";
	for (std::vector<int>::iterator iter = container.begin(); iter != container.end(); ++iter)
	{
		std::cout << "[" << *iter << "]";
	}
	std::cout << std::endl;

	::searcher("Vector", container, 0);
	std::cout << std::endl;
	return (0);
}