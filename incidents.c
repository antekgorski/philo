/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incidents.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:30:13 by agorski           #+#    #+#             */
/*   Updated: 2024/12/28 23:47:19 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_come(t_table *table, t_philo_head **philo_head)
{
	int	i;

	ft_philo_head_init(*philo_head, table);
	i = 0;
	while (i < table->philo_n)
	{
		if (pthread_create(&table->philo[i], NULL, ft_philo, philo_head) != 0)
			e_q("Error: pthread_create failed\n");
		i++;
	}
}

void	ft_philo_out(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_n)
	{
		if (pthread_join(table->philo[i], NULL) != 0)
			e_q("Error: pthread_join failed\n");
		i++;
	}
}

void	ft_table_setting(t_table *table)
{
	int	i;

	i = 0;
	table->start_time = ft_get_time();
	table->forks = (t_mutex *)malloc(sizeof(t_mutex) * table->philo_n);
	if (!table->forks)
		e_q("Error: malloc failed\n");
	table->philo = (pthread_t *)malloc(sizeof(pthread_t) * table->philo_n);
	if (!table->philo)
		e_q("Error: malloc failed\n");
	while ((i < table->philo_n))
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			e_q("Error: mutex init failed\n");
		i++;
	}
}
