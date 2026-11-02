/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:21:53 by darismen          #+#    #+#             */
/*   Updated: 2025/11/28 14:45:29 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"



int main (int argc, char**argv)
{
	try 
	{
		if (argc < 2)
			throw PmergeMe::BadArgException("Incorrect number of inputs");
			
		PmergeMe vec_sorter;
		PmergeMe deq_sorter;

		vec_sorter.load_vector(argv, argc);
		deq_sorter.load_deque(argv, argc);
		
		std::cout << std::endl;
		std::cout << "Before vec:	";
		vec_sorter.print_sequence(vec_sorter.getOriginalVec()); 
		std::cout << "Before deq:	";
		deq_sorter.print_sequence(deq_sorter.getOriginalDeq()); 
		std::cout << "=======================================================" << std::endl;
		
		clock_t vec_start = clock();
		vec_sorter.FordJohnsonVec();
		clock_t vec_time = clock() - vec_start;

		
		clock_t deq_start = clock();
		deq_sorter.FordJohnsonDeq();
		clock_t deq_time = clock() - deq_start;

		std::cout << "After vec:	";
		vec_sorter.print_sequence(vec_sorter.getMainVec());
		std::cout << "After deq:	";
		deq_sorter.print_sequence(deq_sorter.getMainDeq());
		std::cout << std::endl;
		
		std::cout << "Time to process a range of " << vec_sorter.getOriginalVec().size()
				<< " elements with std::vector: " << vec_time << " us" << std::endl;
		std::cout << "Time to process a range of " << deq_sorter.getOriginalDeq().size()
				<< " elements with std::deque: " << deq_time << " us" << std::endl;
		
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}

}

// const PmergeMe::vector& main_vec = vec_sorter.getMainVec();
// if (std::adjacent_find(main_vec.begin(), main_vec.end(), std::greater<int>()) == main_vec.end()) {
// 	// Sequence is sorted (no adjacent pair where first > second)
// 	// ... your code
//     std::cout << "Sorted";
// }
// else
//     {std::cout << "Not Sorted";}