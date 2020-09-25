/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 11:56:05 by louis             #+#    #+#             */
/*   Updated: 2020/09/25 11:46:08 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structures.h"

int		clear_philo(t_args *args)
{
	int	index;

	index = 0;
	while (index < args->args[N_PHILO])
	{
		pthread_mutex_destroy(&args->forks[index].mutex);
		pthread_mutex_destroy(&args->philos[index].eat);
		index++;
	}
	pthread_mutex_destroy(&args->messages);
	free(args->philos);
	free(args->forks);
	free(args);
	return (EXIT_SUCCESS);
}

void	ft_usleep(long n)
{
	struct timeval	start;
	struct timeval	current;

	gettimeofday(&start, NULL);
	while (1)
	{
		usleep(50);
		gettimeofday(&current, NULL);
		if ((current.tv_sec - start.tv_sec) * 1000000 +
			(current.tv_usec - start.tv_usec) > n)
			break ;
	}
}
