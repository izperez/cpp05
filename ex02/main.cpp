/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:02:14 by izperez           #+#    #+#             */
/*   Updated: 2025/05/01 11:53:32 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>


int main()
{
	std::srand(time(NULL));
	try {
		Bureaucrat boss("Alice", 1);
		Bureaucrat intern("Bob", 150);
		Bureaucrat mid("Charlie", 50);

		ShrubberyCreationForm shrub("Home");
		RobotomyRequestForm robot("Shcool");
		PresidentialPardonForm pardon("Job");

		std::cout << "\n--- Intento de firma por el Interno (Bob) ---\n";
		intern.signForm(shrub);
		intern.signForm(robot);
		intern.signForm(pardon);

		std::cout << "\n--- Firma correcta por Charlie y Alice ---\n";
		mid.signForm(robot);
		boss.signForm(pardon);
		boss.signForm(shrub);

		std::cout << "\n--- Intento de ejecución por Interno (Bob) ---\n";
		try { shrub.execute(intern); } catch (const std::exception& e) { std::cout << "Error: " << e.what() << std::endl; }

		std::cout << "\n--- Ejecución por Bureaucrat medio (Charlie) ---\n";
		try { robot.execute(mid); } catch (const std::exception& e) { std::cout << "Error: " << e.what() << std::endl; }

		std::cout << "\n--- Ejecución por Jefe (Alice) ---\n";
		try { shrub.execute(boss); } catch (const std::exception& e) { std::cout << "Error: " << e.what() << std::endl; }
		try { robot.execute(boss); } catch (const std::exception& e) { std::cout << "Error: " << e.what() << std::endl; }
		try { pardon.execute(boss); } catch (const std::exception& e) { std::cout << "Error: " << e.what() << std::endl; }

	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}

