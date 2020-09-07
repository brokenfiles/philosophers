/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 11:56:05 by louis             #+#    #+#             */
/*   Updated: 2020/09/07 16:46:04 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structures.h"

int	clear_philo(t_args *args)
{
	int	index;

	index = 0;
	while (index < args->args[N_PHILO])
	{
		pthread_mutex_destroy(&args->forks[index]);
		pthread_mutex_destroy(&args->philos[index].eat);
		index++;
	}
	pthread_mutex_destroy(&args->fork_message);
	pthread_mutex_destroy(&args->picking);
	free(args->forks);
	free(args);
	return (EXIT_SUCCESS);
}
