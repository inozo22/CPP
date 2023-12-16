#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		for (int i = 1; i < ac; ++i)
		{
			for (int j = 0; av[i][j]; ++j)
			{
				char ch = std::toupper(av[i][j]);
				std::cout << ch;
			}
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return 0;
}
