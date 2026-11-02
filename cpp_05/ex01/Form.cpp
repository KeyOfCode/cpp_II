/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:11:34 by darismen          #+#    #+#             */
/*   Updated: 2025/04/09 16:17:34 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): _name("default"), _isSigned(false),
	_grade(150), _exe_grade(150)
{
	std::cout << "Form Default Constructor called for " << this->getName() <<
	" with sign grade of " << this->getSignGrade() <<
	" and execution grade of " << this->getExeGrade() << std::endl;
}

Form::Form(std::string name, int grade, int exe)
	: _name(name), _isSigned(false),
	_grade(grade), _exe_grade(exe)
{
	try
	{
		if (this->_grade < 1 || this->_exe_grade < 1)
		{
			throw (Form::GradeTooHighException());
		}
		else if (this->_grade > 150 || this->_exe_grade > 150)
		{
			throw (Form::GradeTooLowException());
		}
		else	
			std::cout << "Form Constructor called for " << 
				this->getName() << " with grade of " <<
				this->getSignGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Form::Form(const Form &src)
	: _name(src._name), _isSigned(src._isSigned),
	_grade(src._grade), _exe_grade(src._exe_grade)
{
	std::cout << "Form Copy Constructor called " << std::endl;
}

Form& Form::operator = (const Form &rhs)
{
	std::cout << "Form Assignment Operator Overload Called" << std::endl;
	if (this == &rhs)
		return *this;
	this->_isSigned = rhs._isSigned;
	return *this;
}

Form::~Form()
{
	std::cout << "\x1B[0;31mForm " 
		<< this->_name << " Destructor Called\x1B[0;37m" << std::endl;
}

std::string	Form::getName() const
{
	return this->_name;
}

int	Form::getSignGrade() const
{
	return this->_grade;
}

int	Form::getExeGrade() const
{
	return this->_exe_grade;
}

bool	Form::getIsSigned() const
{
	return this->_isSigned;
}

bool Form::beSigned(Bureaucrat &crat) 
{
	try
	{
		if (crat.getGrade() <= this->getSignGrade())
			this->_isSigned = true;
		else
			throw Form::GradeTooLowException();
	}
	catch(const Form::GradeTooLowException& e)
	{
		this->_isSigned = false;
		std::cerr << e.what() << std::endl;
	}
	return (this->_isSigned);
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "\033[0;32mForm Grade too Low!!\033[0m";
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "\033[0;32mForm Grade too High!!\033[0m";
}

std::ostream &operator<<(std::ostream &os, Form const &obj)
{
	os << obj.getName() << ", Form Grade " << obj.getSignGrade();
	return os;
}