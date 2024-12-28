/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:54:40 by agorski           #+#    #+#             */
/*   Updated: 2024/12/28 23:50:16 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_struct(t_table *table, t_philo_head **philo_head)
{
	table->philo_n = 0;
	table->time_to_die = 0;
	table->time_to_eat = 0;
	table->time_to_sleep = 0;
	table->number_of_meals = 0;
	table->start_time = 0;
	table->philo_died = 0;
	table->meal_eaten = 0;
	table->forks = NULL;
	table->philo = NULL;
	*philo_head = NULL;
}

int	ft_meals_eaten(t_table *table, t_philo_head *philo_head)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < table->philo_n)
	{
		if (philo_head[i].meals_c != table->number_of_meals)
			count++;
		i++;
	}
	if (count == table->philo_n)
		return (1);
	return (0);
}

int	ft_philo_died(t_table *table, t_philo_head *philo_head)
{
	int	i;

	i = 0;
	while (i < table->philo_n)
	{
		if (ft_get_time() - philo_head[i].lm_time > table->time_to_die)
		{
			printf("%ld %d died\n", ft_get_time(), i + 1);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_dinner(t_table *table, t_philo_head *philo_head)
{
	while (1)
	{
		if (table->number_of_meals != -1)
		{
			if (ft_meals_eaten(table, philo_head) == 1)
				table->meal_eaten = 1;
		}
		if (ft_philo_died(table, philo_head) == 1)
			table->philo_died = 1;
	}
}

int	main(int argc, char *argv[])
{
	t_table			table;
	t_philo_head	*philo_head;

	ft_init_struct(&table, &philo_head);
	ft_parse_args(argc, argv, &table);
	ft_table_setting(&table);
	ft_dinner(&table, philo_head);
	ft_philo_come(&table, &philo_head);
	ft_philo_out(&table);
	ft_free(&table, philo_head);
	return (0);
}
