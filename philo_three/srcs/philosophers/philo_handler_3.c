/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 11:56:05 by louis             #+#    #+#             */
/*   Updated: 2020/09/19 18:19:22 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structures.h"
#include "../../includes/declarations.h"

int		clear_philo(t_args *args)
{
	int	index;
	int	status;

	index = 0;
	waitpid(-1, &status, 0);
	while (index < args->args[N_PHILO])
	{
		free(args->philos[index].eat);
		kill(args->philos[index++].pid, SIGQUIT);
	}
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
