/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:13:45 by agorski           #+#    #+#             */
/*   Updated: 2025/01/03 12:20:04 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_died(t_table *table, t_philo_head **philo_head)
{
	int	i;

	i = 0;
	while (i < table->philo_n)
	{
		if (!ft_full(&(*philo_head)[i]))
			return (1);
		else if (ft_is_dead(&(*philo_head)[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_dead(t_philo_head *philo)
{
	if (((ft_get_time() - philo->lm_time)) > philo->table->time_to_die)
	{
		printf("%ld %d died\n", ft_ts(philo->table), philo->id + 1);
		return (1);
	}
	return (0);
}

void	ft_dinner(t_table *table, t_philo_head **philo_head)
{
	while (1)
	{
		pthread_mutex_lock(&table->diner);
		if (ft_philo_died(table, philo_head) == 1)
		{
			table->philo_died = 1;
			break ;
		}
		pthread_mutex_unlock(&table->diner);
		usleep(100);
	}
	pthread_mutex_unlock(&table->diner);
}

// int	ft_meals_eaten(t_table *table, t_philo_head **philo_head)
// {
// 	int	i;
// 	int	count;

// 	count = 0;
// 	i = 0;
// 	while (i < table->philo_n)
// 	{
// 		if ((*philo_head)[i].meals_c != table->number_of_meals)
// 			count++;
// 		i++;
// 	}
// 	if (count == 0)
// 		return (1);
// 	return (0);
// }

// int	ft_philo_died(t_table *table, t_philo_head **philo_head)
// {
// 	int	i;

// 	i = 0;
// 	while (i < table->philo_n)
// 	{
// 		if (((ft_get_time() - (*philo_head)[i].lm_time)) > table->time_to_die)
// 		{
// 			printf("%ld %d died\n", ft_ts(table), i + 1);
// 			return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// void	ft_dinner(t_table *table, t_philo_head **philo_head)
// {
// 	while (1)
// 	{
// 		if (table->number_of_meals != -1)
// 		{
// 			pthread_mutex_lock(&table->diner);
// 			if (ft_meals_eaten(table, philo_head) == 1)
// 			{
// 				table->meal_eaten = 1;
// 				break ;
// 			}
// 			pthread_mutex_unlock(&table->diner);
// 		}
// 		pthread_mutex_lock(&table->diner);
// 		if (ft_philo_died(table, philo_head) == 1)
// 		{
// 			table->philo_died = 1;
// 			break ;
// 		}
// 		pthread_mutex_unlock(&table->diner);
// 	}
// 	pthread_mutex_unlock(&table->diner);
// }