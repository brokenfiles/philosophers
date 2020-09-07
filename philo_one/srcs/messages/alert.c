/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alert.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 10:41:18 by louis             #+#    #+#             */
/*   Updated: 2020/09/07 16:35:11 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "declarations.h"
#include <pthread.h>

void	alert(long int t, t_philo *p)
{
	pthread_mutex_lock(&p->args->fork_message);
	ft_putnbr((int)t);
	if (p->state != FED)
	{
		ft_putstr(" philo #");
		ft_putnbr(p->id);
	}
	ft_putstr(" ");
	if (p->state == EATING)
		ft_putstr("is eating");
	else if (p->state == SLEEPING)
		ft_putstr("is sleeping");
	else if (p->state == FORKING)
		ft_putstr("has taken a fork");
	else if (p->state == THINKING)
		ft_putstr("is thinking");
	else if (p->state == DIED)
		ft_putstr("died");
	else if (p->state == FED)
		ft_putstr("everyone is fed");
	ft_putstr("\n");
	pthread_mutex_unlock(&p->args->fork_message);
}
