/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:37:16 by louis             #+#    #+#             */
/*   Updated: 2020/09/04 13:47:53 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <structures.h>
#include <stdlib.h>
#include <pthread.h>
#include <declarations.h>

int		die_message(t_philo *p, PHILO_STATE state)
{
	p->state = state;
	alert(current_time(*p->args), p);
	return (FALSE);
}

int		philo_alive(t_args *args)
{
	int		index;
	t_philo	philo;

	index = 0;
	while (index < args->args[N_PHILO])
	{
		philo = args->philos[index];
		if (args->n_args > 4 && args->total_philo_meal >= args->args[MAX_EAT_TOTAL])
			return (die_message(&philo, FED));
		if (philo.timeout < current_time(*args) && philo.state != EATING)
		{
			die_message(&philo, DIED);
			args->philo_dead = TRUE;
			return (FALSE);
		}
		index++;
	}
	return (TRUE);
}

void	start_mid_philo(t_args *args, int even)
{
	int index;

	index = 0;
	while (index < args->args[N_PHILO])
	{
		if (index % 2 == !even)
		{
			pthread_create(&args->philos[index].pthread, NULL,
					start_routine, (void *) &(args->philos[index]));
			pthread_detach(args->philos[index].pthread);
		}
		index++;
	}
}

int		start_philosophers(t_args *args)
{
	start_mid_philo(args, 1);
	usleep(500);
	start_mid_philo(args, 0);
	while (philo_alive(args));
	return (EXIT_SUCCESS);
}