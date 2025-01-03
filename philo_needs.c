/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_needs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:01:13 by agorski           #+#    #+#             */
/*   Updated: 2025/01/03 21:34:49 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo_head *philo)
{
	if (is_end(philo->table))
		return ;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		printf("%ld\t%d has taken a fork\n", ft_ts(philo->table), philo->id
			+ 1);
		if (is_end(philo->table))
		{
			pthread_mutex_unlock(philo->l_fork);
			return ;
		}
		else
		{
			pthread_mutex_lock(philo->r_fork);
			printf("%ld\t%d has taken a fork\n", ft_ts(philo->table), philo->id
				+ 1);
		}
		if (is_end(philo->table))
		{
			pthread_mutex_unlock(philo->l_fork);
			pthread_mutex_unlock(philo->r_fork);
			return ;
		}
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		printf("%ld\t%d has taken a fork\n", ft_ts(philo->table), philo->id
			+ 1);
		if (is_end(philo->table))
		{
			pthread_mutex_unlock(philo->r_fork);
			return ;
		}
		else
		{
			pthread_mutex_lock(philo->l_fork);
			printf("%ld\t%d has taken a fork\n", ft_ts(philo->table), philo->id
				+ 1);
		}
		if (is_end(philo->table))
		{
			pthread_mutex_unlock(philo->r_fork);
			pthread_mutex_unlock(philo->l_fork);
			return ;
		}
	}
	pthread_mutex_lock(&philo->table->waiter);
	philo->lm_time = ft_get_time();
	pthread_mutex_unlock(&philo->table->waiter);
	printf("%ld\t%d is eating\n", ft_ts(philo->table), philo->id + 1);
	ft_rsleep(philo->table->time_to_eat);
	pthread_mutex_lock(&philo->table->waiter);
	if (philo->table->number_of_meals != -1)
		philo->meals_c++;
	pthread_mutex_unlock(&philo->table->waiter);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
}

void	ft_sleep(t_philo_head *philo)
{
	if (is_end(philo->table))
		return ;
	printf("%ld\t%d is sleeping\n", ft_ts(philo->table), philo->id + 1);
	ft_rsleep(philo->table->time_to_sleep);
}

void	ft_think(t_philo_head *philo)
{
	if (is_end(philo->table))
		return ;
	printf("%ld\t%d is thinking\n", ft_ts(philo->table), philo->id + 1);
}
