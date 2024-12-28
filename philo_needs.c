/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_needs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:01:13 by agorski           #+#    #+#             */
/*   Updated: 2024/12/28 23:58:58 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_forks(t_philo_head *philo)

{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		printf("%ld %d has taken a fork\n", ft_get_time(), philo->id + 1);
		pthread_mutex_lock(philo->r_fork);
		printf("%ld %d has taken a fork\n", ft_get_time(), philo->id + 1);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		printf("%ld %d has taken a fork\n", ft_get_time(), philo->id + 1);
		pthread_mutex_lock(philo->l_fork);
		printf("%ld %d has taken a fork\n", ft_get_time(), philo->id + 1);
	}
}

void	ft_drop_forks(t_philo_head *philo)
{
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

void	ft_eat(t_philo_head *philo)
{
	printf("%ld %d is eating\n", ft_get_time(), philo->id + 1);
	usleep(philo->table->time_to_eat * 1000);
	if (philo->table->number_of_meals != -1)
		philo->meals_c++;
	philo->lm_time = ft_get_time();
}

void	ft_sleep(t_philo_head *philo)
{
	printf("%ld %d is sleeping\n", ft_get_time(), philo->id + 1);
	usleep(philo->table->time_to_sleep * 1000);
}

void	ft_think(t_philo_head *philo)
{
	printf("%ld %d is thinking\n", ft_get_time(), philo->id + 1);
}
