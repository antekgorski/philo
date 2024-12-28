# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agorski <agorski@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/27 22:51:40 by agorski           #+#    #+#              #
#    Updated: 2024/12/29 00:02:51 by agorski          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS = check_imput.c incidents.c main.c philo_needs.c philosofers.c tools.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
TESTFLAGS = -g #-fsanitize=address

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