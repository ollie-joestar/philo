/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:00:29 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/23 18:58:32 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	die(t_philo *philo)
{
	lock (philo->print_lock);
	if (*philo->dead)
	{
		unlock(philo->print_lock);
		return ;
	}
	*philo->dead = 1;
	unlock(philo->print_lock);
	print_death(philo);
}

void	think(t_philo *philo)
{
	if (*philo->dead)
		return ;
	print_think(philo);
	p_usleep(philo, philo->time_to_think);
}

void	nap(t_philo *philo)
{
	if (*philo->dead)
	{
		return ;
	}
	print_sleep(philo);
	p_usleep(philo, philo->time_to_sleep);
}

static int	update_last_meal_time(t_philo *philo)
{
	long	time;

	time = p_get_time(philo);
	if (-1 == time)
		return (write(2, "get_time error\n", 15));
	philo->last_meal = time;
	return (0);
}

void	eat(t_philo *philo)
{
	lock_forks(philo);
	print_fork(philo);
	if (philo->num_of_philos == 1)
	{
		p_usleep(philo, philo->time_to_die + 10);
		return ;
	}
	lock_forks(philo);
	print_fork(philo);
	if (update_last_meal_time(philo))
		return ;
	print_eat(philo);
	p_usleep(philo, philo->time_to_eat);
	unlock_forks(philo);
	update_meals(philo);
}
