/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:33:59 by agorski           #+#    #+#             */
/*   Updated: 2025/01/03 11:24:34 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo(void *arg)
{
	t_philo_head	*philo;

	philo = (t_philo_head *)arg;
	while (philo->table->philo_died != 1 && !ft_full(philo))
	{
		if (philo->table->philo_died == 1 || ft_full(philo))
			break ;
		ft_take_forks(philo);
		ft_eat(philo);
		ft_drop_forks(philo);
		if (philo->table->philo_died == 1 || ft_full(philo))
			break ;
		ft_sleep(philo);
		if (philo->table->philo_died == 1 || ft_full(philo))
			break ;
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
