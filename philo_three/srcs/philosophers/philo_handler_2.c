/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:37:16 by louis             #+#    #+#             */
/*   Updated: 2020/09/19 19:18:42 by llaurent         ###   ########.fr       */
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
			exit(die_message(p, FED));
		if (!p->fed && p->state != EATING
			&& p->timeout < current_time(*p->args))
			exit(die_message(p, DIED));
		ft_usleep(30);
	}
}

void	start_mid_philo(t_args *args, int even)
{
	t_philo	*p;
	int		index;

	index = 0;
	while (index < args->args[N_PHILO])
	{
		if (index % 2 == !even)
		{
			p = &args->philos[index];
			p->pid = fork();
			if (p->pid == 0)
			{
				args->forks = sem_open("/forks", O_RDWR);
				args->messages = sem_open("/messages", O_RDWR);
				args->picking = sem_open("/picking", O_RDWR);
				pthread_create(&p->pthread, NULL, philo_alive, (void *)p);
				pthread_detach(p->pthread);
				start_routine(p);
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
