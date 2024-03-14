#include "PmergeMe.hpp"
#include <stdexcept>
#include <ctime>
#include <sstream>
#include <iostream>
#include <iterator>
# include <iomanip>


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
	clock_t start_time;

	this->timeVector = 0.0;
	start_time = clock();
	this->sorted_vector = merge_insert_vector(this->sequence, this->size, this->timeVector);
	this->timeVector = double(clock() - start_time) / CLOCKS_PER_SEC * 1e6;

	this->timeDeque = 0.0;
	start_time = clock();
	this->sorted_deque = merge_insert_deque(this->sequence, this->size, this->timeDeque);
	this->timeDeque = double(clock() - start_time) / CLOCKS_PER_SEC * 1e6;
}
void    PmergeMe::printResult( void )
{
//Print original nunmber sequence
	std::cout << std::setfill(' ') << std::setw(20) << "Before: ";
	std::copy(this->sequence, this->sequence + this->size, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

//Print sorted nunmber sequence by vector
	std::cout << std::setfill(' ') << std::setw(20) << "After(with vector): ";
	std::copy(this->sorted_vector.begin(), this->sorted_vector.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
//Print sorted nunmber sequence by deque
	std::cout << std::setfill(' ') << std::setw(20) << "After(with deque): ";
	std::copy(this->sorted_deque.begin(), this->sorted_deque.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

//Print both time to took
	std::cout << "Time to process a range of " << std::setfill(' ') << std::setw(6) << this->size << " elements with std::vector : " << this->timeVector << " us" << std::endl;
	std::cout << "Time to process a range of " << std::setfill(' ') << std::setw(6) << this->size << " elements with std::deque  : " << this->timeDeque << " us" << std::endl;

}

std::vector<int> PmergeMe::merge_insert_vector(int *sequence, int size, double & tmVector)
{
//	clock_t start_time = clock();
	if (size <= 1)
	{
		std::vector<int> result(sequence, sequence + size);
//		tmVector = double(clock() - start_time) / CLOCKS_PER_SEC * 1e6;
		return result;
	}
	int	mid = size / 2;
	std::vector<int> left = merge_insert_vector(sequence, mid, tmVector);
	std::vector<int> right = merge_insert_vector(sequence + mid, size - mid, tmVector);

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

//	tmVector += double(clock() - start_time) / CLOCKS_PER_SEC * 1e6;
	return result;
}

std::deque<int> PmergeMe::merge_insert_deque(int *sequence, int size, double &tmDeque)
{
//	clock_t	start_time = clock();

	if (size <= 1)
	{
		std::deque<int> result(sequence, sequence + size);
//		tmDeque = double(clock() - start_time) / CLOCKS_PER_SEC * 1e6;
		return result;
	}
	int	mid = size / 2;
	std::deque<int> left = merge_insert_deque(sequence, mid, tmDeque);
	std::deque<int> right = merge_insert_deque(sequence + mid, size - mid, tmDeque);
	std::deque<int> result;

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
//	tmDeque += double(clock() - start_time) / CLOCKS_PER_SEC * 1e6;
	return result;
}
//- - -     member function     - - -//
