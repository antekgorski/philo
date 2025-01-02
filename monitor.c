/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:13:45 by agorski           #+#    #+#             */
/*   Updated: 2025/01/02 10:14:45 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_meals_eaten(t_table *table, t_philo_head **philo_head)
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
		return (1);
	return (0);
}

int	ft_philo_died(t_table *table, t_philo_head **philo_head)
{
	int	i;

	i = 0;
	while (i < table->philo_n)
	{
		if ((ft_get_time() - philo_head[i]->lm_time) > table->time_to_die)
		{
			printf("%ld %d died\n", ft_get_time(), i + 1);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_dinner(t_table *table, t_philo_head **philo_head)
{
	while (1)
	{
		if (table->number_of_meals != -1)
		{
			if (ft_meals_eaten(table, philo_head) == 1)
			{
				table->meal_eaten = 1;
				break ;
			}
		}
		if (ft_philo_died(table, philo_head) == 1)
		{
			table->philo_died = 1;
			break ;
		}
	}
}
