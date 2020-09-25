/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 10:27:59 by louis             #+#    #+#             */
/*   Updated: 2020/09/25 12:37:22 by louis            ###   ########.fr       */
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
	sem_wait(p->args->picking);
	sem_wait(p->args->forks);
	alert(current_time(*p->args), philo_state(p, FORKING));
	sem_wait(p->args->forks);
	alert(current_time(*p->args), philo_state(p, FORKING));
	sem_post(p->args->picking);
}

int			eat(t_philo *p)
{
	sem_wait(p->eat);
	ft_usleep(p->args->args[T_TO_EAT] * 1000);
	sem_post(p->args->forks);
	sem_post(p->args->forks);
	if (p->args->stop)
		return (1);
	sem_post(p->eat);
	return (0);
}

void		*start_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (1)
	{
		take_forks(p);
		p->timeout = p->args->args[T_TO_DIE] + current_time(*(p->args));
		if (p->args->stop)
			break ;
		alert(current_time(*p->args), philo_state(p, EATING));
		if (eat(p))
			break ;
		alert(current_time(*p->args), philo_state(p, SLEEPING));
		if (p->args->n_args > 4 &&
			++p->eat_count >= p->args->args[PHILO_MAX_EAT] && (p->fed = 1))
			break ;
		ft_usleep(p->args->args[T_TO_SLEEP] * 1000);
		if (p->args->stop)
			break ;
		alert(current_time(*p->args), philo_state(p, THINKING));
	}
	p->args->args[CURR_PHILO]--;
	return (NULL);
}
