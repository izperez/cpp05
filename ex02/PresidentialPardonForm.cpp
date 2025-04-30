/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:02:19 by izperez           #+#    #+#             */
/*   Updated: 2025/04/25 11:18:50 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "\033[32m" << "Presidential Constructor called!" << "\033[0m" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\033[31m" << "Presidential Destructor called!" << "\033[0m" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned())
		throw std::runtime_error("Form not signed.");
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

