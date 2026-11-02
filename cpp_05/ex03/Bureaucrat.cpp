/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:20:05 by darismen          #+#    #+#             */
/*   Updated: 2025/04/09 16:20:10 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("default"), _grade(150)
{
	std::cout << "Bureaucrat Default Constructor called for " << this->getName() <<
	" with grade of " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name), _grade(grade)
{
	try
	{
		if (this->_grade < 1)
		{
			_grade = 1;
			throw (Bureaucrat::GradeTooHighException());
		}
		else if (this->_grade > 150)
		{
			_grade = 150;
			throw (Bureaucrat::GradeTooLowException());
		}
		else	
			std::cout << "Bureaucrat Constructor called for " << this->getName() <<
				" with grade of " << this->getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "Bureaucrat Constructor called for " << this->getName() <<
				" with adjusted grade of " << this->getGrade() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
	: _name(src._name), _grade(src._grade)
{
	std::cout << "Bureaucrat Copy Constructor called " << std::endl;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat &rhs)
{
	std::cout << "Bureaucrat Assignment Operator Overload Called" << std::endl;
	if (this == &rhs)
		return *this;
	this->_name = rhs.getName();
	this->_grade = rhs.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "\x1B[0;31mBureaucrat " 
		<< this->_name << " Destructor Called\x1B[0;37m" << std::endl;
}

std::string	Bureaucrat::getName() const
{
	return this->_name;
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

void	Bureaucrat::gradeUp()
{
	try
	{
		if (this->_grade > 1)
			this->_grade--;
		else
			throw Bureaucrat::GradeTooHighException();
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Bureaucrat::gradeDown()
{
	try
	{
		if (this->_grade < 150)
			_grade++;
		else
			throw Bureaucrat::GradeTooLowException();
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Bureaucrat::signForm(A_Form &form)
{
	try
	{
		if (form.beSigned(*this))
			std::cout << this->_name << " signed " << 
			form.getName() << std::endl;
		else
			throw Bureaucrat::GradeTooLowException();
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << this->_name <<
			" couldn't sign " << form.getName() << 
			" because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(A_Form &form)
{
	try
	{
		if (form.getIsSigned())
		{
			std::cout << this->_name << " executed " << 
			form.getName() << std::endl;
			form.execute(*this);
		}
		else
			throw A_Form::SignedException();
	}
	catch(const A_Form::SignedException& e)
	{
		std::cerr << this->_name <<
			" couldn't execute " << form.getName() << 
			" because " << e.what() << std::endl;
	}
}


/* Exception Constructors
Bureaucrat::GradeTooLowException::GradeTooLowException()
{
	std::cout << "\x1B[0;31mConstructor [Low]\x1B[0;37m" << std::endl;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
	std::cout << "\x1B[0;31mDestructor [Low]\x1B[0;37m" << std::endl;
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
	std::cout << "\x1B[0;31mConstructor [High]\x1B[0;37m" << std::endl;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
	std::cout << "\x1B[0;31mDestructor [High]\x1B[0;37m" << std::endl;
} */

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "\033[0;31mGrade too Low!!\033[0m";
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "\033[0;31mGrade too High!!\033[0m";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &obj)
{
	os << obj.getName() << ", bureaucrat Grade " << obj.getGrade();
	return os;
}

