#include <iostream>

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		for (int i = 1; i < ac; ++i)
		{
			for (int j = 0; av[i][j]; ++j)
			{
				if (av[i][j] >= 97 && av[i][j] <= 122)
					av[i][j] -= 32;
				std::cout << (char)av[i][j];
			}
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return 0;
}
