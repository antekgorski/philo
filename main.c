/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:54:40 by agorski           #+#    #+#             */
/*   Updated: 2024/12/28 17:42:44 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_table_init(t_table *table)
{
	int i;
	i = 0;
	table->start_time = ft_get_time();
	table->forks = (t_mutex *)malloc(sizeof(t_mutex) * table->philo_n);
	if (!table->forks)
		e_q("Error: malloc failed\n");
	table->philo = (t_philo *)malloc(sizeof(t_philo) * table->philo_n);
	if (!table->philo)
		e_q("Error: malloc failed\n");
	while (i < table->philo_n)
	{
		table->philo[i].id = i;
		table->philo[i].meals_c = 0;
		table->philo[i].lm_time = table->start_time;
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			e_q("Error: mutex init failed\n");
		i++;
		table->philo[i].l_fork = table->forks[i];
		table->philo[i].r_fork = table->forks[(i + 1) % table->philo_n];
	}
}

int	main(int argc, char *argv[])
{
	t_table	table;

	ft_parse_args(argc, argv, &table);
	ft_table_init(&table);
	return (0);
}
