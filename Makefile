# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agorski <agorski@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/27 22:51:40 by agorski           #+#    #+#              #
#    Updated: 2025/01/03 20:23:07 by agorski          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS = check_imput.c main.c init.c philo_needs.c philosofers.c time_tools.c tools.c waiter.c
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
# valgrind --tool=memcheck --leak-check=full --track-origins=yes ./philo