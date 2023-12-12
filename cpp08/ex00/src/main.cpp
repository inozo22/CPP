#include "easyfind.hpp"
#include <vector>
#include <iostream>


//template<typename T>

int	main( void )
{
	
	std::vector<int>	container;

	
	for (std::vector<int>::iterator iter = container.begin(); iter != container.end(); iter++)
	{
		std::cout << *iter;
	}
	std::cout << std::endl;
	return (0);
}