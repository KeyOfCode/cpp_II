/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:09:56 by darismen          #+#    #+#             */
/*   Updated: 2025/09/14 17:09:16 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <ranges>


typedef std::vector<int>::iterator iter;

class Span
{
	private:
		unsigned int _N;
		std::vector<int> _numbers;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &src);
		Span &operator = (const Span &rhs);
		~Span();
		void addNumber(int n);
		void addNumber(iter begin, iter end);
		unsigned int getN(void) const;
		std::vector<int> getNumbers(void) const;
		int shortestSpan();
		int longestSpan();
		class MaxMembersException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class NoSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v);

std::ostream &operator << (std::ostream &os, Span const &a);


#endif