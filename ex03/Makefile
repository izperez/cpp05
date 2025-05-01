# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izperez <izperez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 11:02:16 by izperez           #+#    #+#              #
#    Updated: 2025/05/01 11:51:33 by izperez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Intern
CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDE = Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp

.SILENT:
all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I.
		@echo "\033[32mOK Compiled!\033[0m"

$(OBJS): $(SRCS)
		$(CC) $(CFLAGS) -c $(SRCS)
		@echo "\033[32mObjets $@ created!\033[0m"

clean:
		-rm -rf $(OBJS)
		@echo "\033[31mObjets destroyed!\033[0m"

fclean:
		-rm -rf $(NAME)
		@echo "\033[31mExecutable Destroyed!\033[0m"

re: fclean all

.PHONY: all clean fclean re