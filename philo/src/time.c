/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:01:15 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/23 18:59:57 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	p_get_time(t_philo *philo)
{
	long	time;

	lock(philo->clock_lock);
	time = get_time();
	unlock(philo->clock_lock);
	return (time);
}

long	get_time(void)
{
	struct timeval	time;
	long			t;
	int				check;

	check = gettimeofday(&time, NULL);
	if (-1 == check)
		return (-1);
	t = time.tv_sec * 1000 + time.tv_usec / 1000;
	if (t < 0)
		return (-1);
	return (t);
}
