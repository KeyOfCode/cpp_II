/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:00:51 by darismen          #+#    #+#             */
/*   Updated: 2025/01/20 14:45:23 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_grade;
	const int			_exe_grade;
public:
	Form();
	Form(const Form &);
	Form(std::string , const int , const int);
	Form &operator = (const Form &);
	~Form();

	std::string	getName() const;
	int			getSignGrade() const;
	int			getExeGrade() const;
	bool		getIsSigned() const;
	
	bool		beSigned(Bureaucrat &);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator << (std::ostream &o, Form const &a);

#endif