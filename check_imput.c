/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_imput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:13:33 by agorski           #+#    #+#             */
/*   Updated: 2024/12/29 22:42:34 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i > 10)
		e_q("HEY!\t<<BE||!2BE>>\t...but argv can't BE too long.\n");
	return (i);
}

static int	ft_atoi(char *argv)
{
	long int	result;
	int			i;

	i = 0;
	if (argv[0] == '-')
		e_q("HEY!\t<<BE||!2BE>>\t...but argv can't BE negative.\n");
	ft_strlen(argv);
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			e_q("HEY!\t<<BE||!2BE>>\t...but argv must BE a number.\n");
		i++;
	}
	result = 0;
	while (*argv)
	{
		result = result * 10 + *argv - '0';
		argv++;
	}
	if (result > INT_MAX)
		e_q("HEY!\t<<BE||!2BE>>\t...but argv can't BE too big.\n");
	if (result < 1)
		e_q("HEY!\t<<BE||!2BE>>\t...but argv can't BE less than 1.\n");
	return ((int)result);
}

int	ft_parse_args(int argc, char **argv, t_table *table)
{
	if (argc < 5 || argc > 6)
		e_q("HEY!\t<<BE||!2BE>>\t...but number of arg must BE 4 || 5.\n");
	if (argc == 5)
		table->number_of_meals = -1;
	while (argc > 1)
	{
		if (argc == 2)
			table->philo_n = ft_atoi(argv[argc - 1]);
		if (argc == 3)
			table->time_to_die = ft_atoi(argv[argc - 1]);
		if (argc == 4)
			table->time_to_eat = ft_atoi(argv[argc - 1]);
		if (argc == 5)
			table->time_to_sleep = ft_atoi(argv[argc - 1]);
		if (argc == 6)
			table->number_of_meals = ft_atoi(argv[argc - 1]);
		argc--;
	}
	return (0);
}
