/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:02:26 by izperez           #+#    #+#             */
/*   Updated: 2025/05/01 12:10:03 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : _target("default")
{
	std::cout << "Default constructor called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "\033[32m" << "RobotomyRequestForm Constructor called!" << "\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other), _target(other._target)
{
	std::cout << "Copy constructor called!" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\033[31m" << "RobotomyRequestForm Destructor called!" << "\033[0m" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!isSigned())
		throw std::runtime_error("Form not signed.");
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();

	if (rand() % 2)
		std::cout << _target << " has been robotomized succesfully!" << std::endl;
	
}

