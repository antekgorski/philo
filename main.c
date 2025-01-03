/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:54:40 by agorski           #+#    #+#             */
/*   Updated: 2025/01/03 19:16:38 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_table			table;
	t_philo_head	*philo_head;

	ft_init_struct(&table, &philo_head);
	ft_parse_args(argc, argv, &table);
	ft_table_setting(&table);
	ft_philo_head_init(&philo_head, &table);
	ft_philo_come(&table, &philo_head);
	ft_waiter(&table, &philo_head);
	ft_philo_out(&table);
	ft_free(&table, philo_head);
	return (0);
}
