/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:15:07 by agorski           #+#    #+#             */
/*   Updated: 2024/12/28 17:14:20 by agorski          ###   ########.fr       */
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
	return ((long long)time.tv_sec * 1000 + (long long)time.tv_usec / 1000);
}
