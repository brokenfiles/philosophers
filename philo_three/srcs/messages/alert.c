/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alert.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 10:41:18 by louis             #+#    #+#             */
/*   Updated: 2020/09/23 20:42:59 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structures.h"
#include "../../includes/declarations.h"

void	print_line(long int t, t_philo *p, PHILO_STATE state)
{
	ft_putnbr((int)t);
	if (state != FED)
	{
		ft_putstr(" philo #");
		ft_putnbr(p->id + 1);
	}
	if (state == EATING)
		ft_putstr(" is eating\n");
	else if (state == SLEEPING)
		ft_putstr(" is sleeping\n");
	else if (state == FORKING)
		ft_putstr(" has taken a fork\n");
	else if (state == THINKING)
		ft_putstr(" is thinking\n");
	else if (state == DIED)
		ft_putstr(" died\n");
	else if (state == FED)
		ft_putstr(" everyone is fed\n");
}

void	alert(long int t, t_philo *p)
{
	sem_wait(p->args->messages);
	print_line(t, p, p->state);
	sem_post(p->args->messages);
}
