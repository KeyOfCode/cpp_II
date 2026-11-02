/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:27:16 by darismen          #+#    #+#             */
/*   Updated: 2025/09/14 17:07:26 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &src) : _N(src._N), _numbers(src._numbers) {*this = src;}

Span &Span::operator = (const Span &rhs)
{
	if (this != &rhs)
	{
		this->_N = rhs._N;
		this->_numbers = rhs._numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	try
	{
		if (this->_numbers.size() >= this->_N)
			throw MaxMembersException();
		this->_numbers.push_back(n);
	}
	catch (const Span::MaxMembersException &e)
	{	
		std::cerr << e.what()<<std::endl;
	}
}

void Span::addNumber(iter begin,iter end)
{
	try
	{
		if (end - begin + this->_numbers.size() > this->_N)
			throw MaxMembersException();
		this->_numbers.insert(this->_numbers.end(), begin, end);
	}
	catch (const Span::MaxMembersException &e)
	{	
		std::cerr << e.what()<<std::endl;
	}
}


int Span::shortestSpan()
{
	if (this->getNumbers().size() < 2)
		throw Span::NoSpanException();
	std::vector<int> sorted = this->getNumbers();
	std::sort(sorted.begin(), sorted.end());
	int min_span = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size(); i++)
	{
		if (min_span > sorted[i] - sorted[i- 1])
			min_span = sorted[i] - sorted[i- 1];
	}
	return min_span;
}

int Span::longestSpan()
{
	if (this->getNumbers().size() < 2)
		throw Span::NoSpanException();
	std::vector<int> sp = this->getNumbers();
	return (*std::max_element(sp.begin(), sp.end()) - 
			*std::min_element(sp.begin(), sp.end()));
}

std::vector<int> Span::getNumbers(void) const {return this->_numbers;} 

unsigned int Span::getN(void) const {return this->_N;}

const char* Span::MaxMembersException::what() const throw() {
	return "Cannot add more numbers, maximum capacity reached";
}

const char* Span::NoSpanException::what() const throw() {
	return "Cannot calculate span with less than 2 numbers";
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
	os << "{";
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
		os << *it;
		if (it + 1 != v.end())
			os << ", ";
	}
	os << "}";
	return os;
}

std::ostream &operator << (std::ostream &os, Span const &a)
{
	os << a.getNumbers() << ", N = " << a.getN();
	return os;
}