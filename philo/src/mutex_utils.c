/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:01:50 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/24 15:33:17 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock(pthread_mutex_t *lock)
{
	pthread_mutex_lock(lock);
}

void	unlock(pthread_mutex_t *lock)
{
	pthread_mutex_unlock(lock);
}

void	destroy(pthread_mutex_t *lock)
{
	pthread_mutex_destroy(lock);
}

void	lock_forks(t_philo *philo)
{
	if (philo->frks_taken == 2)
		return ;
	if (!philo->frks_taken)
	{
		lock(philo->frst_frk);
		philo->frks_taken = 1;
	}
	else if (philo->frks_taken == 1)
	{
		lock(philo->scnd_frk);
		philo->frks_taken = 2;
	}
}

void	unlock_forks(t_philo *philo)
{
	if (philo->frks_taken > 0)
		unlock(philo->frst_frk);
	if (philo->frks_taken > 1)
		unlock(philo->scnd_frk);
	philo->frks_taken = 0;
}
