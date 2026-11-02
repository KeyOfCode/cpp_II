/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:32:08 by darismen          #+#    #+#             */
/*   Updated: 2025/11/20 12:29:04 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <iterator>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
	typedef std::stack<T, Container> stack;
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;

	MutantStack() :stack () {}
	MutantStack(const MutantStack &src) : stack(src) {}
	~MutantStack() {}
	
	MutantStack &operator=(MutantStack const &src)
	{
		if (*this != src)
			*this = src;
		return (*this);
	}

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	
	const_iterator const_begin() { return this->c.begin(); }
	const_iterator const_end() { return this->c.end(); }
};

#endif