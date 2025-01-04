/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_needs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:01:13 by agorski           #+#    #+#             */
/*   Updated: 2025/01/04 16:29:56 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_philo_head *philo)
{
	pthread_mutex_lock(&philo->table->print);
	if (is_end(philo->table))
	{
		pthread_mutex_unlock(&philo->table->print);
		return ;
	}
	printf("%ld\t%d is sleeping\n", ft_ts(philo->table), philo->id + 1);
	pthread_mutex_unlock(&philo->table->print);
	ft_rsleep(philo->table->time_to_sleep);
}

void	ft_think(t_philo_head *philo)
{
	pthread_mutex_lock(&philo->table->print);
	if (is_end(philo->table))
	{
		pthread_mutex_unlock(&philo->table->print);
		return ;
	}
	printf("%ld\t%d is thinking\n", ft_ts(philo->table), philo->id + 1);
	pthread_mutex_unlock(&philo->table->print);
}
