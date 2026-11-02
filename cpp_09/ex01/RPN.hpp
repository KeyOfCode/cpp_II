/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:32:08 by darismen          #+#    #+#             */
/*   Updated: 2025/11/10 16:25:32 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstdlib>
# include <string>
# include <sstream>

class RPN
{
typedef std::stack<int> stack;
private:
	stack _stack;
public:
	RPN();
	RPN(const RPN &src);
	RPN &operator = (const RPN &rhs);
	~RPN();
	
	void operations(const std::string &op);
	class	InvalidInputException:	public std::exception
	{
		private:
			std::string			_error;
		public:
			InvalidInputException(const std::string &msg): _error(msg)
				{_error = "\033[0;31m" + msg + "\033[0m";}
			virtual	~InvalidInputException() throw() {}
			virtual const char	*what(void)	const throw() {return (this->_error.c_str());}
	};
};

#endif