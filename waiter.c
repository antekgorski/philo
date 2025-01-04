/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:13:45 by agorski           #+#    #+#             */
/*   Updated: 2025/01/04 13:25:51 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_meals_eaten(t_table *table, t_philo_head **philo_head)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < table->philo_n)
	{
		if ((*philo_head)[i].meals_c != table->number_of_meals)
			count++;
		i++;
	}
	if (count == 0)
		return (table->end = true);
	return (false);
}

bool	ft_philo_died(t_table *table, t_philo_head **philo_head)
{
	int	i;

	i = 0;
	while (i < table->philo_n)
	{
		if (((ft_get_time() - (*philo_head)[i].lm_time)) > table->time_to_die)
		{
			pthread_mutex_lock(&table->waiter);
			if (table->end)
				return (true);
			printf("%ld\t%d died\n", ft_ts(table), i + 1);
			table->end = true;
			pthread_mutex_unlock(&table->waiter);
			return (true);
		}
		i++;
	}
	return (false);
}

void	ft_waiter(t_table *table, t_philo_head **philo_head)
{
	while (1)
	{
		pthread_mutex_lock(&table->print);
		if (ft_philo_died(table, philo_head))
		{
			pthread_mutex_unlock(&table->print);
			break ;
		}
		pthread_mutex_unlock(&table->print);
		if (table->number_of_meals != -1)
		{
			pthread_mutex_lock(&table->waiter);
			if (ft_meals_eaten(table, philo_head))
			{
				pthread_mutex_unlock(&table->waiter);
				break ;
			}
			pthread_mutex_unlock(&table->waiter);
		}
	}
}
