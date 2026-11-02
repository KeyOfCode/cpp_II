/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:18:12 by darismen          #+#    #+#             */
/*   Updated: 2025/04/09 16:19:55 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
	A_Form::A_Form("ShrubberyCreation", 72, 45), _target("defaultPardon")
{
	std::cout << "\032[0;33m\tShrubberyCreationForm Default Constructor\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): 
	A_Form::A_Form("ShrubberyCreationForm", 72, 45), _target(target)
{
	std::cout << "\033[0;33mShrubberyCreationForm Constructor for target " << this->getTarget() << "\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src):
	A_Form::A_Form(src), _target(src.getTarget())
{
	std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm &rhs)
{
	std::cout << "ShrubberyCreationForm Assignment Operator Overload Called" << std::endl;
	if (this == &rhs)
		return *this;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\x1B[0;31mShrubberyCreationForm" 
		<< " Destructor Called\x1B[0;37m" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void	ShrubberyCreationForm::startExe(Bureaucrat const & executor) const
{
	(void)executor;
	//crear un objeto de archivo de salida con el nombre del archivo basado en el target del formulario
	std::ofstream archivo((this->getTarget().append("_shubbery")).c_str());
	if (!archivo)
	{
		std::cerr << "No se pudo abrir el archivo" << std::endl;
		return ;
	}
	
	//escribir en el archivo
	archivo << "    ^    " << std::endl;
	archivo << "   ^^^   " << std::endl;
	archivo << "  ^^^^^  " << std::endl;
	archivo << " ^^^^^^^ " << std::endl;
	archivo << "^^^^^^^^^" << std::endl;
	archivo << "    |    " << std::endl;
	
	//cerrar el archivo
	archivo.close();
}

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm const &obj)
{
	os << "\033[0;34mForm " << obj.getName() << 
	":\n\t Sign Grade: " << obj.getSignGrade() <<
	"\n\t Execution Grade: " << obj.getSignGrade() <<
	"\n\t is signed: " << obj.getIsSigned() <<
	"\033[0m" << std::endl;
	return os;
}