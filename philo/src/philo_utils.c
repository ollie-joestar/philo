/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:54:04 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/06 14:58:24 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo *first_philo(t_philo *philo)
{
	int	min;

	if (!philo)
		return (NULL);
	min = philo->index;
	while (philo->index < min)
	{
		min = philo->index;
		if (!philo->next)
			return (philo);
		philo = philo->next;
	}
	return (philo);
}

t_philo	*last_philo(t_philo *philo)
{
	int	max;

	if (!philo)
		return (NULL);
	max = philo->index;
	while (philo->index > max)
	{
		max = philo->index;
		if (!philo->next)
			return (philo);
		philo = philo->next;
	}
	return (philo);
}

void	link_to_data(t_data *data, t_philo *philo)
{
	t_philo	*frst;
	t_philo	*last;

	if (!data->philos)
	{
		data->philos = philo;
		data->philos->next = philo;
		data->philos->prev = philo;
		return ;
	}
	frst = first_philo(data->philos);
	last = last_philo(data->philos);
	frst->prev = philo;
	last->next = philo;
	philo->next = frst;
	philo->prev = last;
}
