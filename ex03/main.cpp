/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:02:14 by izperez           #+#    #+#             */
/*   Updated: 2025/04/22 11:23:50 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"


int main()
{
	Intern Carlos;
	
	AForm* form1 = Carlos.makeForm("robotomy request", "School");
	AForm* form2 = Carlos.makeForm("shrubbery creation", "Job");
	AForm* form3 = Carlos.makeForm("presidential pardon", "Personal");
	
	AForm* invalidForm = Carlos.makeForm("invalid form", "Random");

	delete form1;
	delete form2;
	delete form3;
	delete invalidForm;
	return (0);
}

