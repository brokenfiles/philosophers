/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alert.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 10:41:18 by louis             #+#    #+#             */
/*   Updated: 2020/09/09 15:33:31 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structures.h"
#include "../../includes/declarations.h"

void	alert(long int t, t_philo *p)
{
	sem_wait(p->args->fork_message);
	ft_putnbr((int)t);
	if (p->state != FED)
	{
		ft_putstr(" philo #");
		ft_putnbr(p->id);
	}
	if (p->state == EATING)
		ft_putstr(" is eating");
	else if (p->state == SLEEPING)
		ft_putstr(" is sleeping");
	else if (p->state == FORKING)
		ft_putstr(" has taken a fork");
	else if (p->state == THINKING)
		ft_putstr(" is thinking");
	else if (p->state == DIED)
		ft_putstr(" died");
	else if (p->state == FED)
		ft_putstr(" everyone is fed");
	ft_putstr("\n");
	sem_post(p->args->fork_message);
}
