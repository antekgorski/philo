/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:43:27 by agorski           #+#    #+#             */
/*   Updated: 2025/01/03 21:39:35 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
 * @brief Sleep for a given time
 * @param time the time to sleep
 * @return long 0
 */
long	ft_rsleep(long time)
{
	long	start;

	start = ft_get_time();
	while (ft_get_time() - start < time)
		usleep(100);
	return (0);
}
