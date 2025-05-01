/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:18:57 by izperez           #+#    #+#             */
/*   Updated: 2025/05/01 12:13:23 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
try {
	Bureaucrat b1("John", 1); // Highest possible grade
	Bureaucrat b2("Jane", 100);
	Bureaucrat b3;

	Form form1("Form 1", 50, 100);
	Form form2("Form 2", 10, 20);
	Form form3;

	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;

	b1.signForm(form1);  // OK
	b2.signForm(form2);  // NOK 
} catch (const std::exception& e) {
	std::cout << "Exception: " << e.what() << std::endl;
}

return 0;
}
