/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 22:44:07 by agorski           #+#    #+#             */
/*   Updated: 2024/12/28 17:39:32 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "philo.h"

// typedefs
typedef pthread_mutex_t	t_mutex;

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
	int					meals_c;
	long				lm_time;
	t_mutex				l_fork;
	t_mutex				r_fork;
}						t_philo;

/**
 * @brief Structure for the table
 * @param philo_n the number of philosophers
 * @param time_to_die the time to die
 * @param time_to_eat the time to eat
 * @param time_to_sleep the time to sleep
 * @param number_of_meals the number of meals
 */
typedef struct s_table
{
	int					philo_n;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_meals;
	long				start_time;
	t_mutex				*forks;
	t_philo				*philo;

}						t_table;

#endif
