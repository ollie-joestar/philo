/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:54:04 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/23 19:09:02 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*first_philo(t_philo *philo)
{
	int	min;

	if (!philo)
		return (NULL);
	min = 201;
	while (philo->index < min)
	{
		min = philo->index;
		if (!philo->prev)
			return (philo);
		if (philo->prev->index > philo->index)
			break ;
		philo = philo->prev;
	}
	return (philo);
}

t_philo	*last_philo(t_philo *philo)
{
	int	max;

	if (!philo)
		return (NULL);
	max = -1;
	while (philo->index > max)
	{
		max = philo->index;
		if (!philo->next)
			return (philo);
		if (philo->next->index < philo->index)
			break ;
		philo = philo->next;
	}
	return (philo);
}

void	link_to_data(t_data *data, t_philo *philo)
{
	t_philo	*frst;
	t_philo	*last;

	philo->print_lock = &data->print_lock;
	philo->start_lock = &data->start_lock;
	philo->meals_lock = &data->meals_lock;
	philo->clock_lock = &data->clock_lock;
	philo->dead = &data->dead;
	philo->full = &data->full;
	philo->start = &data->start;
	philo->start_time = &data->start_time;
	if (!data->philos)
	{
		philo->next = philo;
		philo->prev = philo;
		data->philos = philo;
		return ;
	}
	frst = first_philo(data->philos);
	last = last_philo(data->philos);
	frst->prev = philo;
	last->next = philo;
	philo->next = frst;
	philo->prev = last;
}

void	update_meals(t_philo *philo)
{
	lock(philo->meals_lock);
	philo->meals_eaten++;
	if (philo->meals_to_eat != 0 && philo->meals_eaten >= philo->meals_to_eat)
		*philo->full += 1;
	unlock(philo->meals_lock);
}

void	set_frks(t_philo *philo)
{
	if (&philo->frk < &philo->next->frk)
	{
		philo->frst_frk = &philo->frk;
		philo->scnd_frk = &philo->next->frk;
	}
	else
	{
		philo->frst_frk = &philo->next->frk;
		philo->scnd_frk = &philo->frk;
	}
}
