/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:31:30 by darismen          #+#    #+#             */
/*   Updated: 2025/11/28 14:38:23 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ctime>
#include <iostream>
#include <vector>
#include <deque>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <cmath>



class PmergeMe
{
	public:
		
		typedef std::vector<int>	vector;
		typedef std::deque<int>		deque;
		
		typedef std::pair<vector, vector> pair_vec;
		typedef std::pair<deque, deque> pair_deq;
		
		typedef std::vector<std::vector<int> >	rec_vec;
		typedef std::deque<std::deque<int> >	rec_deq;
		
	private:
		vector		_original_vec;	// Original input data
		vector		_main_vec;		// Main sorted chain
		rec_vec		_pend_vec;		// Pending elements to be inserted
		
		deque		_original_deq;	// Original input data
		deque		_main_deq;		// Main sorted chain
		rec_deq		_pend_deq;		// Pending elements to be inserted
		
		int			_recursion;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe &rhs);

		const vector& getOriginalVec() const { return _original_vec; }
		const vector& getMainVec() const { return _main_vec; }
		
		const deque& getOriginalDeq() const { return _original_deq; }
		const deque& getMainDeq() const { return _main_deq; }
		
		void setRercursion(int value) { _recursion = value; }
		
		void load_vector(char** argv, int argc);
		void load_deque(char** argv, int argc);

		// VECTORS
		
		void FordJohnsonVec();

		void make_pairs_vec();
		void sort_pairs_vec(pair_vec *newpair);
		
		void make_pend_vec();
		void insert_pend_vec();

		// DEQUE

		void FordJohnsonDeq();
		
		void make_pairs_deq();
		void sort_pairs_deq(pair_deq *newpair);
		
		void make_pend_deq();
		void insert_pend_deq();
		
		void print_sequence(const vector& sequence);
		void print_sequence(const deque& sequence);
		
		class BadArgException : public std::exception
		{
			private:
				std::string _error;
			public:
				BadArgException(const std::string &msg): _error(msg)
					{_error = "\033[0;31m" + msg + "\033[0m";}
				virtual	~BadArgException() throw() {}
				virtual const char	*what(void)	const throw() {return (this->_error.c_str());}
		};
};

std::ostream &operator << (std::ostream &o, PmergeMe const &a);
std::ostream &operator << (std::ostream &o, std::vector<int> const &a);
std::ostream &operator << (std::ostream &o, std::deque<int> const &a);
