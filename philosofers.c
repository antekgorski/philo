/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:33:59 by agorski           #+#    #+#             */
/*   Updated: 2025/01/03 21:33:31 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_end(t_table *table)
{
	pthread_mutex_lock(&table->waiter);
	if (table->end)
	{
		pthread_mutex_unlock(&table->waiter);
		return (true);
	}
	pthread_mutex_unlock(&table->waiter);
	return (false);
}

bool	is_full(t_philo_head *philo)
{
	if (philo->table->number_of_meals != -1)
	{
		if (philo->meals_c == philo->table->number_of_meals)
			return (true);
	}
	return (false);
}

void	*ft_philo(void *arg)
{
	t_philo_head	*philo;

	philo = (t_philo_head *)arg;
	while (!is_end(philo->table) && !is_full(philo))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
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
