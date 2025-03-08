/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:54:04 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/08 11:56:11 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo *first_philo(t_philo *philo)
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

	if (!data)
		return ;
	philo->print_lock = &data->print_lock;
	philo->death_lock = &data->death_lock;
	philo->queue_lock = &data->queue_lock;
	philo->is_dead = &data->dead_flag;
	philo->q_buff = &data->q_buff;
	philo->q_turn = &data->q_turn;
	if (!data->philos)
	{
		printf("replacing philos in data\n");
		philo->next = philo;
		philo->prev = philo;
		data->philos = philo;
		return ;
	}
	printf("linking philo to data\n");
	frst = first_philo(data->philos);
	last = last_philo(data->philos);
	frst->prev = philo;
	last->next = philo;
	philo->next = frst;
	philo->prev = last;
}
