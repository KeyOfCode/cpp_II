/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:11:13 by darismen          #+#    #+#             */
/*   Updated: 2025/11/24 19:03:42 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


RPN::RPN() {}

RPN::RPN(const RPN &src) : _stack(src._stack) {}

RPN &RPN::operator=(const RPN &rhs) 
{
	if (this != &rhs)
	{
		this->_stack = rhs._stack;
	}
	return *this;
}

RPN::~RPN() {}

int solve(int a, int b, char opr)
{
	if (opr == '+')
		return a + b;
	else if (opr == '-')
		return a - b;
	else if (opr == '*')
		return a * b;
	else if (opr == '/')
		return a / b;
	else
		throw RPN::InvalidInputException("Invalid operator");
}



void RPN::operations(const std::string &op)
{
	std::string operators = "+-*/";
	int a;
	int b;
	for (int i = 0; i < int(op.size()); i++)
	{
		if (operators.find(op[i]) != std::string::npos)
		{
			// std::cout << "2nd: " << this->_stack.top() << " size: " << this->_stack.size() << std::endl;
			b = this->_stack.top();
			this->_stack.pop();
			// std::cout << "b: " << b << " size: " << this->_stack.size() << std::endl;
			a = this->_stack.top();
			this->_stack.pop();
			// std::cout << "a: " << a << " size: " << this->_stack.size() << std::endl;
			// std::cout << "opr: " << op[i] << std::endl;
			this->_stack.push(solve (a, b, op[i]));
			// std::cout << "end: " << this->_stack.top() << " size: " << this->_stack.size() << std::endl<< std::endl;

		}
		else if (std::isdigit(op[i]))
		{
			this->_stack.push(op[i] - '0');
			// std::cout << "i: " << i << std::endl << " push: " << this->_stack.top() 
					// << " size: " << this->_stack.size() << std::endl<< std::endl;
		}
		else if (op[i] == ' ')
			continue;
		else
			throw InvalidInputException("Error");
	}
	std::cout << "result: " << this->_stack.top() << std::endl << std::endl;
}
