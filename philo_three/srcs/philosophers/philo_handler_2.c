/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:37:16 by louis             #+#    #+#             */
/*   Updated: 2020/09/16 23:40:02 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structures.h"
#include "../../includes/declarations.h"

int		die_message(t_philo *p, PHILO_STATE state)
{
	p->state = state;
	alert(current_time(*p->args), p);
	return (FALSE);
}

void	*philo_alive(void *mem)
{
	t_philo	*p;

	p = (t_philo *)mem;
	while (TRUE)
	{
		if (p->args->n_args > 4 && p->eat_count >= p->args->args[PHILO_MAX_EAT])
		{
			die_message(p, FED);
			exit(EXIT_SUCCESS);
		}
		if (!p->fed && p->state != EATING
			&& p->timeout < current_time(*p->args))
		{
			die_message(p, DIED);
			exit(EXIT_SUCCESS);
		}
		ft_usleep(30);
	}
}

void	start_mid_philo(t_args *args, int even)
{
	int	index;

	index = 0;
	while (index < args->args[N_PHILO])
	{
		if (index % 2 == !even)
		{
			args->philos[index].pid = fork();
			if (args->philos[index].pid == 0)
			{
				pthread_create(&args->philos[index].pthread, NULL,
							   philo_alive, &args->philos[index]);
				pthread_detach(args->philos[index].pthread);
				start_routine(&args->philos[index]);
				ft_usleep(200);
			}
		}
		index++;
	}
}

int		start_philosophers(t_args *args)
{
	start_mid_philo(args, 1);
	ft_usleep(5000);
	start_mid_philo(args, 0);
	return (EXIT_SUCCESS);
}
