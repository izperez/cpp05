/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:18:57 by izperez           #+#    #+#             */
/*   Updated: 2025/05/01 12:13:31 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat Pepita("Pepita", 1);
		Bureaucrat juanita;
		juanita = Pepita;
		std::cout << "name " << juanita << std::endl;
		std::cout << Pepita << std::endl;
		Pepita.incrementGrade(); //TooHighException
	} catch (std::exception& e) {
		std::cerr << "Error Pepita: " << e.what() << std::endl;
	}
	try {
		Bureaucrat Juanita ("Juanita", 150);
		std::cout << Juanita << std::endl;
		Juanita.decrementGrade(); //TooLowException
	} catch (std::exception& e) {
		std::cerr << "Error Juanita: " << e.what() << std::endl;
	}
	return 0;
}
