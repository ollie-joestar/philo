/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 00:37:20 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/23 18:47:27 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	alive_and_hungry(t_philo *philo)
{
	if (should_die(philo))
		return (0);
	lock (philo->print_lock);
	if (*philo->dead)
	{
		unlock(philo->print_lock);
		return (0);
	}
	unlock(philo->print_lock);
	if (!hungry(philo))
		return (0);
	return (1);
}

int	hungry(t_philo *philo)
{
	if (philo->meals_to_eat == 0)
		return (1);
	if (philo->meals_eaten >= philo->meals_to_eat)
		return (0);
	return (1);
}

int	full(t_philo *philo)
{
	if (philo->meals_to_eat == 0)
		return (0);
	lock(philo->meals_lock);
	if (*philo->full >= philo->num_of_philos)
	{
		unlock(philo->meals_lock);
		return (1);
	}
	unlock(philo->meals_lock);
	return (0);
}

int	should_die(t_philo *philo)
{
	long	time;

	if (philo->last_meal == 0 || philo->time_to_die == 0)
		return (0);
	time = get_time();
	if (time == -1)
		return (write(2, "get_time error\n", 15));
	if (time - philo->last_meal > philo->time_to_die)
		return (die(philo), 1);
	return (0);
}

int	dead(t_philo *philo)
{
	lock(philo->print_lock);
	if (*philo->dead)
	{
		unlock(philo->print_lock);
		return (1);
	}
	unlock(philo->print_lock);
	return (0);
}
