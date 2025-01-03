/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:15:07 by agorski           #+#    #+#             */
/*   Updated: 2025/01/03 11:08:27 by agorski          ###   ########.fr       */
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
 * @brief Get the time in milliseconds
 *1 second = 1000 milliseconds
 *1 millisecond = 1000 microseconds
 *microsecond = 1000 nanoseconds
 *@return long the time in milliseconds
 */
long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((long)time.tv_sec * 1000 + (long)time.tv_usec / 1000);
}

/**
 * @brief Get the time since the start of the program
 * @param table the table
 * @return long the time since the start of the program
 */
long	ft_ts(t_table *table)
{
	return (ft_get_time() - table->start_time);
}

/**
 * @brief Check if all the philosophers have eaten the required number of meals
 * @param table the table
 * @param philo_head the philosophers
 * @return int 1 if all the philosophers have eaten the required number of meals, 0 otherwise
 */
int	ft_full(t_philo_head *philo)
{
	if (philo->table->number_of_meals != -1)
	{
		if (philo->meals_c == philo->table->number_of_meals)
			return (1);
	}
	return (0);
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
	pthread_mutex_destroy(&table->diner);
	if (table->forks != NULL)
		free(table->forks);
	if (table->philo != NULL)
		free(table->philo);
	if (philo_head != NULL)
		free(philo_head);
}
