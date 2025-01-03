/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/01/03 21:41:11 by agorski           #+#    #+#             */
/*   Updated: 2025/01/03 21:41:11 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_struct(t_table *table, t_philo_head **philo_head)
{
	table->philo_n = 0;
	table->time_to_die = 0;
	table->time_to_eat = 0;
	table->time_to_sleep = 0;
	table->number_of_meals = 0;
	table->start_time = 0;
	table->end = false;
	table->forks = NULL;
	table->philo = NULL;
	*philo_head = NULL;
}

void	ft_philo_head_init(t_philo_head **philo_head, t_table *table)
{
	int	i;

	i = 0;
	*philo_head = (t_philo_head *)malloc(sizeof(t_philo_head)
			* table->philo_n);
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

void	ft_philo_come(t_table *table, t_philo_head **philo_head)
{
	int	i;

	i = 0;
	table->start_time = ft_get_time();
	while (i < table->philo_n)
	{
		if (pthread_create(&table->philo[i], NULL, &ft_philo,
				(void *)&(*philo_head)[i]) != 0)
			e_q("Error: pthread_create failed\n");
		i++;
	}
}

void	ft_table_setting(t_table *table)
{
	int	i;

	i = 0;
	table->start_time = ft_get_time();
	table->forks = (t_mutex *)malloc(sizeof(t_mutex) * table->philo_n);
	if (!table->forks)
		e_q("Error: malloc failed\n");
	table->philo = (pthread_t *)malloc(sizeof(pthread_t) * table->philo_n);
	if (!table->philo)
		e_q("Error: malloc failed\n");
	while ((i < table->philo_n))
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			e_q("Error: fork mutex init failed\n");
		i++;
	}
	if (pthread_mutex_init(&table->waiter, NULL) != 0)
		e_q("Error: diner mutex init failed\n");
	if (pthread_mutex_init(&table->print, NULL) != 0)
		e_q("Error: print mutex init failed\n");
}
