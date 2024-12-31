# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/27 22:51:40 by agorski           #+#    #+#              #
#    Updated: 2024/12/31 14:56:54 by agorski          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS = check_imput.c main.c philo_needs.c philosofers.c tools.c init.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
TESTFLAGS = -g -pthread #-fsanitize=address -fsanitize=thread

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test:
	$(CC) $(CFLAGS) $(TESTFLAGS) $(SRCS) -o $(NAME)

retest: fclean test

.phony: all clean fclean re test retest
# valgrind --leak-check=full --track-origins=yes ./philo
# valgrind --leak-check=full --show-leak-kinds=all ./philo