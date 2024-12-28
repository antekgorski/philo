/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:36:56 by agorski           #+#    #+#             */
/*   Updated: 2024/12/28 17:12:41 by agorski          ###   ########.fr       */
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

// philosofer main functions

int	ft_parse_args(int argc, char **argv, t_table *table);

// tools

long	ft_get_time(void);
void	e_q(char *str);

#endif
