/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:11:34 by darismen          #+#    #+#             */
/*   Updated: 2025/01/22 13:14:49 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

A_Form::A_Form(void): _name("default"), _isSigned(false),
	_grade(150), _exe_grade(150)
{
	std::cout << "\033[0;31mA_Form Default Constructor called for " << this->getName() <<
	" with sign grade of " << this->getSignGrade() <<
	" and execution grade of " << this->getExeGrade() << "\033[0m" << std::endl;
}

A_Form::A_Form(std::string name, int grade, int exe)
	: _name(name), _isSigned(false),
	_grade(grade), _exe_grade(exe)
{
	try
	{
		if (this->_grade < 1 || this->_exe_grade < 1)
		{
			throw (A_Form::GradeTooHighException());
		}
		else if (this->_grade > 150 || this->_exe_grade > 150)
		{
			throw (A_Form::GradeTooLowException());
		}
		else	
			std::cout << "A_Form Constructor called for " << 
				this->getName() << " with grade of " <<
				this->getSignGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

A_Form::A_Form(const A_Form &src)
	: _name(src._name), _isSigned(src._isSigned),
	_grade(src._grade), _exe_grade(src._exe_grade)
{
	std::cout << "A_Form Copy Constructor called " << std::endl;
}

A_Form& A_Form::operator = (const A_Form &rhs)
{
	std::cout << "A_Form Assignment Operator Overload Called" << std::endl;
	if (this == &rhs)
		return *this;
	this->_isSigned = rhs._isSigned;
	return *this;
}

A_Form::~A_Form()
{
	std::cout << "\x1B[0;31mA_Form " 
		<< this->_name << " Destructor Called\x1B[0;37m" << std::endl;
}

std::string	A_Form::getName() const
{
	return this->_name;
}

int	A_Form::getSignGrade() const
{
	return this->_grade;
}

int	A_Form::getExeGrade() const
{
	return this->_exe_grade;
}

bool	A_Form::getIsSigned() const
{
	return this->_isSigned;
}

bool A_Form::beSigned(Bureaucrat &crat) 
{
	try
	{
		if (crat.getGrade() <= this->getSignGrade())
			this->_isSigned = true;
		else
			throw A_Form::GradeTooLowException();
	}
	catch(const A_Form::GradeTooLowException& e)
	{
		this->_isSigned = false;
		std::cerr << e.what() << std::endl;
	}
	return (this->_isSigned);
}

void	A_Form::execute(Bureaucrat const & executor) const
{
	// this->startExe(executor);
	try
	{
		if (this->getIsSigned() == false)
			throw A_Form::SignedException();
		else if (executor.getGrade() > this->getExeGrade())
			throw A_Form::GradeTooLowException();
		else 
		{
			// std::cout << executor.getName() << " executes form: " << this->_name << std::endl;
			this->startExe(executor);
		}
	}
	catch(const A_Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const A_Form::SignedException& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

// void	A_Form::execute(Bureaucrat const & executor) const
// {
// 	(void)executor;
// }

const char* A_Form::GradeTooLowException::what() const throw()
{
	return "\033[0;31mA_Form Grade too Low!!\033[0m";
}

const char* A_Form::GradeTooHighException::what() const throw()
{
	return "\033[0;31mA_Form Grade too High!!\033[0m";
}

const char* A_Form::SignedException::what() const throw()
{
	return "\033[0;31mForm Grade Not Signed!!\033[0m";
}

std::ostream &operator<<(std::ostream &os, A_Form const &obj)
{
	os << "\033[0;34mForm " << obj.getName() << 
	":\n\t Sign Grade: " << obj.getSignGrade() <<
	"\n\t  Execution Grade: " << obj.getSignGrade() <<
	"\n\t  is signed: " << obj.getIsSigned() <<
	"\033[0m" << std::endl;
	return os;
}