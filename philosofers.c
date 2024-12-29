/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:33:59 by agorski           #+#    #+#             */
/*   Updated: 2024/12/29 01:21:34 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_head_init(t_philo_head **philo_head, t_table *table)
{
	int	i;

	i = 0;
	*philo_head = (t_philo_head *)malloc(sizeof(t_philo_head) * table->philo_n);
	if (*philo_head == NULL)
		e_q("Error: malloc failed\n");
	while ((i < table->philo_n))
	{
		(*philo_head)[i].id = i;
		(*philo_head)[i].meals_c = 0;
		(*philo_head)[i].lm_time = table->start_time;
		(*philo_head)[i].l_fork = &table->forks[i];
		(*philo_head)[i].r_fork = &table->forks[(i + 1) % table->philo_n];
		(*philo_head)[i].table = table;
		i++;
	}
}

void	*ft_philo(void *arg)
{
	t_philo_head	*philo;

	philo = (t_philo_head *)arg;
	while (philo->table->philo_died != 1 || philo->table->meal_eaten != 1)
	{
		ft_take_forks(philo);
		ft_eat(philo);
		ft_drop_forks(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}
