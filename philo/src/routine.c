/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:57:02 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/08 15:35:55 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start(t_data *data)
{
	t_philo	*philo;
	int		i;

	philo = first_philo(data->philos);
	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_create(&philo->thread, NULL, philo_routine, philo))
			return (1);
		philo = philo->next;
		i++;
	}
	return (0);
}

void	p_think(t_philo *philo)
{	
	long	time;

	time = get_time();
	printf("%ld %d is thinking\n", time - philo->start_time, philo->index);
	ft_usleep(100);
	return ;
}

void	update_q(t_philo *philo)
{
	pthread_mutex_lock(philo->queue_lock);
	*philo->q_buff += 1;
	if (*philo->q_buff == philo->num_of_philos / 2)
	{
		*philo->q_buff = 0;
		if (*philo->q_turn == philo->num_of_philos)
			*philo->q_turn = 1;
		else
			*philo->q_turn += 1;
	}
	pthread_mutex_unlock(philo->queue_lock);
}

void	p_eat(t_philo *philo)
{
	long	time;

	/*time = time - philo->start_time;*/
	pthread_mutex_lock(philo->frk);
	time = get_time();
	printf("%ld %d has taken a fork\n", time - philo->start_time, philo->index);
	pthread_mutex_lock(philo->prev->frk);
	time = get_time();
	printf("%ld %d has taken a fork\n", time - philo->start_time, philo->index);
	philo->last_meal = time;
	philo->meals_eaten++;
	update_q(philo);
	printf("%ld %d is eating\n", time - philo->start_time, philo->index);
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->frk);
	pthread_mutex_unlock(philo->prev->frk);
	return ;
}

void	p_sleep(t_philo *philo)
{
	long	time;

	time = get_time();
	printf("%ld %d is sleeping\n", time - philo->start_time, philo->index);
	ft_usleep(philo->time_to_sleep);
	return ;
}

int	alive_and_hungry(t_philo *philo)
{
	long	time;

	time = get_time();
	if (time - philo->last_meal > philo->time_to_die)
	{
		printf("%ld %d died\n", time - philo->start_time, philo->index);
		return (0);
	}
	if (philo->meals_to_eat != 0 && philo->meals_eaten >= philo->meals_to_eat)
		return (0);
	return (1);
}

int	your_turn(t_philo *philo)
{
	int	i;
	int	limit;
	int	real_index;

	pthread_mutex_lock(philo->queue_lock);
	i = 0;
	limit = philo->num_of_philos / 2;
	if (philo->num_of_philos ==  1)
		return (1);
	while (limit)
	{
		real_index = *philo->q_turn + i;
		if (real_index > philo->num_of_philos)
			real_index %= philo->num_of_philos;
		if (real_index == philo->index)
		{
			pthread_mutex_unlock(philo->queue_lock);
			return (1);
		}
		i += 2;
		limit--;
	}
	pthread_mutex_unlock(philo->queue_lock);
	return (0);
}

void	*philo_routine(void *ptr)
{
	t_philo	*philo;

	//init routine
	philo = (t_philo *)ptr;
	philo->start_time = get_time();
	if (philo->start_time == -1)
		return (write(2, "get_time error\n", 14), NULL);
	philo->last_meal = philo->start_time;
	//routine itself
	if (philo->index & 1 && philo->index == last_philo(philo)->index)
	{
		ft_usleep(20);
	}
	while (alive_and_hungry(philo))
	{
		if (your_turn(philo))
			p_eat(philo);
		p_sleep(philo);
	}
	p_think(philo);
	p_think(philo);
	return (NULL);
}
