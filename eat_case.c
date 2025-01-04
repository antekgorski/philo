/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:36:54 by agorski           #+#    #+#             */
/*   Updated: 2025/01/04 16:30:33 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo_head *philo)
{
	if (is_end(philo->table))
		return ;
	if (philo->id % 2 == 0)
		eat_even(philo);
	else
		eat_odd(philo);
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

void	even_unlock(t_philo_head *philo)
{
	pthread_mutex_unlock(&philo->table->print);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	eat_even(t_philo_head *philo)
{
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(&philo->table->print);
	if (is_end(philo->table))
	{
		pthread_mutex_unlock(&philo->table->print);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	printf("%ld\t%d has taken a fork\n", ft_ts(philo->table), philo->id + 1);
	pthread_mutex_unlock(&philo->table->print);
	if (philo->l_fork == philo->r_fork)
	{
		pthread_mutex_unlock(philo->l_fork);
		ft_rsleep(philo->table->time_to_die + 5);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(&philo->table->print);
	if (is_end(philo->table))
	{
		even_unlock(philo);
		return ;
	}
	printf("%ld\t%d has taken a fork\n", ft_ts(philo->table), philo->id + 1);
	pthread_mutex_unlock(&philo->table->print);
}

void	eat_odd(t_philo_head *philo)
{
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(&philo->table->print);
	if (is_end(philo->table))
	{
		pthread_mutex_unlock(&philo->table->print);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	printf("%ld\t%d has taken a fork\n", ft_ts(philo->table), philo->id + 1);
	pthread_mutex_unlock(&philo->table->print);
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(&philo->table->print);
	if (is_end(philo->table))
	{
		pthread_mutex_unlock(&philo->table->print);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	printf("%ld\t%d has taken a fork\n", ft_ts(philo->table), philo->id + 1);
	pthread_mutex_unlock(&philo->table->print);
}

