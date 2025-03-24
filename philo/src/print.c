/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:34:45 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/23 19:11:28 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_eat(t_philo *philo)
{
	long	time;

	if (should_die(philo))
		return ;
	lock(philo->print_lock);
	if (*philo->dead)
	{
		unlock(philo->print_lock);
		return ;
	}
	time = get_time();
	if (time != -1)
		printf("%ld\t%d\tis eating\n",
			time - *philo->start_time, philo->index);
	else
		write(2, "p_get_time error\n", 15);
	unlock(philo->print_lock);
	return ;
}

void	print_fork(t_philo *philo)
{
	long	time;

	if (should_die(philo))
		return ;
	lock(philo->print_lock);
	if (*philo->dead)
	{
		unlock(philo->print_lock);
		return ;
	}
	time = get_time();
	if (time != -1)
		printf("%ld\t%d\thas taken a fork\n",
			time - *philo->start_time, philo->index);
	else
		write(2, "p_get_time error\n", 15);
	unlock(philo->print_lock);
	return ;
}

void	print_sleep(t_philo *philo)
{
	long	time;

	if (should_die(philo))
		return ;
	lock(philo->print_lock);
	if (*philo->dead)
	{
		unlock(philo->print_lock);
		return ;
	}
	time = get_time();
	if (time != -1)
		printf("%ld\t%d\tis sleeping\n",
			time - *philo->start_time, philo->index);
	else
		write(2, "p_get_time error\n", 15);
	unlock(philo->print_lock);
	return ;
}

void	print_think(t_philo *philo)
{
	long	time;

	if (should_die(philo))
		return ;
	lock(philo->print_lock);
	if (*philo->dead)
	{
		unlock(philo->print_lock);
		return ;
	}
	time = get_time();
	if (time != -1)
		printf("%ld\t%d\tis thinking\n",
			time - *philo->start_time, philo->index);
	else
		write(2, "p_get_time error\n", 15);
	unlock(philo->print_lock);
	return ;
}

void	print_death(t_philo *philo)
{
	long	time;

	lock(philo->print_lock);
	time = get_time();
	if (time != -1)
		printf("%ld\t%d\tdied\n",
			time - *philo->start_time, philo->index);
	else
		write(2, "p_get_time error\n", 15);
	ft_usleep(100);
	unlock(philo->print_lock);
	return ;
}
