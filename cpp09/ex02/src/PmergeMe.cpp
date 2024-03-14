#include "PmergeMe.hpp"
#include <stdexcept>
#include <ctime>
#include <sstream>
#include <iostream>
#include <iterator>

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
PmergeMe::PmergeMe( PmergeMe const & src )
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
//	std::cout << "ac: " << ac << std::endl;
	if (ac < 2)
		throw std::invalid_argument("Please provide a positive integer sequence.");
	this->size = ac - 1;
//	std::cout << "size: " << this->size << std::endl;
	this->sequence = new int[this->size];
	for (int i = 1; i < ac; ++i)
	{
		std::stringstream ss(av[i]);
		if (!(ss >> sequence[i - 1]) || sequence[i - 1] < 0)
		{
//			std::cout << "Error: Invalid input. Please provide only positive integers." << std::endl;
			delete[] sequence;
			throw std::invalid_argument("Invalid input. Please provide only positive integers.");
		}
//		std::cout << "sequence: " << sequence[i - 1] << std::endl;
	}
}

//- - -     member function     - - -//
void    PmergeMe::sortProcess( void )
{
	double	tmVector = 0.0;
//	std::cout << "size before sort: " << size << std::endl;
	this->sorted_vector = merge_insert_sort(this->sequence, this->size, tmVector);
	std::cout << "Time for sorting with vector: " << tmVector << " us" << std::endl;
}
void    PmergeMe::printResult( void )
{
	std::cout << "Before: ";
	std::copy(this->sequence, this->sequence + this->size, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	std::cout << "After(with vector): ";
	std::copy(this->sorted_vector.begin(), this->sorted_vector.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

}

std::vector<int> PmergeMe::merge_insert_sort(int *sequence, int size, double & tmVector)
{
//	std::cout << BLUE "size before sort: " << size << RESET << std::endl;
	clock_t start_time = clock();
	if (size <= 1)
	{
//		std::cout << "HELLO!!! size: " << size << "sequence" << std::endl;
		for (int i = 0; i < size; i++)
			std::cout << sequence[i] << " ";
		std::cout << std::endl;
		std::vector<int> result(sequence, sequence + size);
		tmVector = double(clock() - start_time) / CLOCKS_PER_SEC * 1e6;
		return result;
	}
//	std::cout << "HELLO!!! size: " << size << "sequence" << std::endl;

	int	mid = size / 2;
	std::vector<int> left = merge_insert_sort(sequence, mid, tmVector);
	std::vector<int> right = merge_insert_sort(sequence + mid, size - mid, tmVector);

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
	while (i < left.size())
		result.push_back(left[i++]);
	while (j < right.size())
		result.push_back(right[j++]);

	tmVector += double(clock() - start_time) / CLOCKS_PER_SEC * 1e6;
	std::cout << "CHECK: ";
	std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	return result;
}

//- - -     member function     - - -//

