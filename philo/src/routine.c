/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:55:00 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/23 18:59:05 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	question_existence(t_philo *philo)
{
	while (alive_and_hungry(philo))
	{
		if (!full(philo) && !dead(philo))
			eat(philo);
		if (!full(philo) && !dead(philo))
			nap(philo);
		if (!full(philo) && !dead(philo))
			think(philo);
		if (dead(philo) || full(philo))
			break ;
	}
}

void	initial_thought(t_philo *philo)
{
	unsigned long	tte;

	if (philo->num_of_philos == 1)
		return ;
	tte = (unsigned long)philo->time_to_eat;
	if (!(philo->num_of_philos % 2))
	{
		if (!(philo->index % 2))
			(print_think(philo), p_usleep(philo, tte + 1));
	}
	else if ((philo->num_of_philos % 2))
	{
		if (!(philo->index % 2))
			(print_think(philo), p_usleep(philo, tte + 1));
		else if (philo->index == philo->num_of_philos)
		{
			print_think(philo);
			p_usleep(philo, tte + tte + 1);
		}
	}
}

void	calculate_thinking_time(t_philo *philo)
{
	unsigned long	ttt;
	unsigned long	tte;
	unsigned long	tts;

	if (philo->num_of_philos == 1)
		return ;
	tte = philo->time_to_eat;
	tts = philo->time_to_sleep;
	ttt = 0;
	if (philo->num_of_philos % 2)
		ttt = (tte + tte - tts) * ((tte + tte) > tts);
	else
		ttt = (tte - tts) * (tte > tts);
	philo->time_to_think = (ttt != 0) + ttt;
}

int	organised(t_philo *philo)
{
	pthread_mutex_lock(philo->print_lock);
	if (!*philo->start)
	{
		pthread_mutex_unlock(philo->print_lock);
		return (0);
	}
	pthread_mutex_unlock(philo->print_lock);
	return (1);
}

void	*philo_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (!organised(philo) && !dead(philo))
		ft_usleep(1);
	if (dead(philo))
		return (NULL);
	philo->last_meal = *philo->start_time;
	set_frks(philo);
	initial_thought(philo);
	calculate_thinking_time(philo);
	question_existence(philo);
	unlock_forks(philo);
	return (NULL);
}
