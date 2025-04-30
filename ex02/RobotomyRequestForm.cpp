/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:02:26 by izperez           #+#    #+#             */
/*   Updated: 2025/04/17 10:39:19 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "\033[32m" << "RobotomyRequestForm Constructor called!" << "\033[0m" << std::endl;
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

