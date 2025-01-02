/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:15:07 by agorski           #+#    #+#             */
/*   Updated: 2025/01/02 20:28:55 by agorski          ###   ########.fr       */
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
