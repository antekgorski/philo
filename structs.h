/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 22:44:07 by agorski           #+#    #+#             */
/*   Updated: 2025/01/02 18:30:56 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "philo.h"

// typedefs
typedef pthread_mutex_t	t_mutex;
typedef struct s_philo_head	t_philo_head;

/**
 * @brief Structure for the table
 * @param philo_n the number of philosophers
 * @param time_to_die the time to die
 * @param time_to_eat the time to eat
 * @param time_to_sleep the time to sleep
 * @param number_of_meals the number of meals
 * @param start_time the start time
 * @param forks the forks
 * @param philo the philosophers
 */
typedef struct s_table
{
	int					philo_n;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_meals;
	long				start_time;
	int					philo_died;
	int					meal_eaten;
	t_mutex				*forks;
	t_philo_head		*philo_head;
}						t_table;

/**
 * @brief Structure for the philosophers
 * @param id the id of the philosopher
 * @param meals_count the number of meals the philosopher has eaten
 * @param lm_time the time of the last meal
 * @param l_fork the left fork
 * @param r_fork the right fork
 * @param table the table
 */
typedef struct s_philo_head
{
	int					id;
	int					meals_c;
	long				lm_time;
	pthread_t			thread_id;
	t_mutex				*l_fork;
	t_mutex				*r_fork;
	t_table				*table;
}						t_philo_head;

#endif
