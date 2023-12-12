#ifndef EASYFIND_HPP
# define EASYFIND_HPP

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
