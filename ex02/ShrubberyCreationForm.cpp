/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:02:34 by izperez           #+#    #+#             */
/*   Updated: 2025/05/01 12:12:20 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _target("default")
{
	std::cout << "Default constructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "\033[32m" << "ShrubberyCreationForm Constructor called!" << "\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other), _target(other._target)
{
	std::cout << "Copy constructor called!" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\033[31m" << "ShrubberyCreationForm Destructor called!" << "\033[0m" << std::endl;
	
}

void ShrubberyCreationForm::execute(const Bureaucrat & executor) const
{
	if (!isSigned())
		throw std::runtime_error("Form not signed.");
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
		
	std::ofstream file((_target + "_shrubbery").c_str());
	file << "  *\n  ***\n *****\n*******\n  |||";
	file.close();
	
}

