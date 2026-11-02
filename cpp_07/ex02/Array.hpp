/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:27:21 by darismen          #+#    #+#             */
/*   Updated: 2025/08/04 20:08:52 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T>
class Array
{
	private:
		T *_array;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &src);
		~Array();
		Array &operator = (const Array &rhs);
		T &operator [] (unsigned int index) const;
		unsigned int size() const;
		T *getArray(void) const;
		// int *getSize(void) const;
		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

template <class T>
std::ostream &operator << (std::ostream &out, const Array<T> &arr);


#include "Array.tpp"


/* template <class T>
class Array
{
	private:
		T *_array;
		unsigned int _size;
	public:
		Array() : _array(new T[_size]), _size(0) {}
		Array(unsigned int n) : _array(new T[n]), _size(n) {}
		Array(const Array &src) : _array(new T[src._size]), _size(src._size)
		{
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = src._array[i];
		}
		~Array() { delete [] _array; }
		Array &operator = (const Array &rhs) 
		{
			if (this == &rhs)
				return *this;
			delete [] _array;
			_array = new T[rhs._size];
			_size = rhs._size;
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = rhs._array[i];
			return *this;
		}
		T &operator [] (unsigned int index)
		{
				if (index < this->_size)
					return this->_array[index];
				else
					throw OutOfBoundsException();
		}

		unsigned int size() const { return this->_size; }
		
		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Out of bounds";
				}
		};
		
		T *getArray() { return this->_array; }
};

template<typename T>
std::ostream	&operator<<(std::ostream &os, Array<T> &rhs)
{
	int size;

	size = rhs.size();
	os << "{";
	for (int i = 0; i < size - 1; i++)
		os << rhs.getArray()[i] << ", ";
	os << rhs.getArray()[size - 1] << "}";
	return (os);
} */

#endif