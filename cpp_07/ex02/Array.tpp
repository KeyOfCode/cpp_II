/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:32:59 by darismen          #+#    #+#             */
/*   Updated: 2025/08/04 20:09:20 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP
#include "Array.hpp"

template <class T>
class Array;

template <class T>
Array<T>::Array() : _array(new T()), _size(0) {}

template <class T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <class T>
Array<T>::Array(const Array &src) : _array(new T[src._size]), _size(src._size)
{
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = src._array[i];
}

template <class T>
Array<T>::~Array() { delete [] _array; }

template <class T>
unsigned int Array<T>::size() const { return _size; }

template <class T>
T	*Array<T>::getArray(void) const { return (this->_array); }

template <class T>
const char * Array<T>::OutOfBoundsException::what() const throw()
{
	return "\033[0;31mIndex out of bounds!!\033[0m";
}

template <class T>
Array<T> &Array<T>::operator = (const Array &rhs) 
{
	if (this != &rhs)
	{
		delete [] _array;
		_size = rhs._size;
		_array = new T[rhs._size];
		for (int i = 0; i < _size; i++)
			_array[i] = rhs._array[i];
	}
	return *this;
}

template <class T>
T &Array<T>::operator [] (unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _array[index];
}


template <class T>
std::ostream &operator << (std::ostream &out, const Array<T> &arr)
{
	out << "[";
	for (unsigned int i = 0; i < arr.size(); i++)
	{
		out << arr[i];
		if (i < arr.size() - 1)
			out << ", ";
	}
	out << "]";
	return out;
}


#endif