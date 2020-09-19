/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 10:27:59 by louis             #+#    #+#             */
/*   Updated: 2020/09/16 23:36:51 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structures.h"
#include "../../includes/declarations.h"

t_philo		*philo_state(t_philo *p, PHILO_STATE state)
{
	p->state = state;
	return (p);
}

void		take_forks(t_philo *p)
{
	sem_wait(p->args->forks);
	alert(current_time(*p->args), philo_state(p, FORKING));
	sem_wait(p->args->forks);
	alert(current_time(*p->args), philo_state(p, FORKING));
}

void		*start_routine(t_philo *p)
{
	while (1)
	{
		sem_wait(p->args->picking);
		take_forks(p);
		sem_post(p->args->picking);
		p->timeout = p->args->args[T_TO_DIE] + current_time(*(p->args));
		alert(current_time(*p->args), philo_state(p, EATING));
		sem_wait(p->eat);
		ft_usleep(p->args->args[T_TO_EAT] * 1000);
		sem_post(p->eat);
		sem_post(p->args->forks);
		sem_post(p->args->forks);
		alert(current_time(*p->args), philo_state(p, SLEEPING));
		if (p->args->n_args > 4 &&
			++p->eat_count >= p->args->args[PHILO_MAX_EAT])
			break ;
		ft_usleep(p->args->args[T_TO_SLEEP] * 1000);
		alert(current_time(*p->args), philo_state(p, THINKING));
	}
	p->args->args[CURR_PHILO]--;
	p->fed = 1;
	return (NULL);
}
