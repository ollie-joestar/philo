/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overseer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:20:40 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/24 11:09:32 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	overseer_process(t_overseer *overseer)
{
	t_philo	*philo;

	philo = first_philo(overseer->philos);
	while (1)
	{
		lock(overseer->print_lock);
		if (*overseer->dead)
		{
			unlock(overseer->print_lock);
			break ;
		}
		unlock(overseer->print_lock);
		philo = philo->next;
		if (full(overseer->philos))
			break ;
		ft_usleep(3);
	}
}

int	overseer(void *ptr)
{
	t_philo		*philo;
	t_overseer	*overseer;
	int			i;

	overseer = (t_overseer *)ptr;
	philo = first_philo(overseer->philos);
	i = 0;
	overseer_process(overseer);
	while (i < overseer->num_of_philos)
	{
		if (pthread_join(philo->thread, NULL))
			return (1);
		i++;
		philo = philo->next;
	}
	return (0);
}
