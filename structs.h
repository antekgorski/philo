/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 22:44:07 by agorski           #+#    #+#             */
/*   Updated: 2024/12/27 23:19:56 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "philo.h"

// typedefs
typedef pthread_mutex_t	t_mutex;

/**
 * @brief Structure for the forks
 * @param mutex the mutex for the fork
 * @param id the id of the fork
 */
typedef struct s_fork
{
	t_mutex				mutex;
	int					id;
}						t_fork;

/**
 * @brief Structure for the philosophers
 * @param id the id of the philosopher
 * @param meals_count the number of meals the philosopher has eaten
 * @param last_meal_time the time of the last meal
 * @param fork the fork of the philosopher
 */
typedef struct s_philo
{
	int					id;
	int					meals_count;
	int					last_meal_time;
	t_fork				*fork;

}						t_philo;

/**
 * @brief Structure for the table
 * @param number_of_philosophers the number of philosophers
 * @param time_to_die the time to die
 * @param time_to_eat the time to eat
 * @param time_to_sleep the time to sleep
 * @param number_of_meals the number of meals
 */
typedef struct s_table
{
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_meals;

}						t_table;

#endif
