#include "PmergeMe.hpp"
#include <stdexcept>
#include <ctime>
#include <sstream>
#include <iostream>
#include <iterator>
# include <iomanip>

//- - - Orthodox Canonical Form - - -//
PmergeMe::PmergeMe( void ): sequence(NULL), size(0)
{
	// std::cout << "Default constructor called" << std::endl;
}
PmergeMe::~PmergeMe( void )
{
//	std::cout << "Destructor called" << std::endl;
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
//	std::cout << "Constructor called with parametor" << std::endl;
	if (ac < 2)
		throw std::invalid_argument("Please provide a positive integer sequence.");
	this->size = ac - 1;
	this->sequence = new int[this->size];
	for (int i = 1; i < ac; ++i)
	{
		std::string token = av[i];
		std::stringstream ss(av[i]);
		if (!this->isNumber(token) || !(ss >> sequence[i - 1]) || sequence[i - 1] < 0)
		{
			delete[] sequence;
			throw std::invalid_argument("Invalid input. Please provide only positive integers.");
		}
	}
}

//- - -     member function     - - -//
void    PmergeMe::sortProcess( void )
{
	clock_t start_time;

	this->timeVector = 0.0;
	start_time = clock();
	this->sorted_vector = merge_insert_vector(this->sequence, this->size);
	this->timeVector = double(clock() - start_time) / CLOCKS_PER_SEC * 1e6;

	this->timeDeque = 0.0;
	start_time = clock();
	this->sorted_deque = merge_insert_deque(this->sequence, this->size);
	this->timeDeque = double(clock() - start_time) / CLOCKS_PER_SEC * 1e6;
}

void    PmergeMe::printResult( void )
{
//Print original nunmber sequence
	std::cout << std::setfill(' ') << GREEN << std::setw(20) << "Before: ";
	std::copy(this->sequence, this->sequence + this->size, std::ostream_iterator<int>(std::cout, " "));
	std::cout << RESET << std::endl;

//Print sorted nunmber sequence by vector
	std::cout << std::setfill(' ') << GREEN << std::setw(20) << "After(with vector): ";
	std::copy(this->sorted_vector.begin(), this->sorted_vector.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << RESET << std::endl;
//Print sorted nunmber sequence by deque
	std::cout << std::setfill(' ') << GREEN << std::setw(20) << "After(with deque): ";
	std::copy(this->sorted_deque.begin(), this->sorted_deque.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << RESET << std::endl;

//Print both time to took
	std::cout << "Time to process a range of " << std::setfill(' ') << std::setw(6) << this->size << " elements with std::vector : " << this->timeVector << " us" << std::endl;
	std::cout << "Time to process a range of " << std::setfill(' ') << std::setw(6) << this->size << " elements with std::deque  : " << this->timeDeque << " us" << std::endl;
}

std::vector<int> PmergeMe::merge_insert_vector(int *sequence, int size)
{
	if (size <= 1)
	{
		std::vector<int> result(sequence, sequence + size);
		return result;
	}
	int	mid = size / 2;

	//Split data columns.
	std::vector<int> left = merge_insert_vector(sequence, mid);
	std::vector<int> right = merge_insert_vector(sequence + mid, size - mid);
	std::vector<int> result;

	//Before merge step, allocate memory to avoid reallocate mamory multiple times.  
	result.reserve(left.size() + right.size());

	//Merge phase
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
	return result;
}

std::deque<int> PmergeMe::merge_insert_deque(int *sequence, int size)
{
	if (size <= 1)
	{
		std::deque<int> result(sequence, sequence + size);
		return result;
	}
	int	mid = size / 2;

	//Split data columns.
	std::deque<int> left = merge_insert_deque(sequence, mid);
	std::deque<int> right = merge_insert_deque(sequence + mid, size - mid);
	std::deque<int> result;

	//Merge phase
	while (!left.empty() && !right.empty())
	{
		if (left.front() <= right.front())
		{
			result.push_back(left.front());
			left.pop_front();
		}
		else
		{
			result.push_back(right.front());
			right.pop_front();
		}
	}
	while (!left.empty())
	{
		result.push_back(left.front());
		left.pop_front();
	}
	while (!right.empty())
	{
		result.push_back(right.front());
		right.pop_front();
	}
	return result;
}

bool	PmergeMe::isNumber( const std::string & token)
{
	for (size_t i = 0; i < (token.size()); i++)
	{
		if (!std::isdigit(token[i]))
			return false;
	}
	return true;
}
//- - -     member function     - - -//
