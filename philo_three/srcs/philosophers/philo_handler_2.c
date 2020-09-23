/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:37:16 by louis             #+#    #+#             */
/*   Updated: 2020/09/23 15:25:09 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structures.h"
#include "../../includes/declarations.h"

int		die_message(t_philo *p, PHILO_STATE state)
{
	p->state = state;
	alert(current_time(*p->args), p);
	return (state == DIED ? EXIT_FAILURE : EXIT_SUCCESS);
}

void	*philo_alive(void *mem)
{
	t_philo	*p;

	p = (t_philo *)mem;
	while (p->state != DIED)
	{
		usleep(1000);
		if (p->args->n_args > 4 && p->eat_count >= p->args->args[PHILO_MAX_EAT])
		{
			die_message(p, FED);
			while (1)
				;
		}
		if (!p->fed && p->state != EATING
			&& p->timeout < current_time(*p->args))
		{
			sem_wait(p->args->messages);
			p->state = DIED;
			print_line(current_time(*p->args), p);
		}
	}
	exit(0);
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
				exit(EXIT_SUCCESS);
			}
		}
		index++;
	}
}

void	start_philos(t_args *args)
{
	t_philo	*p;
	int		index;

	index = 0;
	while (index < args->args[N_PHILO])
	{
		p = &args->philos[index];
		if ((p->pid = fork()) == 0)
		{
//			args->forks = sem_open("/forks", O_RDWR);
//			args->messages = sem_open("/messages", O_RDWR);
//			args->picking = sem_open("/picking", O_RDWR);
			pthread_create(&p->pthread, NULL, philo_alive, (void *) p);
//			pthread_detach(p->pthread);
			start_routine(p);
			exit(EXIT_SUCCESS);
		}
		usleep(10);
		index++;
	}
}

int		ft_wait(t_args *args)
{
	int status;
	int i;

	while (1)
		if (waitpid(-1, &status, 0) < 0 || WIFEXITED(status))
		{
			i = -1;
			while (++i < args->args[N_PHILO])
				kill(args->philos[i].pid, SIGINT);
			return (0);
		}
	return (0);
}

int		start_philosophers(t_args *args)
{
	// LAST VERSION : BEFORE REMAKE
//	start_mid_philo(args, 1);
//	ft_usleep(5000);
//	start_mid_philo(args, 0);
	start_philos(args);
	ft_wait(args);
	return (EXIT_SUCCESS);
}
