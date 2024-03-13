#include "PmergeMe.hpp"
#include <stdexcept>
#include <ctime>

//- - - Orthodox Canonical Form - - -//
PmergeMe::PmergeMe( void )
{
	// std::cout << "Default constructor called" << std::endl;

}
PmergeMe::~PmergeMe( void )
{
	// std::cout << "Destructor called" << std::endl;
	delete[] sequence;
}
PmergeMe::PmergeMe( PmergeMe & src )
{
	// std::cout << "Copy constructor called" << std::endl;
	if (this != &src)
	{
		this->size = src.size;
		this->sequence = new int[size];
		for (int i = 0; i < size; i++)
		{
			this->sequence[i] = src.sequence[i];
		}
	}
	return *this;
}
PmergeMe & PmergeMe::operator=( PmergeMe const & src )
{
	// std::cout << "Copy assigment operator called" << std::endl;
	if (this != &src)
	{
		this->~PmergeMe();
		new(this) PmergeMe(src);
	}
	return *this;
}
//- - - Orthodox Canonical Form - - -//

//- - - Constructor with parametor - - -//
PmergeMe::PmergeMe( int ac, char *av[] )
{
	if (ac < 2)
		throw std::invalid_argument("Please provide a positive integer sequence.");
	this->size = ac - 1;
	this->sequence = new int[size];
	for (int i = 1; 1 < ac; ++i)
	{
		std::stringstream ss(av[i]);
		if (!(ss >> sequence[i - 1]) || sequence[i - 1] < 0)
		{
//			std::cout << "Error: Invalid input. Please provide only positive integers." << std::endl;
			delete[] sequence;
			throw std::invalid_argument("Invalid input. Please provide only positive integers.");
		}
	}
}

//- - -     member function     - - -//
void    PmergeMe::sortProcess( void )
{

}
void    PmergeMe::printResult( void )
{

}

std::vector<int> PmergeMe::merge_insert_sort(int *sequence, int size, double & tmVector)
{
	clock_t start_time = clock();
	if (size <= 1)
	{
		std::vector<int> result(sequence, sequence + size);
		tmVector = double(clock() - start_time) / CLOCKS_PER_SEC * 1e6;
		return result;
	}
	int	mid = size / 2;
	std::vector<int> left = merge_insert_sort(sequence, mid, tmVector);
	std::vector<int> right = merge_insert_sort(sequence, size - mid, tmVector);

	std::vector<int> result;
	result.reserve(left.size() + right.size());

	size_t i = 0, j = 0;
	while (i < left.size() && j < right.size())
	{
		if (left[i] <= right[j])
			result.push_back(left[i++]);
		else
			result.push_back(right[j++]);
	}
	//20240313 until here
}

//- - -     member function     - - -//

