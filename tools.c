/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:15:07 by agorski           #+#    #+#             */
/*   Updated: 2025/01/03 21:44:10 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Print an error message and exit the program
 * @param str the error message
 */
void	e_q(char *str)
{
	printf("%s", str);
	exit(1);
}

/**
 * @brief Check if all the philosophers have eaten the required number of meals
 * @param table the table
 * @param philo_head the philosophers
 * @return int 1 if all the philosophers have eaten the required number of meals,
 * @return 0 otherwise
 */
bool	ft_full(t_philo_head *philo)
{
	if (philo->table->number_of_meals != -1)
	{
		if (philo->meals_c == philo->table->number_of_meals)
			return (true);
	}
	return (false);
}

/**
 * @brief Free the memory allocated for the forks, head, and philosophers
 * @param table the table
 * @param philo_head the philosophers
 */
void	ft_free(t_table *table, t_philo_head *philo_head)
{
	int	i;

	i = 0;
	if (table->philo != NULL)
	{
		while (i < table->philo_n)
		{
			pthread_mutex_destroy(&table->forks[i]);
			i++;
		}
	}
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->waiter);
	if (table->forks != NULL)
		free(table->forks);
	if (table->philo != NULL)
		free(table->philo);
	if (philo_head != NULL)
		free(philo_head);
}
