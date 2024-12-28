/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:36:56 by agorski           #+#    #+#             */
/*   Updated: 2024/12/28 23:48:36 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// includes
# include <limits.h>   //INT_MAX
# include <pthread.h>  //pthread_create
# include <stdio.h>    //printf
# include <stdlib.h>   //malloc, free, write ect...
# include <string.h>   //memset
# include <sys/time.h> //gettimeofday
# include <unistd.h>   //usleep

// my includes
# include "structs.h"

// main functions

int		ft_parse_args(int argc, char **argv, t_table *table);
void	ft_table_setting(t_table *table);
void	ft_philo_come(t_table *table, t_philo_head **philo_head);
void	ft_philo_out(t_table *table);
void	ft_dinner(t_table *table, t_philo_head *philo_head);
void	ft_philo_head_init(t_philo_head *philo_head, t_table *table);
void	*ft_philo(void *arg);

// philo_needs

void	ft_take_forks(t_philo_head *philo);
void	ft_drop_forks(t_philo_head *philo);
void	ft_eat(t_philo_head *philo);
void	ft_sleep(t_philo_head *philo);
void	ft_think(t_philo_head *philo);

// tools

long	ft_get_time(void);
void	e_q(char *str);
void	ft_free(t_table *table, t_philo_head *philo_head);

#endif
