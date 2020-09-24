/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:37:16 by louis             #+#    #+#             */
/*   Updated: 2020/09/24 10:38:51 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structures.h"
#include "../../includes/declarations.h"

void	*philo_alive(void *mem)
{
	t_philo	*p;

	p = (t_philo *)mem;
	while (p->state != DIED)
	{
		usleep(1000);
		if (!p->fed && p->timeout < current_time(*p->args))
		{
			sem_wait(p->eat);
			sem_wait(p->args->messages);
			print_line(current_time(*p->args), p, DIED);
			sem_post(p->args->death);
			exit(0);
		}
	}
	return (NULL);
}

void	start_philos(t_args *args)
{
	t_philo	*p;
	int		index;
	char	*tmp;

	index = 0;
	while (index < args->args[N_PHILO])
	{
		p = &args->philos[index];
		if ((p->pid = fork()) == 0)
		{
			tmp = ft_itoa(p->id);
			p->eat = sem_open(tmp, O_CREAT);
			free(tmp);
			pthread_create(&p->pthread, NULL, philo_alive, (void *)p);
			start_routine(p);
			exit(EXIT_SUCCESS);
		}
		usleep(100);
		index++;
	}
}

void	*death_check(void *mem)
{
	t_args *args;

	args = (t_args*)mem;
	sem_wait(args->death);
	args->state = 1;
	sem_post(args->stop);
	return (NULL);
}

int		ft_wait(t_args *args)
{
	pthread_t	death_thread;
	int			status;
	int			index;

	index = 0;
	pthread_create(&death_thread, NULL, death_check, (void*)args);
	pthread_detach(death_thread);
	sem_wait(args->stop);
	if (args->state == 0)
	{
		while (waitpid(-1, &status, 0) > 0)
			;
		if (WIFEXITED(status))
			if (WEXITSTATUS(status) == FED)
				write(1, "everyone is fed\n", 16);
	}
	else
	{
		while (index < args->args[N_PHILO])
			kill(args->philos[index++].pid, SIGKILL);
	}
	while (waitpid(-1, &status, 0) > 0)
		;
	return (1);
}

int		start_philosophers(t_args *args)
{
	start_philos(args);
	ft_wait(args);
	return (EXIT_SUCCESS);
}
