/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:24:34 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/06 14:27:21 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_philo(t_philo *philo)
{
	if (!philo)
		return ;
	printf("philo [%d]\n", philo->index);
	printf("num_of_philos: %d\n", philo->num_of_philos);
	printf("time_to_die: %ld\n", philo->time_to_die);
	printf("time_to_eat: %ld\n", philo->time_to_eat);
	printf("time_to_sleep: %ld\n", philo->time_to_sleep);
	printf("meals_eaten: %ld\n", philo->meals_eaten);
	printf("meals_to_eat: %ld\n", philo->meals_to_eat);
	printf("start_time: %ld\n", philo->start_time);
	printf("last_meal: %ld\n", philo->last_meal);
	printf("frk: %p\n", philo->frk);
	printf("next: %p\n", philo->next);
	printf("prev: %p\n", philo->prev);
	printf("\n");
}

void	p_philos(t_philo *philo)
{
	t_philo	*tmp;
	t_philo	*frst;
	t_philo	*last;

	if (!philo)
		return ;
	frst = first_philo(philo);
	last = last_philo(philo);
	tmp = frst;
	while (tmp != last)
	{
		p_philo(tmp);
		tmp = tmp->next;
	}
}
