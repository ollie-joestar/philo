/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:24:34 by oohnivch          #+#    #+#             */
/*   Updated: 2025/03/23 19:11:56 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_philo(t_philo *philo)
{
	if (!philo)
		return ;
	printf("philo [%d]\n", philo->index);
	printf("adress: %p\n", philo);
	printf("num_of_philos: %d\n", philo->num_of_philos);
	printf("time_to_die: %ld\n", philo->time_to_die);
	printf("time_to_eat: %ld\n", philo->time_to_eat);
	printf("time_to_sleep: %ld\n", philo->time_to_sleep);
	printf("meals_eaten: %ld\n", philo->meals_eaten);
	printf("meals_to_eat: %ld\n", philo->meals_to_eat);
	printf("start_time: %ld\n", *philo->start_time);
	printf("last_meal: %ld\n", philo->last_meal);
	printf("frk: %p\n", &philo->frk);
	if (philo->next)
		printf("next: %p id: %d\n", philo->next, philo->next->index);
	else
		printf("next: %p\n", philo->next);
	if (philo->prev)
		printf("prev: %p id: %d\n", philo->prev, philo->prev->index);
	else
		printf("prev: %p\n", philo->prev);
	printf("\n");
}

void	p_philos(t_data *data)
{
	int		i;
	t_philo	*philo;

	printf("printing philos\n");
	if (!data || !data->philos)
	{
		printf("no philos in data\n");
		return ;
	}
	philo = first_philo(data->philos);
	i = data->num_of_philos;
	while (i--)
	{
		p_philo(philo);
		philo = philo->next;
	}
}

void	e_lock(pthread_mutex_t *lock, t_philo *philo, char *s)
{
	pthread_mutex_lock(philo->print_lock);
	printf("\t\t\tstart lock %s\n", s);
	pthread_mutex_unlock(philo->print_lock);
	pthread_mutex_lock(lock);
	if (dead(philo))
	{
		pthread_mutex_unlock(lock);
		pthread_mutex_lock(philo->print_lock);
		printf("\t\t\tdead philo lock %s\n", s);
		pthread_mutex_unlock(philo->print_lock);
	}
	pthread_mutex_lock(philo->print_lock);
	printf("\t\t\tend lock %s\n", s);
	pthread_mutex_unlock(philo->print_lock);
}

void	e_unlock(pthread_mutex_t *lock, t_philo *philo, char *s)
{
	pthread_mutex_lock(philo->print_lock);
	printf("\t\t\tstart unlock %s\n", s);
	pthread_mutex_unlock(philo->print_lock);
	pthread_mutex_unlock(lock);
	pthread_mutex_lock(philo->print_lock);
	printf("\t\t\tend unlock %s\n", s);
	pthread_mutex_unlock(philo->print_lock);
}
