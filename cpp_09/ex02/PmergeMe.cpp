/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:11:07 by darismen          #+#    #+#             */
/*   Updated: 2025/11/28 14:43:49 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src):
_original_vec(src._original_vec), _main_vec(src._main_vec),
_pend_vec(src._pend_vec), 
_original_deq(src._original_deq), _main_deq(src._main_deq),
_pend_deq(src._pend_deq), 
_recursion(src._recursion) {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this == &rhs)
		return *this;
		
	this->_original_vec = rhs._original_vec;
	this->_main_vec = rhs._main_vec;
	this->_pend_vec = rhs._pend_vec;
	this->_original_deq = rhs._original_deq;
	this->_main_deq = rhs._main_deq;
	this->_pend_deq = rhs._pend_deq;
	this->_recursion = rhs._recursion;
	
	return *this;
}

void PmergeMe::load_vector(char **argv, int argc)
{
	this->_recursion = 1;
	for (int i = 1; i < argc; i++)
	{	
		if (atoi(argv[i]) < 0)
			{throw BadArgException("Negative Input"); }
		this->_original_vec.push_back(atoi(argv[i]));
	}
}

void PmergeMe::load_deque(char **argv, int argc)
{
	this->_recursion = 1;
	for (int i = 1; i < argc; i++)
	{	
		if (atoi(argv[i]) < 0)
			{throw BadArgException("Negative Input"); }
		this->_original_deq.push_back(atoi(argv[i]));
	}
}

#pragma region Max Size

int max_size(int size)
{
	if (size <= 1) return 1;
	
	int levels = 0;
	int temp = size;
	while (temp > 1) {
		temp /= 2;
		levels++;
	}
	
	return std::min(levels, 12);
}

int Jacobsthal(int n)
{
	// base case
	if (n == 0)
		return 0;

	// base case
	if (n == 1)
		return 1;

	// recursive step.
	return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

void PmergeMe::FordJohnsonVec()
{
	int group_size = max_size(this->_original_vec.size());
	// std::cout << "group size: " << group_size << std::endl;
	
	// Build phase: create pairs at each recursion level
	for (int i = 1; i <= group_size; i++)
	{
		this->setRercursion(i);
		this->make_pairs_vec();
	}
	this->_main_vec = this->_original_vec;
	// Insert phase: process pend elements from largest to smallest groups
	for (int i = group_size; i >= 1; i--)
	{
		this->setRercursion(i);
		this->make_pend_vec();
		// Skip insertion if no pend elements were created
		if (this->_pend_vec.empty()) continue;
		this->insert_pend_vec();
	}
}

void PmergeMe::sort_pairs_vec(pair_vec *newpair)
{
	const vector& first_vec = (*newpair).first;
	const vector& second_vec = (*newpair).second;
	
	if (!first_vec.empty() && !second_vec.empty())
		if (first_vec.back() > second_vec.back())
			std::swap((*newpair).first, (*newpair).second);
}

void PmergeMe::make_pairs_vec()
{
	vector original = this->_original_vec;
	this->_original_vec.clear();
	int target_size = std::pow(2, this->_recursion);
	if (target_size == 1)
		target_size = 2;
	int half_size = target_size / 2;
	vector::iterator it = original.begin();
	for (; it <= original.end(); it += target_size)
	{
		if (it + half_size >= original.end())
		{
			this->_original_vec.insert(this->_original_vec.end(), it, original.end());
			break;
		}
		else
		{
			// Process a pair of elements from the sequence
			vector first_vec(it, it + half_size);
			vector second_vec;
			if (it + target_size >= original.end())
				second_vec.insert(second_vec.end(), it + half_size, original.end());
			else
				second_vec.insert(second_vec.end(), it + half_size, it + target_size);
			
			// Create pair and sort
			pair_vec newpair = std::make_pair(first_vec, second_vec);
			if (first_vec.size() == second_vec.size())
				sort_pairs_vec(&newpair);
			
			this->_original_vec.insert(this->_original_vec.end(), newpair.first.begin(), newpair.first.end());
			this->_original_vec.insert(this->_original_vec.end(), newpair.second.begin(), newpair.second.end());
			
		}
	}
}

void PmergeMe::make_pend_vec()
{
	int target_size = std::pow(2, this->_recursion);
	int half_size = target_size / 2;
	int quarter = half_size / 2;
	if (quarter == 0)
		quarter = 1;
	
	vector &sequence = this->_main_vec;
	this->_pend_vec.clear();
	
	vector::iterator it = sequence.begin()+half_size;
	while (it + quarter <= sequence.end())
	{
		// Create a vector for the pend elements and add to pend chain
		vector pend_group(it, it + quarter);
		this->_pend_vec.push_back(pend_group);
		it = sequence.erase(it, it + quarter);	// erase returns new valid iterator
	}
	if (quarter == 1 && it < sequence.end()) {
		vector remaining_group(it, sequence.end());
		this->_pend_vec.push_back(remaining_group);
		sequence.erase(it, sequence.end());
	}
}

void PmergeMe::insert_pend_vec(void)
{
	vector &main = this->_main_vec;
	rec_vec &pend = this->_pend_vec;
	int target_size = std::pow(2, this->_recursion);
	int half_size = target_size / 2;
	int quarter = half_size / 2;
	if (quarter == 0)
		quarter = 1;

	int i = 2;
	while (!pend.empty())
	{
		int lower = (i > 2) ? Jacobsthal(i - 1) : 1;
		int upper = Jacobsthal(i);
		for (int j = upper - lower - 1; j >= 0; j--)
		{
			if (j < int(pend.size()) && j >= 0)
			{
				vector &current = pend[j];
				vector::iterator end = main.end();
				if (quarter > 1)
				{
					vector compare;
					for (vector::iterator it = main.begin(); it < main.end(); it += quarter)
						if (it + quarter - 1 < main.end())
							compare.push_back(*(it + quarter - 1));

					vector::iterator compare_pos = upper_bound(compare.begin(), compare.end(), current.back());
					int block_index = compare_pos - compare.begin();
					end = main.begin() + (block_index * quarter);
				}
				else
				{
					end = upper_bound(main.begin(), main.end(), current.back());
				}
				main.insert(end, current.begin(), current.end());
				pend.erase(pend.begin() + j);
			}
		}
		i++;
	}
	pend.clear();
}


void PmergeMe::FordJohnsonDeq()
{
	int group_size = max_size(this->_original_deq.size());
	
	// Build phase: create pairs at each recursion level
	for (int i = 1; i <= group_size; i++)
	{
		this->setRercursion(i);
		this->make_pairs_deq();
	}
	this->_main_deq = this->_original_deq;
	// Insert phase: process pend elements from largest to smallest groups
	for (int i = group_size; i >= 1; i--)
	{
		this->setRercursion(i);
		this->make_pend_deq();
		// Skip insertion if no pend elements were created
		if (this->_pend_deq.empty()) continue;
		this->insert_pend_deq();
	}
}

void PmergeMe::sort_pairs_deq(pair_deq *newpair)
{
	const deque& first_deq = (*newpair).first;
	const deque& second_deq = (*newpair).second;
	
	if (!first_deq.empty() && !second_deq.empty())
		if (first_deq.back() > second_deq.back())
			std::swap((*newpair).first, (*newpair).second);
}

void PmergeMe::make_pairs_deq()
{
	deque original = this->_original_deq;
	this->_original_deq.clear();
	int target_size = std::pow(2, this->_recursion);
	if (target_size == 1)
		target_size = 2;
	int half_size = target_size / 2;
	deque::iterator it = original.begin();
	for (; it <= original.end(); it += target_size)
	{
		if (it + half_size >= original.end())
		{
			this->_original_deq.insert(this->_original_deq.end(), it, original.end());
			break;
		}
		else
		{
			// Process a pair of elements from the sequence
			deque first_deq(it, it + half_size);
			deque second_deq;
			if (it + target_size >= original.end())
				second_deq.insert(second_deq.end(), it + half_size, original.end());
			else
				second_deq.insert(second_deq.end(), it + half_size, it + target_size);
			
			// Create pair and sort
			pair_deq newpair = std::make_pair(first_deq, second_deq);
			if (first_deq.size() == second_deq.size())
				sort_pairs_deq(&newpair);
			
			this->_original_deq.insert(this->_original_deq.end(), newpair.first.begin(), newpair.first.end());
			this->_original_deq.insert(this->_original_deq.end(), newpair.second.begin(), newpair.second.end());
			
		}
	}
}

void PmergeMe::make_pend_deq()
{
	int target_size = std::pow(2, this->_recursion);
	int half_size = target_size / 2;
	int quarter = half_size / 2;
	if (quarter == 0)
		quarter = 1;
	
	deque &sequence = this->_main_deq;
	this->_pend_deq.clear();
	
	deque::iterator it = sequence.begin()+half_size;
	while (it + quarter <= sequence.end())
	{
		// Create a deque for the pend elements and add to pend chain
		deque pend_group(it, it + quarter);
		this->_pend_deq.push_back(pend_group);
		it = sequence.erase(it, it + quarter);	// erase returns new valid iterator
	}
	if (quarter == 1 && it < sequence.end()) {
		deque remaining_group(it, sequence.end());
		this->_pend_deq.push_back(remaining_group);
		sequence.erase(it, sequence.end());
	}
}

void PmergeMe::insert_pend_deq(void)
{
	deque &main = this->_main_deq;
	rec_deq &pend = this->_pend_deq;
	int target_size = std::pow(2, this->_recursion);
	int half_size = target_size / 2;
	int quarter = half_size / 2;
	if (quarter == 0)
		quarter = 1;

	int i = 2;
	while (!pend.empty())
	{
		int lower = (i > 2) ? Jacobsthal(i - 1) : 1;
		int upper = Jacobsthal(i);
		for (int j = upper - lower - 1; j >= 0; j--)
		{
			if (j < int(pend.size()) && j >= 0)
			{
				deque &current = pend[j];
				deque::iterator end = main.end();
				if (quarter > 1)
				{
					deque compare;
					for (deque::iterator it = main.begin(); it < main.end(); it += quarter)
						if (it + quarter - 1 < main.end())
							compare.push_back(*(it + quarter - 1));

					deque::iterator compare_pos = upper_bound(compare.begin(), compare.end(), current.back());
					int block_index = compare_pos - compare.begin();
					end = main.begin() + (block_index * quarter);
				}
				else
				{
					end = upper_bound(main.begin(), main.end(), current.back());
				}
				main.insert(end, current.begin(), current.end());
				pend.erase(pend.begin() + j);
			}
		}
		i++;
	}
	pend.clear();
}

void PmergeMe::print_sequence(const deque& sequence)
{
	deque::const_iterator it = sequence.begin();
	for (; it != sequence.end(); it++)
	{
		if (it < sequence.begin() + 10 || it > sequence.end() - 10)
			std::cout << *it << " ";
		}
	std::cout << std::endl;
}

void PmergeMe::print_sequence(const vector& sequence)
{
	vector::const_iterator it = sequence.begin();
	for (; it != sequence.end(); it++)
	{
		if (it < sequence.begin() + 10 || it > sequence.end() - 10)
			std::cout << *it << " ";
		}
	std::cout << std::endl;
}

std::ostream &operator << (std::ostream &o, std::deque<int> const &a)
{
	std::deque<int>::const_iterator it = a.begin();
	for (; it != a.end(); ++it)
	{
		o << *it << " ";
	}
	return o;
}

std::ostream &operator << (std::ostream &o, std::vector<int> const &a)
{
	std::vector<int>::const_iterator it = a.begin();
	for (; it != a.end(); ++it)
	{
		o << *it << " ";
	}
	return o;
}
