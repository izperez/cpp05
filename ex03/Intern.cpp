/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:53:12 by izperez           #+#    #+#             */
/*   Updated: 2025/04/22 11:25:51 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "\033[32m" << "Intern Constructor called!" << "\033[0m" << std::endl;
}

Intern::~Intern()
{
	std::cout << "\033[31m" << "Intern Destructor called!" << "\033[0m" << std::endl;
}

AForm* Intern::createForm(const std::string &formName, const std::string &target)
{
	if (formName == "shrubbery creation")
		return new ShrubberyCreationForm(target);
	else if (formName == "robotomy request")
		return new RobotomyRequestForm(target);
	else if (formName == "presidential pardon")
		return new PresidentialPardonForm(target);
	else
		return (NULL);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
	AForm* form = createForm(formName, target);

	if (form)
		std::cout << "Intern creates " << formName << std::endl;
	else
		std::cerr << "Intern: Error - Form name " << formName << " doesn't exist" << std::endl;
	return (form);
	
}