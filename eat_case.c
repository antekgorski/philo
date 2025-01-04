/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:36:54 by agorski           #+#    #+#             */
/*   Updated: 2025/01/04 18:06:01 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo_head *philo)
{
	if (is_end(philo->table))
		return ;
	if (philo->id % 2 == 0)
	{
		if (!eat_even(philo))
			return ;
	}
	else if (!eat_odd(philo))
		return ;
	pthread_mutex_lock(&philo->table->print);
	pthread_mutex_lock(&philo->table->waiter);
	philo->lm_time = ft_get_time();
	if (philo->table->number_of_meals != -1)
		philo->meals_c++;
	pthread_mutex_unlock(&philo->table->waiter);
	printf("%ld\t%d is eating\n", ft_ts(philo->table), philo->id + 1);
	pthread_mutex_unlock(&philo->table->print);
	ft_rsleep(philo->table->time_to_eat);
	if (philo->id % 2 == 0)
		duble_unlock(philo->l_fork, philo->r_fork);
	else
		duble_unlock(philo->r_fork, philo->l_fork);
}

bool	eat_even(t_philo_head *philo)
{
	duble_lock(philo->l_fork, &philo->table->print);
	if (is_end(philo->table))
	{
		duble_unlock(&philo->table->print, philo->l_fork);
		return (false);
	}
	printf("%ld\t%d has taken a fork\n", ft_ts(philo->table), philo->id + 1);
	pthread_mutex_unlock(&philo->table->print);
	if (philo->l_fork == philo->r_fork)
	{
		pthread_mutex_unlock(philo->l_fork);
		ft_rsleep(philo->table->time_to_die + 5);
		return (false);
	}
	duble_lock(philo->r_fork, &philo->table->print);
	if (is_end(philo->table))
	{
		pthread_mutex_unlock(&philo->table->print);
		duble_unlock(philo->r_fork, philo->l_fork);
		return (false);
	}
	printf("%ld\t%d has taken a fork\n", ft_ts(philo->table), philo->id + 1);
	pthread_mutex_unlock(&philo->table->print);
	return (true);
}

bool	eat_odd(t_philo_head *philo)
{
	duble_lock(philo->r_fork, &philo->table->print);
	if (is_end(philo->table))
	{
		duble_unlock(&philo->table->print, philo->r_fork);
		return (false);
	}
	printf("%ld\t%d has taken a fork\n", ft_ts(philo->table), philo->id + 1);
	pthread_mutex_unlock(&philo->table->print);
	duble_lock(philo->l_fork, &philo->table->print);
	if (is_end(philo->table))
	{
		pthread_mutex_unlock(&philo->table->print);
		duble_unlock(philo->l_fork, philo->r_fork);
		return (false);
	}
	printf("%ld\t%d has taken a fork\n", ft_ts(philo->table), philo->id + 1);
	pthread_mutex_unlock(&philo->table->print);
	return (true);
}

// void	ft_eat(t_philo_head *philo)
// {
// 	if (is_end(philo->table))
// 		return ;
// 	if (philo->id % 2 == 0)
// 	{
// 		pthread_mutex_lock(philo->l_fork);
// 		pthread_mutex_lock(&philo->table->print);
// 		if (is_end(philo->table))
// 		{
// 			pthread_mutex_unlock(&philo->table->print);
// 			pthread_mutex_unlock(philo->l_fork);
// 			return ;
// 		}
// 		printf("%ld\t%d has taken a fork\n", ft_ts(philo->table), philo->id
// 			+ 1);
// 		pthread_mutex_unlock(&philo->table->print);
// 		if (philo->l_fork == philo->r_fork)
// 		{
// 			pthread_mutex_unlock(philo->l_fork);
// 			ft_rsleep(philo->table->time_to_die + 5);
// 			return ;
// 		}
// 		pthread_mutex_lock(philo->r_fork);
// 		pthread_mutex_lock(&philo->table->print);
// 		if (is_end(philo->table))
// 		{
// 			pthread_mutex_unlock(&philo->table->print);
// 			pthread_mutex_unlock(philo->r_fork);
// 			pthread_mutex_unlock(philo->l_fork);
// 			return ;
// 		}
// 		printf("%ld\t%d has taken a fork\n", ft_ts(philo->table), philo->id
// 			+ 1);
// 		pthread_mutex_unlock(&philo->table->print);
// 	}
// 	else
// 	{
// 		pthread_mutex_lock(philo->r_fork);
// 		pthread_mutex_lock(&philo->table->print);
// 		if (is_end(philo->table))
// 		{
// 			pthread_mutex_unlock(&philo->table->print);
// 			pthread_mutex_unlock(philo->r_fork);
// 			return ;
// 		}
// 		printf("%ld\t%d has taken a fork\n", ft_ts(philo->table), philo->id
// 			+ 1);
// 		pthread_mutex_unlock(&philo->table->print);
// 		pthread_mutex_lock(philo->l_fork);
// 		pthread_mutex_lock(&philo->table->print);
// 		if (is_end(philo->table))
// 		{
// 			pthread_mutex_unlock(&philo->table->print);
// 			pthread_mutex_unlock(philo->l_fork);
// 			pthread_mutex_unlock(philo->r_fork);
// 			return ;
// 		}
// 		printf("%ld\t%d has taken a fork\n", ft_ts(philo->table), philo->id
// 			+ 1);
// 		pthread_mutex_unlock(&philo->table->print);
// 	}
// 	pthread_mutex_lock(&philo->table->print);
// 	pthread_mutex_lock(&philo->table->waiter);
// 	philo->lm_time = ft_get_time();
// 	if (philo->table->number_of_meals != -1)
// 		philo->meals_c++;
// 	pthread_mutex_unlock(&philo->table->waiter);
// 	printf("%ld\t%d is eating\n", ft_ts(philo->table), philo->id + 1);
// 	pthread_mutex_unlock(&philo->table->print);
// 	ft_rsleep(philo->table->time_to_eat);
// 	if (philo->id % 2 == 0)
// 	{
// 		pthread_mutex_unlock(philo->l_fork);
// 		pthread_mutex_unlock(philo->r_fork);
// 	}
// 	else
// 	{
// 		pthread_mutex_unlock(philo->r_fork);
// 		pthread_mutex_unlock(philo->l_fork);
// 	}
// }