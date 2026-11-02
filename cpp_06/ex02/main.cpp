/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:05:17 by darismen          #+#    #+#             */
/*   Updated: 2025/10/28 15:14:15 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base* generate(void)
{
	srand(time(0));
	int randomNum = std::rand() % 3;
	std::cout << "Random number is: " << randomNum << std::endl;
	
	if (randomNum == 0)
		return new A;
	else if (randomNum == 1)
		return new B;
	else
		return new C;
}


void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (...) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (...) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (...) {}
}

int main()
{
	Base *base = generate();
	std::cout << "Base *p" << std::endl;
	identify(base);
	std::cout << "Base &p" << std::endl;
	identify(*base);
}

