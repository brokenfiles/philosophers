/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alert.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 10:41:18 by louis             #+#    #+#             */
/*   Updated: 2020/09/15 12:39:11 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structures.h"
#include "../../includes/declarations.h"

void	alert(long int t, t_philo *p)
{
	sem_wait(p->args->messages);
	if (p->args->stop)
		return ;
	ft_putnbr((int)t);
	if (p->state != FED)
	{
		ft_putstr(" philo #");
		ft_putnbr(p->id + 1);
	}
	if (p->state == EATING)
		ft_putstr(" is eating\n");
	else if (p->state == SLEEPING)
		ft_putstr(" is sleeping\n");
	else if (p->state == FORKING)
		ft_putstr(" has taken a fork\n");
	else if (p->state == THINKING)
		ft_putstr(" is thinking\n");
	else if (p->state == DIED)
		ft_putstr(" died\n");
	else if (p->state == FED)
		ft_putstr(" everyone is fed\n");
	if (p->state != DIED)
		sem_post(p->args->messages);
}
